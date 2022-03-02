
/*
开闭原则―对扩展开放，对修改关闭，增加功能是通过增加代码来实现，而不是去修改现有源代码
*/

#include <iostream>

using namespace std;

class AbstractCalculator {
public:
    virtual int  getResult() = 0;
    virtual void setOpNum(int a, int b) = 0;
};

/* 加法计算器 */
class PlusCalculator : public AbstractCalculator {
public:
    virtual int getResult() {
        return mA + mB;
    }

    virtual void setOpNum(int a, int b) {
        mA = a;
        mB = b;
    }

private:
    int mA;
    int mB;
};

/* 减法计算器 */
class MinusCalculator : public AbstractCalculator {
public:
    virtual int getResult() {
        return mA - mB;
    }

    virtual void setOpNum(int a, int b) {
        mA = a;
        mB = b;
    }

private:
    int mA;
    int mB;
};

/* 乘法 */

/* 除法 */


void test1()
{
    //以加法为例
    AbstractCalculator* cal = new PlusCalculator();
    cal->setOpNum(10, 20);
    cout << cal->getResult() << endl;
    delete cal;
}
