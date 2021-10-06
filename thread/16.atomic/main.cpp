#include <iostream>
#include <thread>
#include <atomic>

using namespace std;


//int cnt = 0;
std::atomic<int> cnt(0);  //封装一个原子变量

/*
atomic支持的操作:
++ -- +=, &= |= ^=
其他的可能不支持
*/

void thread1()
{
    for (int i = 0; i < 10000000; i++) {
        cnt++;  //要么加了, 要么没加, 不会出现半拉子状态
    }
}

void thread2()
{
    for (int i = 0; i < 10000000; i++) {
        cnt++;
    }
}

int main()
{
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();

    cout << cnt << endl;

    return 0;
}
