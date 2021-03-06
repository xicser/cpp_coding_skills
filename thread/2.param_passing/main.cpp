#include <iostream>
#include <thread>
#include <memory>

using namespace std;

/*
总结:
1, 若传递int这种简单类型参数，建议都是值传递,不要用引用。防止节外生枝。
2, 如果传递类对象，避免隐式类型转换。全部都在创建线程这一行就构建出临时对象来，然后在函数参数里，用引用来接, 如果不用引用, 还会拷贝构造对象, 浪费
3, 建议用join()
*/

//void print1(const int &i, char *p)
//void print1(const int i, char *p)
void print1(const int i, const string &str)
{
    cout << i << endl;   //分析认为i并不是test1()中var的引用, 实际是值传递, 那么子线程使用这个i, 依然是安全的
    cout << str << endl;   //而指针是绝对有问题, 实际上p就是test1()中的hello_str
}

void test1()
{
    int var = 1;
    char hello_str[] = "this is a test !";

    //传递临时对象作为线程参数
//    thread threadObj(print1, var, hello_str);        //(隐式转换)存在hello_str已经被回收了(main执行完), 系统才用hello_str转string的可能性, 这是一个问题
    thread threadObj(print1, var, string(hello_str));  //这是一个肯定的正确的写法
    threadObj.detach();

    cout << "Hello world !" << endl;
}














class A {
public:
    A(int a) : m_i(a)  {
        cout << "构造函数" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
    }
    A(const A &a) : m_i(a.m_i) {
        cout << "拷贝构造函数" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
    }
    ~A() {
//        cout << "析构函数" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
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
    cout << "主thread_id = " << this_thread::get_id() << endl;

    int var = 1;
    int aParam = 12;
    thread threadObj(print2, var, A(aParam));  //这是一个肯定的正确的写法, 在主线程执行结束之前(aParam未释放之前), 对象A已经构建完毕
//    threadObj.join();
    threadObj.detach();

    cout << endl << "Hello world !" << endl << endl;
}











/* ref */
class B {
public:
    B(int a) : m_i(a)  {
        cout << "构造函数" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
    }
    B(const B &a) : m_i(a.m_i) {
        cout << "拷贝构造函数" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
    }
    ~B() {
        cout << "析构函数" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
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
    thread threadObj(print3, ref(obj));         //print3中对obj的修改, 相当于修改本函数里的obj
    threadObj.join();                           //不调用拷贝构造函数, 那么后续如果调用detach就不安全了
    printf("%d", obj.getVal());
}











/* 智能指针 */
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








/* 类的任意成员函数做线程函数 */
class C {
public:
    C(int a) : m_i(a)  {
        cout << "构造函数" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
    }
    C(const C &a) : m_i(a.m_i) {
        cout << "拷贝构造函数" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
    }
    ~C() {
        cout << "析构函数" << " " << this << " " << "thread_id = " << this_thread::get_id() << endl;
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
        cout << "num = " << num << endl;
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
