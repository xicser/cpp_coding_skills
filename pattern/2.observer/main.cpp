#include <iostream>
#include <list>

using namespace std;

/* 观察者 */
class AbstractHero {
public:
    virtual void update() = 0;
};

class HeroA : public AbstractHero {
public:
    HeroA() {
        cout << "英雄A正在打Boss..." << endl;
    }
    virtual void update() {
        cout << "英雄A停止打Boss" << endl;
    }
};
class HeroB : public AbstractHero {
public:
    HeroB() {
        cout << "英雄B正在打Boss..." << endl;
    }
    virtual void update() {
        cout << "英雄B停止打Boss" << endl;
    }
};
class HeroC : public AbstractHero {
public:
    HeroC() {
        cout << "英雄C正在打Boss..." << endl;
    }
    virtual void update() {
        cout << "英雄C停止打Boss" << endl;
    }
};


/* 被观察的 */
class AbstractBoss {
public:
    virtual void addHero(AbstractHero* hero) = 0;       //添加观察者
    virtual void deleteHero(AbstractHero* hero) = 0;    //删除观察者
    virtual void notifyHero(void) = 0;    //通知观察者
};

class Boss : public AbstractBoss {
public:
    virtual void addHero(AbstractHero* hero)       //添加观察者
    {
        heroList.push_back(hero);
    }
    virtual void deleteHero(AbstractHero* hero)    //删除观察者
    {
        heroList.remove(hero);
    }
    virtual void notifyHero(void)    //通知观察者
    {
        for (auto item : heroList) {
            item->update();
        }
    }

private:
    list<AbstractHero *> heroList;
};

int main()
{
    //三个观察者
    HeroA heroA;
    HeroB heroB;
    HeroC heroC;

    //观察目标
    Boss boss;
    boss.addHero(&heroA);
    boss.addHero(&heroB);
    boss.addHero(&heroC);

    cout << "HeroC阵亡..." << endl;
    boss.deleteHero(&heroC);

    cout << "Boss阵亡..." << endl;
    boss.notifyHero();

    return 0;
}
