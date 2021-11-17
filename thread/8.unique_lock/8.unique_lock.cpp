#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <mutex>

using namespace std;

/* 有读有写

std::lock_guard<std::mutex> sbguard1 (my_mutexl, std::adopt_lock); //adopt_lock标记作用;
(2.1) std::adopt_lock:
表示这个互斥量已经被lock了（你必须要把互斥量提前lock了,否则会报异常）
std::adopt_lock: 标记的效果就是, 假设调用方线程已经拥有了互斥的所有权（已经lock()成功了）;
通知lock_guard不需要在构造函数中lock这个互斥量了;
unique_lock也可以带std::adopt_lock标记，含义相同, 就是不希望再unique_lock()的构造函数中lock这个mutex

(2.2) std::try_to_lock:
我们会尝试用mutex的lock()去锁定这个mutex，但如果没有锁定成功，我也会立即返回，并不会阻塞在那里;
用这个try_to_lock的前提是你自己不能先去lock。





*/
class Test {
public:
    //把收到的消息, 存放到一个队列的线程
    void inMsgRecvQueue() {
        for (int i = 0; i < 1000; i++) {
            put(i);
        }
    }
    void put(int i) {
        unique_lock<mutex> g1(mux, std::try_to_lock);
        //如果拿到锁了
        if (g1.owns_lock() == true) {
            msgRecvQueue.push_back(i);
            cout << "生成数据！";
        }
        else {
            cout << "只能干点别的事";
        }
    }



    //把数据从消息队列取出的线程
    void outMsgRecvQueue() {
        for (int i = 0; i < 1000; i++) {
            get();
        }
    }
    void get() {
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
