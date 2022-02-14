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
            /*cout <<  << endl;*/
            mux.lock();
            msgRecvQueue.push_back(i);
            mux.unlock();
        }
    }

    //把数据从消息队列取出的线程
    void outMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {

            mux.lock();
            if (msgRecvQueue.empty() == false) {

                int command = msgRecvQueue.front();
                msgRecvQueue.pop_front();
                mux.unlock();

                cout << "处理数据！";
            }
            else {
                cout << "msgRecvQueue为空";
                mux.unlock();
            }
        }
    }

private:
    list<int> msgRecvQueue;
    mutex mux;      //互斥量
};
void test1()
{
    Test t;

    thread thdOut(&Test::outMsgRecvQueue, ref(t));
    thread thdIn(&Test::inMsgRecvQueue, ref(t));

    thdOut.join();
    thdIn.join();
}

int main()
{
    test1();
}
