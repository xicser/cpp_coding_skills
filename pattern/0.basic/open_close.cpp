
/*
����ԭ��D����չ���ţ����޸Ĺرգ����ӹ�����ͨ�����Ӵ�����ʵ�֣�������ȥ�޸�����Դ����
*/

#include <iostream>

using namespace std;

class AbstractCalculator {
public:
    virtual int  getResult() = 0;
    virtual void setOpNum(int a, int b) = 0;
};

/* �ӷ������� */
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

/* ���������� */
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

/* �˷� */

/* ���� */


void test1()
{
    //�Լӷ�Ϊ��
    AbstractCalculator* cal = new PlusCalculator();
    cal->setOpNum(10, 20);
    cout << cal->getResult() << endl;
    delete cal;
}
