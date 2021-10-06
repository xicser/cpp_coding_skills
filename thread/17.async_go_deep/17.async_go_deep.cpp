#include <iostream>
#include <future>
#include <thread>


using namespace std;

/*
(2.1) std::async参数详述, async用来创建一个异步任务;
std::launch::deferred【延迟调用】
std::launch::async【强制创建一个线程】
std::thread()如果系统资源紧张，那么可能创建线程就会失败，那么执行std::thread()时整个程序可能崩溃。
std::async()我们一般不叫创建线程（解释async能够创建线程），我们一般叫它创建一个异步任务。
std::async和std::thread最明显的不同，就是async有时候并不创建新线程(如加上deferred参数)。

*/

//std::launch::deferred, 延迟到后面调用get才会执行子线程
//线程函数
int threadEntrance1()
{
    cout << "threadEntrance1 id = " << std::this_thread::get_id() << endl;
    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);

    return -999;
}
void test1()
{
    cout << "Hello world! = " << std::this_thread::get_id() << endl;
    std::future<int> result = std::async(std::launch::deferred, threadEntrance1);  //这个线程并不会执行

    cout << "continue... ..." << endl;

    //直到调用get才会启动子线程
    cout << result.get() << endl;

    cout << "I love China !" << endl;
}



//std::launch::async
//线程函数
int threadEntrance2()
{
    cout << "threadEntrance2 id = " << std::this_thread::get_id() << endl;
    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);

    return -999;
}
void test2()
{
    cout << "Hello world! = " << std::this_thread::get_id() << endl;
    std::future<int> result = std::async(std::launch::async, threadEntrance2);  //创建线程并强制执行

    cout << "continue... ..." << endl;
    cout << result.get() << endl;
    cout << "I love China !" << endl;
}



//不指定第一个参数
//线程函数
int threadEntrance3()
{
    cout << "threadEntrance3 id = " << std::this_thread::get_id() << endl;
    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);

    return -999;
}
void test3()
{
    cout << "Hello world! = " << std::this_thread::get_id() << endl;
    std::future<int> result = std::async(threadEntrance3);  //默认值是std::launch::async | std::launch::deferred,
                                                            //系统自己根据资源消耗情况决定异步(创建新线程相当于async)
                                                            //还是同步(不创建新线程相当于deferred)运行
    cout << "continue... ..." << endl;
    cout << result.get() << endl;
    cout << "I love China !" << endl;
}



/*
std::async和std::thread的区别
std::thread创建线程，如果系统资源紧张，创建线程失败，那么整个程序就会报异常崩溃(有脾气)
std::thread创建线程的方式，如果线程返回值，你想拿到这个值也不容易
std::async创建异步任务。可能创建也可能不创建线程。并且async调用方法很容易拿到线程入口函数的返回值;

由于系统资源限制:
(1)如果用std::thread创建的线程太多，则可能创建失败，系统报告异常，崩溃。
(2)如果用std::async，一般就不会报异常不会崩溃，因为如果系统资源紧张导致无法创建新线程的时候，
      std::async这种不加额外参数的调用就不会创建新线程。而是后续谁调用了result.get()来请求结果，那么这个异步任务mythread就运行在执行这条get()语句所在的线程上。
   如果你强制std::async一定要创建新线程，那么就必须使用std::launch::async。承受的代价就是系统资源紧张时，程序崩溃。
(3)经验:一个程序里, 线程数量大致在100-200。
*/




//不指定第一个参数，处理async的不确定性
int threadEntrance4()
{
    cout << "threadEntrance4 id = " << std::this_thread::get_id() << endl;
    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);

    return -999;
}
void test4()
{
    cout << "Hello world! = " << std::this_thread::get_id() << endl;

    //想知道async到底有没有创建新线程（立即执行）  还是  没创建新线程（延迟）
    std::future<int> result = std::async(threadEntrance4);  //默认值是std::launch::async | std::launch::deferred,
                                                            //系统自己根据资源消耗情况决定异步(创建新线程相当于async)
                                                            //还是同步(不创建新线程相当于deferred)运行
    //等0秒
    std::future_status status = result.wait_for(std::chrono::seconds(0));
    switch (status)
    {
        //系统资源紧张，线程被延迟创建了
        case std::future_status::deferred:
            cout << "deferred..." << endl;
            //调用get才会执行, 实际上, 并没有创建子线程, 而是把子线程的代码插在这里执行了
            //从执行流程上讲(串行执行的), 这么做是可以的
            cout << result.get() << endl;

            break;

        //没被推迟
        case std::future_status::ready:         //运行完了
        case std::future_status::timeout:       //线程还没执行完            
            //等一下
            result.get();

            break;

        default: break;
    }




    cout << "continue... ..." << endl;
    cout << result.get() << endl;
    cout << "I love China !" << endl;
}



int main()
{
    //test1();
    test2();

    return 0;
}
