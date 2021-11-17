#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <mutex>

using namespace std;

/* 有读有写

std::lock_guard的std:: adopt_lock参数
std::adopt_lock是个结构体对象，起一个标记作用:作用就是表示这个互斥量已经lock()，
不需要在std::lock_guard<std::mutex>构造函数里再面对mutex对象进行lock()了
总结: std::lock(): 一次锁定多个互斥量: 谨慎博用（建议一个一个锁）

*/
class Test {
public:
    //把收到的消息, 存放到一个队列的线程
    void inMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {
            put(i);
        }
    }
    void put(int i) {
        mux.lock();
        lock_guard<mutex> g1(mux, adopt_lock);  //adopt_lock表示在lock_guard的构造函数中不执行mux1.lock
        msgRecvQueue.push_back(i);
        cout << "生成数据！";

        //超过作用域, lock_guard会自动释放锁
    }



    //把数据从消息队列取出的线程
    void outMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {
            get();
        }
    }
    void get() {
        mux.lock();
        lock_guard<mutex> g1(mux, adopt_lock);  //adopt_lock表示在lock_guard的构造函数中不执行mux1.lock
        if (msgRecvQueue.empty() == false) {
            int command = msgRecvQueue.front();
            msgRecvQueue.pop_front();
            cout << "处理数据！";
        }
        else {
            cout << "msgRecvQueue为空！";
        }

        //超过作用域, lock_guard会自动释放锁
    }

private:
    list<int> msgRecvQueue;
    mutex mux;      //互斥量
};
void test3()
{
    Test t;

    thread thdOut(&Test::outMsgRecvQueue, ref(t));
    thread thdIn(&Test::inMsgRecvQueue, ref(t));

    thdOut.join();
    thdIn.join();
}

int main()
{
    test3();
}
