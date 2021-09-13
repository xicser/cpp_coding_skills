#include <iostream>
#include <thread>

using namespace std;


void threadA()
{
    cout << "I love threadA !" << endl;
}

/*
���߳�ִ������, �������̻߳�ûִ����, ��ʱ�����߳�Ҳ�ᱻ����ϵͳ��ֹ
��������ʹ��detach
*/
void test1()
{
    thread mytobj(threadA);   //�����߳�, ����ʼִ��

    cout << mytobj.joinable() << endl;  //true, ��ʾ����join����detach

//    mytobj.join();            //�������߳�, �ȴ����߳�ִ�����, ���������»��
    mytobj.detach();          //�����̱߳�C++����ʱ��ӹ�, ���̺߳����̷߳�����, һ��detach������join

    cout << mytobj.joinable() << endl;  //false, ��ʾ������join����detach

    cout << "I love China !" << endl;
}


/*
���ഴ���߳�
*/
class A {
public:
    int m_i;

    A(int i) : m_i(i) {}

    void operator()() //��������
    {
        cout << "1m_i = " << m_i << endl;
        cout << "2m_i = " << m_i << endl;
        cout << "3m_i = " << m_i << endl;
        cout << "4m_i = " << m_i << endl;
        cout << "5m_i = " << m_i << endl;
        cout << "6m_i = " << m_i << endl;
        cout << "7m_i = " << m_i << endl;
        cout << "8m_i = " << m_i << endl;
    }
};
void test2()
{
    int i = 6;
    A a(i);
    thread mytobj(a);

//    mytobj.join();
    mytobj.detach();   //����: ����detach, ���߳��������߳����н���, a�ᱻ���٣�a������, ���̻߳��ܵ������Ա����void operator()()��
    //����, thread mytobj(a); �ǰ�a ���� ���߳���ȥ, ���߳̽�����, a�Ǳ�����, ���Ǹ��Ƶ�a����

    cout << "I love China !" << endl;
}

/*
��lambda���ʽ�����߳�
*/
void test3()
{
    auto mylamthread = [] {
        cout << "mylamthread1" << endl;
        cout << "mylamthread2" << endl;
        cout << "mylamthread3" << endl;
        cout << "mylamthread4" << endl;
        cout << "mylamthread5" << endl;
    };

    thread mytobj(mylamthread);
//    mytobj.join();
    mytobj.detach();

    cout << "I love China !" << endl;
}



int main()
{
//    test2();
    test3();

    return 0;
}

