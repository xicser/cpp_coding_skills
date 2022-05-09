#define _CRT_SECRUE_NO_WARINGS
#include <iostream>
#include <string>

using namespace std;

/*
装饰器模式（包装模式）
一般情况下用继承实现类的功能拓展
装饰模式可以动态给一个类增加功能



*/

/* 抽象英雄 */
class AbtractHero {
public:
    virtual void showStatus() = 0;

public:
    int mHp;
    int mMp;
    int mAt;
};

/* 具体英雄 */
class HeroA : public AbtractHero {
public:
    HeroA() {
        mHp = 12;
        mMp = 23;
        mAt = 34;
    }

    virtual void showStatus() {
        cout << "血量" << mHp << endl;
        cout << "魔法" << mMp << endl;
        cout << "攻击" << mAt << endl;
    }
};

/* 抽象装备 */
class AbtractEquipment : public AbtractHero {
public:
    AbtractEquipment(AbtractHero* hero) {
        this->pHero = hero;
    }

    virtual void showStatus() {

    }

    AbtractHero* pHero;
};

/* 狂徒 */
class KuangTuEquipment : public AbtractEquipment {
public:
    KuangTuEquipment(AbtractHero* hero) : AbtractEquipment(hero) {
        
    }

    void addKuangTu() {
        this->mHp = this->pHero->mHp;
        this->mMp = this->pHero->mMp;
        this->mAt = this->pHero->mAt + 30;
    }
};

/* 无尽之刃 */
class WujinKnifeEquipment : public AbtractEquipment {
public:
    WujinKnifeEquipment(AbtractHero* hero) : AbtractEquipment(hero) {

    }

    void addWujinKnife() {
        this->mHp = this->pHero->mHp;
        this->mMp = this->pHero->mMp + 99;
        this->mAt = this->pHero->mAt;
    }
};



int main()
{
    AbtractHero* hero = new HeroA();
    hero->showStatus();

    //给裸奔的英雄穿上衣服
    //狂徒
    hero = new KuangTuEquipment(hero);
    hero->showStatus();

    //无尽之刃
    hero = new WujinKnifeEquipment(hero);
    hero->showStatus();

    return 0;
}
