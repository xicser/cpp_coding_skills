#include "thread_pool.h"
#include <iostream>


ThreadPool::ThreadPool(int poolSize)
{
	this->poolSize = poolSize;
    this->threadAvailable = this->poolSize;

    //创建poolSize个线程
    for (int i = 0; i < this->poolSize; i++) {
        ThreadInfo_t threadi;
        threadi.id = i;
        threadi.pThreadObj = new thread(&ThreadPool::threadEntrance, ref(*this), threadi.id); //这句执行后, 线程立即开始执行

        threadsInfo.push_back(threadi);
    }

    //创建输入线程
    pThreadInObj = new thread(&ThreadPool::threadGetCmd, ref(*this));

    //等待所有子线程执行完毕
    for (auto iter = threadsInfo.begin(); iter != threadsInfo.end(); iter++) {
        iter->pThreadObj->join();
    }
    pThreadInObj->join();
}

ThreadPool::~ThreadPool()
{
    //销毁创建的子线程对象
    for (int i = 0; i < this->poolSize; i++) {
        delete threadsInfo[i].pThreadObj;
    }
    delete pThreadInObj;
}

/* 获取命令线程 */
void ThreadPool::threadGetCmd(void)
{
    while (true) {
        string cmd = "abc";
        //getline(cin, cmd, '\n');
        std::chrono::milliseconds dura(10);
        std::this_thread::sleep_for(dura);

        muxCmd.lock();
        cmdQueue.push_back(cmd);

        //看看现在有没有可用线程
        if (this->threadAvailable > 0) {

            //可用线程减1
            this->threadAvailable--;
            condition.notify_all();
        }
        else {
            //线程池扩容
            cout << "线程池容量紧张！" << endl;
            poolExpansion();
            condition.notify_all();
        }
        muxCmd.unlock();
    }
}

/* 线程池扩容 */
void ThreadPool::poolExpansion(void)
{
    //给线程池当中每次增加5个线程
    for (int i = 0; i < 5; i++) {
        ThreadInfo_t threadi;
        threadi.id = i;
        threadi.pThreadObj = new thread(&ThreadPool::threadEntrance, ref(*this), threadi.id);

        threadsInfo.push_back(threadi);
        this->poolSize++;
    }
}

/* 线程函数 */
void ThreadPool::threadEntrance(int threadId)
{
	while (true) {

        //加锁
        unique_lock<mutex> ulock(muxCmd);
        condition.wait(ulock, [this] {
            //处理一下虚假唤醒
            if (cmdQueue.empty() == false) {
                return true;   //命令队列中有数据
            }
            else {
                return false;  //命令队列中没有数据
            }
        });

        string cmd = cmdQueue.front();
        cmdQueue.pop_front();
        ulock.unlock();

        //处理
        std::chrono::milliseconds dura(2000);
        std::this_thread::sleep_for(dura);
        cout << "线程" << threadId << "处理完成" << ", 命令为" << cmd << endl;

        //可用线程减1
        this->threadAvailable++;
    }
}
