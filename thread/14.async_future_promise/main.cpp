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

void test1()
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

void test2()
{
    Test test;
    std::future<int> result = std::async(&Test::threadEntrance, ref(test), 999);  //创建线程并执行

    cout << "... ..." << endl;
    cout << result.get() << endl;
    cout << "I love China !" << endl;

    //如果不用get, 那么在result析构的时候, 依然会等待子线程执行完毕
}

// 参数测试deferred
void test3()
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
void test4()
{
    Test test;

    //创建线程并执行, async表示调用std::async的时候, 就创建了子线程, 子线程立即开始执行
    std::future<int> result = std::async(std::launch::async, &Test::threadEntrance, ref(test), 999);

    cout << "... ..." << endl;
    cout << result.get() << endl;
    cout << "I love China !" << endl;

    cout << "main id = " << std::this_thread::get_id() << endl;

}


//std::packaged_task
//std::packaged_task  可以包裹一个函数, 有点类似std::function,
//不同之处在于这个可以通过get_future返回std::future对象来获取异步执行的函数结果
//线程函数
int threadEntrance1(int param)
{
    cout << "id = " << std::this_thread::get_id() << endl;
    std::chrono::milliseconds dura(2000);
    std::this_thread::sleep_for(dura);

    return -param;
}
void test5()
{
    cout << "Hello world! = " << std::this_thread::get_id() << endl;

    std::packaged_task<int(int)> pt(threadEntrance1);
    std::thread t1(std::ref(pt), 123);  //123是传给线程的参数, 线程直接开始执行

    t1.detach();

    std::future<int> result = pt.get_future();

    std::chrono::milliseconds dura(3000);
    std::this_thread::sleep_for(dura);

    cout << result.get() << endl; //get只能调用一次, 等待threadEntrance2执行完毕, 如果已经执行完毕, 立即返回子线程返回的结果
    cout << "I love China !" << endl;
}



//promise可以用来在线程间提供数据传递
//在某个线程中给它赋值, 然后可以在其他线程中把它取出来
void threadEntrance2(std::promise<int> &promiseIn, int calc)
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
void test6()
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
//    test1();
//    test2();
//    test3();
//    test4();
    test5();
//    test6();


    cout << "out..." << endl;
    return 0;
}
