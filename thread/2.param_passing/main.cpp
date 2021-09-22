#include <iostream>
#include <thread>
#include <memory>

using namespace std;

/*
�ܽ�:
1, ������int���ּ����Ͳ��������鶼��ֵ����,��Ҫ�����á���ֹ������֦��
2, �����������󣬱�����ʽ����ת����ȫ�����ڴ����߳���һ�о͹�������ʱ��������Ȼ���ں������������������, �����������, ���´���������, �˷�
3, ������join()
*/

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
        cout << "���캯��" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
    }
    A(const A &a) : m_i(a.m_i) {
        cout << "�������캯��" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
    }
    ~A() {
//        cout << "��������" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
    }

private:
    int m_i;
};

void print2(int i, const A &a)
{
    cout << "print2 : " << &a << " thread_id = " << this_thread::get_id() << endl;
}

void test2()
{
    cout << "��thread_id = " << this_thread::get_id() << endl;

    int var = 1;
    int aParam = 12;
    thread threadObj(print2, var, A(aParam));  //����һ���϶�����ȷ��д��, �����߳�ִ�н���֮ǰ(aParamδ�ͷ�֮ǰ), ����A�Ѿ��������
//    threadObj.join();
    threadObj.detach();

    cout << endl << "Hello world !" << endl << endl;
}











/* ref */
class B {
public:
    B(int a) : m_i(a)  {
        cout << "���캯��" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
    }
    B(const B &a) : m_i(a.m_i) {
        cout << "�������캯��" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
    }
    ~B() {
        cout << "��������" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
    }

    void setVal(int val) {
        this->m_i = val;
    }
    int getVal(void) {
        return this->m_i;
    }

private:
    int m_i;
};

void print3(B &b)
{
    b.setVal(199);
}
void test3()
{
    B obj(10);
    printf("%d\n", obj.getVal());
    thread threadObj(print3, ref(obj));         //print3�ж�obj���޸�, �൱���޸ı��������obj
    threadObj.join();                           //�����ÿ������캯��, ��ô�����������detach�Ͳ���ȫ��
    printf("%d", obj.getVal());
}











/* ����ָ�� */
void print4(shared_ptr<B> iptr)
{
    cout << "print4 " << iptr.use_count() << endl;
}
void test4()
{
    shared_ptr<B> iptr(new B(21));
    thread threadObj(print4, iptr);
    threadObj.join();
//    threadObj.detach();

    cout << "test4 " << iptr.use_count() << endl;
}








/* ��������Ա�������̺߳��� */
class C {
public:
    C(int a) : m_i(a)  {
        cout << "���캯��" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
    }
    C(const C &a) : m_i(a.m_i) {
        cout << "�������캯��" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
    }
    ~C() {
        cout << "��������" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
    }

    void setVal(int val) {
        this->m_i = val;
    }
    int getVal(void) {
        return this->m_i;
    }

    void thread_work(int num) {
        cout << "thread_work " << num << endl;
    }

    void operator()(int num)
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

private:
    int m_i;
};
void test5()
{
    C obj(43);
//    thread mythread(&C::thread_work, obj, 1234);
//    mythread.join();

    thread mythread(obj, 15);
    mythread.join();

}

















int main()
{
//    test1();
//    test2();
//    test3();
//    test4();

    test5();

    return 0;
}
