#include <iostream>
#include <future>
#include <thread>

using namespace std;

//wait_for
//线程函数
int threadEntrance1()
{
    cout << "threadEntrance id = " << std::this_thread::get_id() << endl;
    std::chrono::milliseconds dura(2000);
    std::this_thread::sleep_for(dura);

    return -999;
}
void test1()
{
    cout << "Hello world! = " << std::this_thread::get_id() << endl;
    std::future<int> result = std::async(threadEntrance1);  //创建线程并执行
    cout << "continue... ..." << endl;
    
    //等子线程5s
    std::future_status status = result.wait_for(std::chrono::seconds(5));
    switch (status)
    {
    case std::future_status::ready:
        cout << "ready..." << endl;
        break;
    case std::future_status::timeout:
        cout << "timeout..." << endl;
        break;
    case std::future_status::deferred:
        //这么创建
        //std::future<int> result = std::async(std::launch::deferred, threadEntrance);
        //result.wait_for直接不等待, 立即走到这个case
        cout << "deferred..." << endl;
        //调用get才会执行, 实际上, 并没有创建子线程, 而是把子线程的代码插在这里执行了
        //从执行流程上讲(串行执行的), 这么做是可以的
        cout << result.get() << endl;

        break;
    default:
        break;
    }


    cout << "I love China !" << endl;
}








//shared_future
//线程函数
int threadEntrance2(int param)
{
    cout << "threadEntrance2 id = " << std::this_thread::get_id() << endl;
    std::chrono::milliseconds dura(2000);
    std::this_thread::sleep_for(dura);

    return -param;
}
void threadEntrance3(std::shared_future<int>& result_s)
{
    cout << "threadEntrance3 id = " << std::this_thread::get_id() << endl;
    cout << "threadEntrance3 " << result_s.get() << endl;
}
void test2()
{
    cout << "Hello world! = " << std::this_thread::get_id() << endl;

    std::packaged_task<int(int)> pt(threadEntrance2);
    std::future<int> result = pt.get_future();
    //std::shared_future<int> result_s(pt.get_future());
    std::thread t1(std::ref(pt), 123);  //123是传给线程的参数, 线程直接开始执行

    t1.detach();

    //std::shared_future<int> result_s(std::move(result));
    cout << result.valid() << endl;  //true
    std::shared_future<int> result_s(result.share()); //result变成空了, result_s里面有值了
    cout << result.valid() << endl;  //false

    cout << result_s.get() << endl;  //如果子线程没有执行完, 就一直等在这里, 否则就能立即得到值
    cout << result_s.get() << endl;  //多次get也可以, 第一个get返回后, 由于子线程已经执行完, 那么后面的get都能直接获取到值, 而不用等
    cout << result_s.get() << endl;
    cout << result_s.get() << endl;

    std::thread t2(threadEntrance3, std::ref(result_s));
    t2.join();

    cout << "I love China !" << endl;
}



int main()
{
    //test1();
    test2();
}
