#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#include <vector>
#include <list>
#include <thread>
#include <mutex>
#include <string>

using namespace std;

/* �̳߳� */
class ThreadPool {
public:
    ThreadPool(int poolSize);
    ~ThreadPool();

private:
    //�߳̿��ƽṹ��
    typedef struct {
        int id;                             //�߳�id
        thread* pThreadObj;                 //�̶߳���ָ��
    } ThreadInfo_t;

    mutex muxCmd;                           //������(�����������)
    condition_variable condition;           //��������
    list<string> cmdQueue;                  //�������

    int poolSize;                           //�̳߳ش�С
    atomic<int> threadAvailable;            //�����߳�����
    vector<ThreadInfo_t> threadsInfo;       //�洢�߳���Ϣ
    thread* pThreadInObj;                   //�����̶߳���ָ��

    void threadEntrance(int threadId);      //�̺߳���
    void threadGetCmd(void);                //��ȡ�����߳�
    void poolExpansion(void);               //�̳߳�����
};

#endif
