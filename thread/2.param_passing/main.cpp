#include <iostream>
#include <thread>

/*
�ܽ�:
1, ������int���ּ����Ͳ��������鶼��ֵ����,��Ҫ�����á���ֹ������֦��
2, �����������󣬱�����ʽ����ת����ȫ�����ڴ����߳���һ�о͹�������ʱ��������Ȼ���ں������������������, �����������, ���´���������, �˷�
3, ������join()
*/


using namespace std;

//void print1(const int &i, char *p)
//void print1(const int i, char *p)
void print1(const int i, const string &str)
{
    cout << i << endl;   //������Ϊi������test1()��var������, ʵ����ֵ����, ��ô���߳�ʹ�����i, ��Ȼ�ǰ�ȫ��
    cout << str << endl;   //��ָ���Ǿ���������, ʵ����p����test1()�е�hello_str
}

void test1()
{
    int var = 1;
    char hello_str[] = "this is a test !";

    //������ʱ������Ϊ�̲߳���
//    thread threadObj(print1, var, hello_str);        //(��ʽת��)����hello_str�Ѿ���������(mainִ����), ϵͳ����hello_strתstring�Ŀ�����, ����һ������
    thread threadObj(print1, var, string(hello_str));  //����һ���϶�����ȷ��д��
    threadObj.detach();

    cout << "Hello world !" << endl;
}


class A {
public:
    A(int a) : m_i(a)  {
        cout << "���캯��" << endl;
    }
    A(const A &a) : m_i(a.m_i) {
        cout << "�������캯��" << endl;
    }
    ~A() {
        cout << "��������" << endl;
    }

private:
    int m_i;
};

void print2(int i, const A &a)
{
    cout << &a << endl;
}

void test2()
{
    int var = 1;
    thread threadObj(print2, var, A(12));  //����һ���϶�����ȷ��д��
//    threadObj.join();
    threadObj.detach();

    cout << "Hello world !" << endl;
}


int main()
{
//    test1();
    test2();

    return 0;
}
