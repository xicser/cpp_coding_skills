#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <mutex>

using namespace std;

/*

防死锁:
std::lock()函数模板:
能力: 一次锁住两个或者两个以上的互斥量（至少两个，多了不限，1个不行）;

它不存在这种因为再多个线程中因为锁的顺序问题导致死锁的风险问题;
std::lock(): 如果互斥量中有一个没锁柱，它就在那里等着，等所有互斥量都锁住，它才能往下走（返回);

要么两个互斥量都锁住，要么两个互斥量都没锁住。如果只锁了一个，另外一个没锁成功，则它立即把已经锁住的解锁。

*/

/* 有读有写 */
class Test {
public:
    //把收到的消息, 存放到一个队列的线程
    void inMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {

            lock(mux1, mux2);
            msgRecvQueue.push_back(i);
            mux1.unlock();
            mux2.unlock();

            cout << "生成数据！";
        }
    }

    //把数据从消息队列取出的线程
    void outMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {

            lock(mux1, mux2);
            if (msgRecvQueue.empty() == false) {

                int command = msgRecvQueue.front();
                msgRecvQueue.pop_front();
                mux1.unlock();
                mux2.unlock();

                cout << "处理数据！";
            }
            else {
                cout << "msgRecvQueue为空！";
                mux1.unlock();
                mux2.unlock();
            }
        }
    }

private:
    list<int> msgRecvQueue;
    mutex mux1;      //互斥量1
    mutex mux2;      //互斥量2
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
