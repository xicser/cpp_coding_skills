#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <mutex>

using namespace std;

//recursive_mutex, 当一个线程拿到锁后，仍可以继续lock多次，更像window的临界区，可以多次Enter

/* 有读有写 */
class Test {
public:
    //把收到的消息, 存放到一个队列的线程
    void inMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {
            {
                lock_guard<recursive_mutex> sbguard(recursive_mux);
                msgRecvQueue.push_back(i);
            }
        }
    }

    //把数据从消息队列取出的线程
    void outMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {
            outMsgLULProc();
        }
    }

    void outMsgLULProc() {

        //lock_guard构造函数执行了mux::lock
        //当sbguard被释放时, 调用其析构函数, 相当于执行mux::unlock
        lock_guard<recursive_mutex> sbguard(recursive_mux);
        if (msgRecvQueue.empty() == false) {

            int command = msgRecvQueue.front();
            msgRecvQueue.pop_front();

            cout << "处理数据！";
        }
        else {
            cout << "msgRecvQueue为空 ";
        }
    }

private:
    list<int> msgRecvQueue;
    recursive_mutex recursive_mux;
};
void test2()
{
    Test t;

    thread thdOut(&Test::outMsgRecvQueue, ref(t));
    thread thdIn(&Test::inMsgRecvQueue, ref(t));

    thdOut.join();
    thdIn.join();
}
