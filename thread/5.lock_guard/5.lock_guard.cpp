#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <mutex>

using namespace std;

/* 有读有写 */
class Test {
public:
    //把收到的消息, 存放到一个队列的线程
    void inMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {
            {
                lock_guard<mutex> sbguard(mux);
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
        
        lock_guard<mutex> sbguard(mux);          //lock_guard构造函数执行了mux::lock
                                                 //当sbguard被释放时, 调用其析构函数, 相当于执行mux::unlock
        if (msgRecvQueue.empty() == false) {

            int command = msgRecvQueue.front();
            msgRecvQueue.pop_front();

            cout << "处理数据！";
        }
        else {
            cout << "msgRecvQueue为空";
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
