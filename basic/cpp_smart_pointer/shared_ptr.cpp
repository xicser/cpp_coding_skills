/*
auto_ptr��unique_prt���ھ��о�����(��ռ�Ե�), ����auto_ptr�Ѿ�����,
�ص�����shared_ptr
*/

#include <iostream>
#include <memory>
#include "shared_ptr.h"

using namespace std;

class Dog {
public:
    Dog(int age, int height) : height(height) {
        this->age = age;
        cout << "construct Dog" << endl;
    }
    ~Dog() {
        cout << "destruct Dog" << endl;
    }

    void dogBarking(void) {
        cout << "dog_Barking" << endl;
    }

    //��ȡ����
    int getAge(void) {
        return this->age;
    }

    //��ȡ���
    int getHeight(void) {
        return this->height;
    }

private:
    int age;
    int height;
};

void test_shared_ptr(void)
{
    shared_ptr<Dog> pDog1(new Dog(10, 20));
    shared_ptr<Dog> pDog2 = make_shared<Dog>(12, 22);

    cout << pDog1.use_count() << endl;      //1
    cout << pDog2.use_count() << endl;      //1

//    shared_ptr<Dog> pDog3 = pDog1;
    shared_ptr<Dog> pDog3(pDog1);

    cout << pDog1.use_count() << endl;      //2
    cout << pDog2.use_count() << endl;      //1
    cout << pDog3.use_count() << endl;      //2

    pDog1->dogBarking();
    cout << pDog1.get() << endl;
}
