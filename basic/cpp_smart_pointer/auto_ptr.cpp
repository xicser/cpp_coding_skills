/*
auto_ptr已弃用
*/

#include <iostream>
#include <memory>

using namespace std;

class Tiger {
public:
    Tiger(int age, int height) : height(height) {
        this->age = age;
        cout << "construct1 Tiger" << endl;
    }
    Tiger() {
        cout << "construct2 Tiger" << endl;
    }
    ~Tiger() {
        cout << "destruct Tiger" << endl;
    }

    void tigerBarking(void) {
        cout << "tiger_Barking" << endl;
    }

    //获取年龄
    int getAge(void) {
        return this->age;
    }

    //获取身高
    int getHeight(void) {
        return this->height;
    }

private:
    int age;
    int height;
};

void test_auto_ptr(void)
{
    auto_ptr<Tiger> tptr1(new Tiger(10, 20));

    //一个智能指针对象只能管理一个对象
    //不能赋值, 不能初始化另一个智能指针
    //赋值, 初始化会导致原来的智能指针失效
//    auto_ptr<Tiger> tptr2 = tptr1;
//    tptr1->tigerBarking();
//    tptr2->tigerBarking();

//    auto_ptr<Tiger> tptr3;
//    tptr3 = tptr1;          //不能赋值
//    tptr3->tigerBarking();


    //只能管理一个对象, 不能管理对象数组
    auto_ptr<Tiger> tptr4(new Tiger[3] {Tiger(12, 23), Tiger(23, 34), Tiger(45, 56)}); //崩溃
}
