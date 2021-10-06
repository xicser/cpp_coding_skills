#include <iostream>
#include <thread>
#include <mutex>
#include <list>
#include <windows.h>

using namespace std;


#define __WINDOWSSJQ__


/* 有读有写 */
class Test {
public:
    Test() {
#ifdef __WINDOWSSJQ__
        InitializeCriticalSection(&winCritical);
#endif
    }

    //把收到的消息, 存放到一个队列的线程
    void inMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {

#ifdef __WINDOWSSJQ__
            EnterCriticalSection(&winCritical);
#else
            mux.lock();
#endif

            msgRecvQueue.push_back(i);

#ifdef __WINDOWSSJQ__
            LeaveCriticalSection(&winCritical);
#else
            mux.unlock();
#endif
        }
    }

    //把数据从消息队列取出的线程
    void outMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {

#ifdef __WINDOWSSJQ__
            EnterCriticalSection(&winCritical);
#else
            mux.lock();
#endif

            if (msgRecvQueue.empty() == false) {

                int command = msgRecvQueue.front();
                msgRecvQueue.pop_front();

#ifdef __WINDOWSSJQ__
                LeaveCriticalSection(&winCritical);
#else
                mux.unlock();
#endif

                cout << "处理数据！";
            }
            else {
                cout << "msgRecvQueue为空";


#ifdef __WINDOWSSJQ__
                LeaveCriticalSection(&winCritical);
#else
                mux.unlock();
#endif
            }
        }
    }

private:
    list<int> msgRecvQueue;

#ifdef __WINDOWSSJQ__
    CRITICAL_SECTION winCritical;
#else
    mutex mux;      //互斥量
#endif
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
