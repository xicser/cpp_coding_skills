#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <mutex>

using namespace std;

/* 有读有写

std::lock_guard的std:: adopt_lock参数
std::adopt_lock是个结构体对象，起一个标记作用:作用就是表示这个互斥量已经lock()，
不需要在std::lock_guardKstd::mutex>构造函数里再面对mutex对象进行lock()了
总结: std::lock(): 一次锁定多个互斥量: 谨慎博用（建议一个一个锁）

*/
class Test {
public:
    //把收到的消息, 存放到一个队列的线程
    void inMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {

            lock(mux1, mux2);
            lock_guard<mutex> g1(mux1, adopt_lock);  //adopt_lock表示在lock_guard的构造函数中不执行mux1.lock
            lock_guard<mutex> g2(mux2, adopt_lock);

            msgRecvQueue.push_back(i);
            //mux1.unlock();                         //使用lock_guard后, 就不用手动unlock了
            //mux2.unlock();

            cout << "生成数据！";
        }
    }

    //把数据从消息队列取出的线程
    void outMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {

            lock(mux1, mux2);

            lock_guard<mutex> g1(mux1, adopt_lock);  //adopt_lock表示在lock_guard的构造函数中不执行mux1.lock
            lock_guard<mutex> g2(mux2, adopt_lock);

            if (msgRecvQueue.empty() == false) {

                int command = msgRecvQueue.front();
                msgRecvQueue.pop_front();
                //mux1.unlock();
                //mux2.unlock();

                cout << "处理数据！";
            }
            else {
                cout << "msgRecvQueue为空！";
                //mux1.unlock();
                //mux2.unlock();
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
