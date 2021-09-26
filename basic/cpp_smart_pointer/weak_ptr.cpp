#include "weak_ptr.h"
#include <memory>

//weak_ptr设计之初就是为了服务于shared_ptr的，所以不增加引用计数就是它的核心功能。
void test_weak_ptr(void)
{
    shared_ptr<AA> aptr = make_shared<AA>();
    weak_ptr<AA> wptr = aptr;           //weak_ptr不会影响引用计数, 但是也不能进行 * 和 -> 操作

    cout << aptr.use_count() << endl;   //1

    //先判断弱引用所指向的对象是否已经销毁
    if (wptr.expired() == false) {
        shared_ptr<AA> aaptr = wptr.lock();     //获取指向对象的shared_ptr, 此时引用计数会 + 1
        cout << aptr.use_count() << endl;       //2
        cout << aaptr.use_count() << endl;      //2
    }
}
