#include <iostream>
#include <thread>
#include <list>
#include <windows.h>

using namespace std;

#define __WINDOWSSJQ__

//windows版本的lock_guard
class CWinlock { //RAII类(Resource Acquisition is initialization)，资源获取即初始化
public:
    CWinlock(CRITICAL_SECTION* pCritical) {
        m_pCritical = pCritical;
        EnterCriticalSection(m_pCritical);
    }

    ~CWinlock() {
        LeaveCriticalSection(m_pCritical);
    }

private:
    CRITICAL_SECTION* m_pCritical;
};


/* 有读有写 */
class Test {
public:
    Test() {
        InitializeCriticalSection(&winCritical);
    }

    //把收到的消息, 存放到一个队列的线程
    void inMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {
            {
                CWinlock winlock(&winCritical);
                msgRecvQueue.push_back(i);
            }
        }
    }

    //把数据从消息队列取出的线程
    void outMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {
            {
                CWinlock winlock(&winCritical);
                if (msgRecvQueue.empty() == false) {

                    int command = msgRecvQueue.front();
                    msgRecvQueue.pop_front();
                    cout << "处理数据！";
                }
                else {
                    cout << "msgRecvQueue为空";
                }
            }
        }
    }

private:
    list<int> msgRecvQueue;
    CRITICAL_SECTION winCritical;
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
