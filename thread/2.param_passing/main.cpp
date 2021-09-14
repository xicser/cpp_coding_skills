#include <iostream>
#include <thread>

/*
总结:
1, 若传递int这种简单类型参数，建议都是值传递,不要用引用。防止节外生枝。
2, 如果传递类对象，避免隐式类型转换。全部都在创建线程这一行就构建出临时对象来，然后在函数参数里，用引用来接, 如果不用引用, 还会拷贝构造对象, 浪费
3, 建议用join()
*/


using namespace std;

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
        cout << "构造函数" << endl;
    }
    A(const A &a) : m_i(a.m_i) {
        cout << "拷贝构造函数" << endl;
    }
    ~A() {
        cout << "析构函数" << endl;
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
    thread threadObj(print2, var, A(12));  //这是一个肯定的正确的写法
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
