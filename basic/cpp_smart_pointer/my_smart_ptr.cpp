/*
自己实现的智能指针, 用来加深对智能指针的理解
*/

#include <iostream>

using namespace std;

template <typename T>
class SharedPtr {
public:

    //构造
    SharedPtr() : ptr(nullptr), countRef(new int(0)) {}
    SharedPtr(T *_ptr) : ptr(_ptr), countRef(new int(1)) {}

    //拷贝构造
    SharedPtr(const SharedPtr<T> &other) : ptr(other.ptr), countRef(other.countRef) {
        (*countRef)++;
    }

    //析构
    ~SharedPtr() {
        release();
    }

    //重载赋值运算符
    SharedPtr<T> operator=(const SharedPtr<T> &other) {
        //保证不是自己和自己赋值
        if (this != &other) {
            this->release();            //释放原来管理的对象
            ptr = other.ptr;
            countRef = other.countRef;
            (*countRef)++;
        }

        return *this;
    }

    T& operator*(void) {
        return *ptr;
    }
    T& operator->(void) {
        return ptr;
    }

    T *getPtr(void) {
        return ptr;
    }

    int getRefCount(void) {
        return *countRef;
    }

private:
    T *ptr;                  //指向管理的对象
    int *countRef;           //引用计数

    void release() {
        (*countRef)--;
        if (*countRef == 0 || *countRef == -1) {
            if (ptr != nullptr) {
                delete ptr;
            }
            delete countRef;
        }
    }
};

class Test
{
public:
    Test() {
        cout << "Test" << endl;
    }
    ~Test() {
        cout << "~Test" << endl;
    }
};


void test_my_smart_ptr(void)
{
    SharedPtr<Test> tptr1(new Test());
    cout << "count = " << tptr1.getRefCount() << endl;

    SharedPtr<Test> tptr2 = tptr1;
    cout << "count = " << tptr2.getRefCount() << endl;

    SharedPtr<Test> tptr3(new Test());
    cout << "count = " << tptr3.getRefCount() << endl;

    SharedPtr<Test> tptr4;
    cout << "count = " << tptr4.getRefCount() << endl;
    tptr4 = tptr3;
    cout << "count = " << tptr4.getRefCount() << endl;
}
