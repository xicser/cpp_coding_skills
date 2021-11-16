#include <iostream>
#include <thread>
#include <vector>
#include <list>

using namespace std;

/* 创建多个线程 */
void myprint1(int num)
{
    cout << "myprint1 : " << num << endl;
}
void test1()
{
    vector<thread> threads;

    for (int i = 0; i < 10; i++) {
        threads.push_back(thread(myprint1, i));   //一创建就开始执行
    }

    //等待所有子线程执行完毕
    for (auto iter = threads.begin(); iter != threads.end(); iter++) {
        iter->join();
    }

    cout << "I Love China !" << endl;
}
















/* 只读数据共享问题, 如果所有的线程都是读，那么不用加锁 */
vector<int> gData = {9, 8, 7};
void myprint2(int num)
{
    cout << "myprint2" << this_thread::get_id() << " 打印 " << gData[0] << gData[1] << gData[2] << endl;
}
void test2()
{
    vector<thread> threads;

    for (int i = 0; i < 10; i++) {
        threads.push_back(thread(myprint2, i));   //一创建就开始执行
    }

    //等待所有子线程执行完毕
    for (auto iter = threads.begin(); iter != threads.end(); iter++) {
        iter->join();
    }

    cout << "I Love China !" << endl;
}














/* 有读有写 */
class Test {
public:
    //把收到的消息, 存放到一个队列的线程
    void inMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {
            /*cout <<  << endl;*/
            msgRecvQueue.push_back(i);
        }
    }

    //把数据从消息队列取出的线程
    void outMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {
            
            if (msgRecvQueue.empty() == false) {
                
                int command = msgRecvQueue.front();
                msgRecvQueue.pop_front();
            }
            else {
                cout << "msgRecvQueue为空" << endl;
            }
        }
    }

private:
    list<int> msgRecvQueue;
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
    // test1();
     test2();

    //test3();


}
