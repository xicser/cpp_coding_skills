#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <mutex>

using namespace std;

/* 有读有写
1, defer_lock
用这个defer_lock的前提是你不能自己先lock，否则会报异常。
defer_lock的意思就是并没有给mutext加锁: 初始化了一个没有加锁的mutex
需要用unique_lock的成员函数lock来加锁




2, unique_lock的成员函数:
(3.1) lock(), 加锁;
(3.2) unlock(),解锁;
(3.3) try_lock(), 尝试给互斥量加锁，如果拿不到锁，则返回false, 如果拿到了锁，返回true，这个函数不阻塞的;
(3.4) release(), 返回它所管理的mutex对象指针，并释放所有权; 也就是说，这个unique_lock和mutext不再有关系。
严格区分unlock()和release()的区别, 不要混淆。如果原来mutex对象处于加锁状态, 你有责任接管过来并负责解锁。




3, unique_lock所有权的传递:
std::unique_lock<std ::mutex> sbguard1(my_mutex1);
sbguard1拥有my_mutex1的所有权
sbguard1可以把自己对mutex(my_mutex1)的所有权转移给其他的unique_lock对象;
所以，unique_lock对象这个mutex的所有权是属于可以转移，但是不能复制（和unique_ptr很像）

转移:
std::unique_lock<std ::mutex> sbguard2(move(sbguard1)); //现在sbguard1指向空，sbguard2指向了mutex

*/

class Test {
public:
    //把收到的消息, 存放到一个队列的线程
    void inMsgRecvQueue() {
        for (int i = 0; i < 1000; i++) {
            inRecvProc(i);
        }
    }
    void inRecvProc(int i) {
        unique_lock<mutex> g1(mux, defer_lock);  //没有加锁的mutex, 相当于把mutex和unique_lock绑定(关联)在一起
        g1.lock();    //不用自己unlock, 出了作用域, 析构的时候会自动unlock

        msgRecvQueue.push_back(i);

        g1.unlock();  //不过也可以自己unlock, 因为在不操作共享数据的时候, 可以提前释放锁, 提高灵活性, 提高并发度


        //g1.lock();  //还可以继续lock

        //// ... ...

        //g1.unlock();


        //尝试拿锁
        if (g1.try_lock() == true) {
            cout << "生成数据(1)！";
            msgRecvQueue.push_back(i);
        }
        else {
            cout << "干点别的事！";
            return;
        }

        cout << "生成数据(2)！";
    }


    //把数据从消息队列取出的线程
    void outMsgRecvQueue() {
        for (int i = 0; i < 1000; i++) {
            outRecvProc();
        }
    }
    void outRecvProc(void) {
        mux.lock();
        unique_lock<mutex> g1(mux, adopt_lock);
        if (msgRecvQueue.empty() == false) {

            int command = msgRecvQueue.front();
            msgRecvQueue.pop_front();

            cout << "处理数据！";
        }
        else {
            cout << "msgRecvQueue为空！";
        }
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
