#include <iostream>
#include <thread>
#include <stdio.h>

using namespace std;

class Mutex {
private:
    atomic_flag flag;

public:
    Mutex() {
        flag.clear();
    }
    ~Mutex() {
        flag.clear();
    }

    void lock() {
        while (true == flag.test_and_set()) {

        }
    }
    void unlock() {
        flag.clear();
    }
};


int value = 0;
int cnt = 10000;
Mutex mutex;
void thread1() {

    for (int i = 0; i < cnt; i++) {
        mutex.lock();
        value++;
        mutex.unlock();
    }
}

void thread2() {
    for (int i = 0; i < cnt; i++) {
        mutex.lock();
        value++;
        mutex.unlock();
    }
}

int main()
{
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();

    printf("cnt = %d\n", value);
}
