#include <iostream>
#include <future>
#include <thread>

using namespace std;

//std::packaged_task
//std::packaged_task  可以包裹一个函数, 有点类似std::function,
//不同之处在于这个可以通过get_future返回std::future对象来获取异步线程执行的结果
//线程函数
int threadEntrance1(int param)
{
    cout << "id = " << std::this_thread::get_id() << endl;
    std::chrono::milliseconds dura(2000);
    std::this_thread::sleep_for(dura);

    return -param;
}
void test1()
{
    cout << "Hello world! = " << std::this_thread::get_id() << endl;

    std::packaged_task<int(int)> pt(threadEntrance1);
    std::future<int> result = pt.get_future();
    std::thread t1(std::ref(pt), 123);  //123是传给线程的参数, 线程直接开始执行

    t1.detach();

    std::chrono::milliseconds dura(3000);
    std::this_thread::sleep_for(dura);

    cout << result.get() << endl; //get只能调用一次, 等待threadEntrance2执行完毕, 如果已经执行完毕, 立即返回子线程返回的结果
    cout << "I love China !" << endl;
}



//promise可以用来在线程间提供数据传递
//在某个线程中给它赋值, 然后可以在其他线程中把它取出来
void threadEntrance2(std::promise<int>& promiseIn, int calc)
{
    cout << "calc ing" << endl;

    //计算了5s
    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);
    calc += 1000;

    //保存计算结果
    int result = calc;
    promiseIn.set_value(result);
}
void test2()
{
    std::promise<int> prom;
    std::thread t1(threadEntrance2, ref(prom), 321);
    t1.detach();

    //获取结果
    std::future<int> fut = prom.get_future();
    auto result = fut.get(); //get只能调用一次, 等待threadEntrance2执行完毕

    cout << "result = " << result << endl;
}

int main()
{
    test1();
    test2();

    cout << "out..." << endl;
    return 0;
}
