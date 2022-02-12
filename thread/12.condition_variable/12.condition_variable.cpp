#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <mutex>

using namespace std;

class Test {
public:
    //存放消息
    void sendMsgToQueue() {
        for (int i = 0; i < 1000; i++) {
            unique_lock<mutex> ulock(mux);
            cout << "生成一个数据！ " << i << " ";
            msgQueue.push_back(i);
            condition.notify_one(); //尝试唤醒condition.wait()的线程(有可能现在没有线程在wait, 那么这句就没有效果)
                                    //在unlock前通知, 确保通知的时候, 消息队列中一定有数据

            //尝试唤醒condition.wait()的所有线程(有可能现在没有线程在wait, 那么这句就没有效果)
            //condition.notify_all();
            ulock.unlock();
        }
    }

    //获取消息
    void getMsgFromQueue() {

        static int consumeCnt = 0;
        while (true) {

            /*
                condition.wait()用来等某个东西
                如果第二个参数lambda表达式返回值是true，那wait()直接返回;
                如果第二个参数lambda表达式返回值是false，那么wait()将解锁互斥量，并堵塞到本行,
                那堵塞到什么时候为止呢? 堵塞到其他某个线程调用notify_one()成员函数为止;
                如果wait()没有第二个参数: condition.wait(sbguard1); 那么就跟第二个参数lambda表达式返回false效果一样
                wait()将解锁互斥量，并堵塞到本行，堵塞到其他某个线程调用notify_one()成员函数为止;

                当其他线程用notify_one()将本wait(原来是睡着/堵塞)的状态唤醒后，wait就开始恢复干活了，恢复后wait干什么活?
                a) wait()不断的尝试重新获取互斥量锁，如果获取不到，那么流程就卡在wait这里等着获取，如果获取到了锁，那么wait就继续执行b
                b) 
                    b.1) 如果wait有第二个参数(lambda)，就判断这个lambda表达式，如果lambda表达式为false, 那么wait()将解锁互斥量，并堵塞到本行
                    b.2) 如果lambda表达式为true，则wait返回，代码流程继续往下走
                    b.3) 如果wait没有第二个参数，则wait返回，代码流程继续往下走
            */

            unique_lock<mutex> ulock(mux);   //加锁
            condition.wait(ulock, [this] {
                //处理一下虚假唤醒
                if (msgQueue.empty() == false) {
                    return true;   //消息队列中有数据
                }
                else {
                    return false;  //消息队列中没有数据（虚假唤醒）
                }
            });

            int data = msgQueue.front();
            msgQueue.pop_front();
            ulock.unlock();

            cout << "消费一个数据！ " << data << " ";
            consumeCnt++;

            if (consumeCnt == 1000) {
                cout << endl << "消费完毕！" << endl;
                break;
            }
        }
    }

private:
    list<int> msgQueue;             // 消息队列
    mutex mux;                      // 互斥量
    condition_variable condition;   // 条件变量
};
void test3()
{
    Test t;

    thread thdOut(&Test::sendMsgToQueue, ref(t));
    thread thdIn(&Test::getMsgFromQueue, ref(t));

    thdOut.join();
    thdIn.join();
}

int main()
{
    test3();
}
