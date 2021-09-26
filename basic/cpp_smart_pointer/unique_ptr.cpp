#include <iostream>
#include <memory>

using namespace std;

class Monkey {
public:
    Monkey(int age, int height) : height(height) {
        this->age = age;
        cout << "construct1 Monkey" << endl;
    }
    Monkey() {
        cout << "construct2 Monkey" << endl;
    }
    ~Monkey() {
        cout << "destruct Monkey" << endl;
    }

    void monkeyBarking(void) {
        cout << "monkey_Barking" << endl;
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

void test_unique_ptr(void)
{
    //unique_ptr对象始终是关联的原始指针的唯一所有者
    unique_ptr<Monkey> mptr1(new Monkey(10, 20));

    //不能拷贝构造
//    unique_ptr<Monkey> mptr2(mptr1);   //编译报错

    //不能赋值, 初始化
//    unique_ptr<Monkey> mptr3 = mptr1;  //编译报错
//    mptr3 = mptr1;          //编译报错

    //不能管理对象数组, 有的支持, 和编译环境有关
//    unique_ptr<Monkey> mptr4(new Monkey[3]); //崩溃

    //可以替换所有权
    unique_ptr<Monkey> mptr5 = std::move(mptr1); //替换所有权(移动构造函数)
    //在unique_ptr对象上调用release()将释放其关联的原始指针的所有权，并返回原始指针
    mptr1.release();

    mptr5->monkeyBarking();
}
