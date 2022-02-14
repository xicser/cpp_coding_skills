#include <iostream>
#include <future>
#include <thread>

using namespace std;

//线程函数
int threadEntrance()
{
    //    cout << "id = " << std::this_thread::get_id() << endl;
    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);
    //    cout << "id = " << std::this_thread::get_id() << endl;

    return -999;
}

void test5()
{
    cout << "Hello world! = " << std::this_thread::get_id() << endl;
    std::future<int> result = std::async(threadEntrance);  //创建线程并执行

    cout << "... ..." << endl;

    // get会等子线程结束, 然后获取它的返回值, 若子线程没有执行结束, 就一直等在这里
    // get只能调用一次
    cout << result.get() << endl;
    //    result.wait();                    // 和get类似, 只是不能返回线程的执行结果

    cout << "I love China !" << endl;
}


class Test {
public:
    //线程函数
    int threadEntrance(int param)
    {
        cout << "threadEntrance id = " << std::this_thread::get_id() << endl;
        std::chrono::milliseconds dura(5000);
        std::this_thread::sleep_for(dura);

        return param * 10;
    }
};

void test6()
{
    Test test;
    std::future<int> result = std::async(&Test::threadEntrance, ref(test), 999);  //创建线程并执行

    cout << "... ..." << endl;
    cout << result.get() << endl;
    cout << "I love China !" << endl;

    //如果不用get, 那么在result析构的时候, 依然会等待子线程执行完毕
}

// 参数测试deferred
void test7()
{
    Test test;

    //创建线程并执行, deferred表示子线程的调用被延迟到future的get或者wait函数被调用时才执行
    std::future<int> result = std::async(std::launch::deferred, &Test::threadEntrance, ref(test), 999);

    cout << "... ..." << endl;
    cout << result.get() << endl;        //实际上, 并没有创建子线程, 而是把子线程的代码插在这里执行了
    cout << "I love China !" << endl;    //从执行流程上讲(串行执行的), 这么做是可以的

    cout << "main id = " << std::this_thread::get_id() << endl;

}

// 参数测试async
void test8()
{
    Test test;

    //创建线程并执行, async表示调用std::async的时候, 就创建了子线程, 子线程立即开始执行
    std::future<int> result = std::async(std::launch::async, &Test::threadEntrance, ref(test), 999);

    cout << "... ..." << endl;
    cout << result.get() << endl;
    cout << "I love China !" << endl;

    cout << "main id = " << std::this_thread::get_id() << endl;

}

int main()
{

    cout << "out..." << endl;
    return 0;
}
