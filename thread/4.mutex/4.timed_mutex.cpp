#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <mutex>


using namespace std;

/*

带超时的互斥量std::timed_mutex和std::recursive_timed_mutex / std::timed_mutex: 是带超时功能的独占互斥量;
try_lock_for():参数是一段时间，是等待一段时间。如果我拿到了锁，或者等待超过时间没拿到锁，就走下来
try_lock_until():参数是一个未来的时间点，在这个未来的时间没到的时间内，如果拿到了锁，那么就走下来
如果时间到了, 没拿到锁,程序流程也走下来
std::recursive_timed_mutex: 带超时功能的递归独占互斥量

*/



/* 有读有写 */
class Test {
public:
    //把收到的消息, 存放到一个队列的线程
    void inMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {

            std::chrono::milliseconds timeout(100);  //100ms
            if (timed_mux.try_lock_for(timeout) == true) { //尝试拿锁100ms, 看这个锁100ms内是否可以拿到
            //if (timed_mux.try_lock_until(chrono::steady_clock::now() + timeout)
                msgRecvQueue.push_back(i);
                timed_mux.unlock();
            }
            //100ms还没拿到
            else {
                std::chrono::milliseconds timeout(100);
                std::this_thread::sleep_for(timeout);
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

        std::chrono::milliseconds timeout(100);  //100ms
        if (timed_mux.try_lock_for(timeout) == true) { //尝试拿锁100ms, 看这个锁100ms内是否可以拿到
        
            if (msgRecvQueue.empty() == false) {

                int command = msgRecvQueue.front();
                msgRecvQueue.pop_front();

                cout << "处理数据！";
            }
            else {
                cout << "msgRecvQueue为空 ";
            }      

            timed_mux.unlock();
        }
        else {
            std::chrono::milliseconds timeout(100);
            std::this_thread::sleep_for(timeout);
        }
    }

private:
    list<int> msgRecvQueue;
    timed_mutex timed_mux;    //带有超时功能的mutex
};
void test3()
{
    Test t;

    thread thdOut(&Test::outMsgRecvQueue, ref(t));
    thread thdIn(&Test::inMsgRecvQueue, ref(t));

    thdOut.join();
    thdIn.join();
}

