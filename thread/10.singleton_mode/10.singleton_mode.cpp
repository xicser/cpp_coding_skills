#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

static mutex mutexInstance;

/* 单例类 */
class Configuration {
public:
    ~Configuration() {
        cout << "析构" << endl;
    }

private:
    Configuration() {
        cout << "构造" << endl;
    }

    static Configuration* instance;

public:
    //懒汉式
    static Configuration* getInstance() {

        //naive的做法
        //unique_lock<mutex> uMutex(mutexInstance);  //自动加锁
        //if (instance == nullptr) {
        //    instance = new Configuration();
        //}

        // 双重锁定(双重检查), 提高性能, 不用每次都lock
        // 如果没有mutex
        // a)如果if (instance != nullptr)条件成立, 则肯定表示instance已经被new过了; 
        // b)如果if (instance == nullptr), 不代表instance一定没被new过;
        if (instance == nullptr) {
            unique_lock<mutex> uMutex(mutexInstance);  //自动加锁
            if (instance == nullptr) {
                instance = new Configuration();
            }
        }

        return instance;
    }
    static Configuration* getInstancePtr() {
        return instance;
    }
    static void clearInstancePtr() {
        instance = nullptr;
    }
};
Configuration* Configuration::instance = nullptr;


/* 资源回收类 */
class Recycle {
public:
    ~Recycle() {
        Configuration* instancePtr = Configuration::getInstancePtr();
        if (instancePtr != nullptr) {
            delete instancePtr;
        }
    }
};

// 用于释放new出来的内存
// 全局变量, 生命周期是整个程序, 当程序执行结束时, 会被释放, 这时会调用析构函数, 然后在析构函数里释放Configuration类实例
static Recycle recycle;



/* 线程入口函数 */
void threadInter()
{
    cout << "threadInter开始" << endl;
    Configuration* pConfig = Configuration::getInstance();
    cout << "threadInter结束" << endl;
}

int main()
{
    // 面临的问题：需要再我们自己创建的线程（而不是主线程）中来创建Configuration这个单例类的对象，这种线程可能不止1个(最少2个)
    // 我们可能会面临getInstance()这种成员函数要互斥

    thread threadA(threadInter);
    thread threadB(threadInter);

    threadA.join();
    threadB.join();
}
