#define _CRT_SECRUE_NO_WARINGS
#include <iostream>
#include <string>

using namespace std;

/*
装饰器模式（包装模式）
一般情况下用继承实现类的功能拓展, 为了得到新功能, 每次继承一次都会多一个子类, 这样会导致子类非常多
装饰模式可以动态给一个类增加功能

*/


/* 抽象饮料 */
class Beverage {
public:
    virtual double cost() = 0;        //计算价钱
};

/* 奶茶 */
class MilkTea : public Beverage {
public:
    virtual double cost() {
        cout << "MilkTea cost 5.5 $" << endl;
        return 5.5;
    }
};

/* 水果茶 */
class FruitTea : public Beverage {
public:
    virtual double cost() {
        cout << "FruitTea cost 6.5 $" << endl;
        return 6.5;
    }
};

/* 佐料(装饰器类) */
class ToppingDecorator : public Beverage {
public:
    //virtual double cost() = 0;        //计算价钱
};

/* 加布丁 */
class Pudding : public ToppingDecorator {
public:
    Pudding(Beverage* bverage) {
        this->bverage = bverage;
    }

    virtual double cost() {
        return costPudding + bverage->cost();
    }

private:
    int costPudding = 2;  //加补丁要两块钱
    Beverage* bverage;
};

/* 加珍珠 */
class Boba : public ToppingDecorator {
public:
    Boba(Beverage* bverage) {
        this->bverage = bverage;
    }

    virtual double cost() {
        return costBoba + bverage->cost();
    }

private:
    int costBoba = 3;  //加珍珠要三块钱
    Beverage* bverage;
};

int main()
{
    Beverage* bverage = new MilkTea();      //先来一杯奶茶
    bverage = new Boba(bverage);            //加一份珍珠
    bverage = new Boba(bverage);            //再加一份珍珠
    bverage = new Pudding(bverage);         //加一份布丁
    double cost = bverage->cost();          //计算总价

    cout << cost << endl;

    return 0;
}
