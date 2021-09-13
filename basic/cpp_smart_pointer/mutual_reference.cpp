/*
智能指针相互引用引起的bug
*/

#include <iostream>
#include <memory>
#include "mutual_reference.h"

using namespace std;

void test_mutual_ref_ptr(void)
{
    shared_ptr<Mouse> pMouse = make_shared<Mouse>(12, 13);
    shared_ptr<Cat> pCat = make_shared<Cat>(15, 16);
    pMouse->ppCat = pCat;
    pCat->ppMouse = pMouse;

    cout << pMouse.use_count() << endl;         //2
    cout << pCat.use_count() << endl;           //2

    //如果不使用weak_ptr, 会内存泄漏
}
