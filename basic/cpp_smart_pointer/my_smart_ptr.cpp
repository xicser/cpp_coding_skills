/*
�Լ�ʵ�ֵ�����ָ��, �������������ָ������
*/

#include <iostream>

using namespace std;

template <typename T>
class SharedPtr {
public:

    //����
    SharedPtr() : ptr(nullptr), countRef(new int(0)) {}
    SharedPtr(T *_ptr) : ptr(_ptr), countRef(new int(1)) {}

    //��������
    SharedPtr(const SharedPtr<T> &other) : ptr(other.ptr), countRef(other.countRef) {
        (*countRef)++;
    }

    //����
    ~SharedPtr() {
        release();
    }

    //���ظ�ֵ�����
    SharedPtr<T> operator=(const SharedPtr<T> &other) {
        //��֤�����Լ����Լ���ֵ
        if (this != &other) {
            this->release();            //�ͷ�ԭ������Ķ���
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
    T *ptr;                  //ָ�����Ķ���
    int *countRef;           //���ü���

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
