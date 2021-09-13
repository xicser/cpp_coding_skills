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
    unique_ptr<Monkey> mptr1(new Monkey(10, 20));

    //不能拷贝构造
//    unique_ptr<Monkey> mptr2(mptr1);   //编译报错

    //不能赋值, 初始化
//    unique_ptr<Monkey> mptr3 = mptr1;  //编译报错
//    mptr3 = mptr1;          //编译报错

    //不能管理对象数组, 有的支持, 和编译环境有关
//    unique_ptr<Monkey> mptr4(new Monkey[3]); //崩溃

    //可以替换所有权
    unique_ptr<Monkey> mptr5 = move(mptr1); //替换所有权
    mptr1.release();                        //释放所有权

    mptr5->monkeyBarking();
}
