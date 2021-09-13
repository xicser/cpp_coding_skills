#include <iostream>
#include <thread>

using namespace std;


void threadA()
{
    cout << "I love threadA !" << endl;
}

/*
主线程执行完了, 但是子线程还没执行完, 这时候子线程也会被操作系统终止
不过可以使用detach
*/
void test1()
{
    thread mytobj(threadA);   //创建线程, 并开始执行

    cout << mytobj.joinable() << endl;  //true, 表示可以join或者detach

//    mytobj.join();            //阻塞主线程, 等待子线程执行完毕, 在这里重新汇合
    mytobj.detach();          //让子线程被C++运行时库接管, 子线程和主线程分离了, 一旦detach不能再join

    cout << mytobj.joinable() << endl;  //false, 表示不可以join或者detach

    cout << "I love China !" << endl;
}


/*
用类创建线程
*/
class A {
public:
    int m_i;

    A(int i) : m_i(i) {}

    void operator()() //不带参数
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
    mytobj.detach();   //疑问: 调用detach, 主线程先于子线程运行结束, a会被销毁，a被销毁, 子线程还能调用其成员函数void operator()()吗？
    //可以, thread mytobj(a); 是把a 复制 到线程中去, 主线程结束后, a是被销毁, 但是复制的a还在

    cout << "I love China !" << endl;
}

/*
用lambda表达式创建线程
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

