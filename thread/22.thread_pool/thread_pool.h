#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#include <vector>
#include <list>
#include <thread>
#include <mutex>
#include <string>

using namespace std;

/* 线程池 */
class ThreadPool {
public:
    ThreadPool(int poolSize);
    ~ThreadPool();

private:
    //线程控制结构体
    typedef struct {
        int id;                             //线程id
        thread* pThreadObj;                 //线程对象指针
    } ThreadInfo_t;

    mutex muxCmd;                           //互斥量(保护命令队列)
    condition_variable condition;           //条件变量
    list<string> cmdQueue;                  //命令队列

    int poolSize;                           //线程池大小
    atomic<int> threadAvailable;            //可用线程数量
    vector<ThreadInfo_t> threadsInfo;       //存储线程信息
    thread* pThreadInObj;                   //输入线程对象指针

    void threadEntrance(int threadId);      //线程函数
    void threadGetCmd(void);                //获取命令线程
    void poolExpansion(void);               //线程池扩容
};

#endif
