#include <iostream>
#include <list>

using namespace std;

/* �۲��� */
class AbstractHero {
public:
    virtual void update() = 0;
};

class HeroA : public AbstractHero {
public:
    HeroA() {
        cout << "Ӣ��A���ڴ�Boss..." << endl;
    }
    virtual void update() {
        cout << "Ӣ��Aֹͣ��Boss" << endl;
    }
};
class HeroB : public AbstractHero {
public:
    HeroB() {
        cout << "Ӣ��B���ڴ�Boss..." << endl;
    }
    virtual void update() {
        cout << "Ӣ��Bֹͣ��Boss" << endl;
    }
};
class HeroC : public AbstractHero {
public:
    HeroC() {
        cout << "Ӣ��C���ڴ�Boss..." << endl;
    }
    virtual void update() {
        cout << "Ӣ��Cֹͣ��Boss" << endl;
    }
};


/* ���۲�� */
class AbstractBoss {
public:
    virtual void addHero(AbstractHero* hero) = 0;       //��ӹ۲���
    virtual void deleteHero(AbstractHero* hero) = 0;    //ɾ���۲���
    virtual void notifyHero(void) = 0;    //֪ͨ�۲���
};

class Boss : public AbstractBoss {
public:
    virtual void addHero(AbstractHero* hero)       //��ӹ۲���
    {
        heroList.push_back(hero);
    }
    virtual void deleteHero(AbstractHero* hero)    //ɾ���۲���
    {
        heroList.remove(hero);
    }
    virtual void notifyHero(void)    //֪ͨ�۲���
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
    //�����۲���
    HeroA heroA;
    HeroB heroB;
    HeroC heroC;

    //�۲�Ŀ��
    Boss boss;
    boss.addHero(&heroA);
    boss.addHero(&heroB);
    boss.addHero(&heroC);

    cout << "HeroC����..." << endl;
    boss.deleteHero(&heroC);

    cout << "Boss����..." << endl;
    boss.notifyHero();

    return 0;
}
