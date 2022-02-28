#include <iostream>

using namespace std;


/* 抽象苹果 */
class AppleAbstract {
public:
    virtual void showName() = 0;
};
/* 中国苹果 */
class AppleChina : public AppleAbstract {
public:
    virtual void showName() {
        cout << "China apple !" << endl;
    }
};
/* 美国苹果 */
class AppleUSA : public AppleAbstract {
public:
    virtual void showName() {
        cout << "USA apple !" << endl;
    }
};
/* 倭国苹果 */
class AppleJapan : public AppleAbstract {
public:
    virtual void showName() {
        cout << "Japan apple !" << endl;
    }
};




/* 抽象香蕉 */
class BananaAbstract {
public:
    virtual void showName() = 0;
};
/* 中国香蕉 */
class BananaChina : public BananaAbstract {
public:
    virtual void showName() {
        cout << "China banana !" << endl;
    }
};
/* 美国香蕉 */
class BananaUSA : public BananaAbstract {
public:
    virtual void showName() {
        cout << "USA banana !" << endl;
    }
};
/* 倭国香蕉 */
class BananaJapan : public BananaAbstract {
public:
    virtual void showName() {
        cout << "Japan banana !" << endl;
    }
};





/* 工厂抽象 */
class FactoryAbstract {
public:
    virtual AppleAbstract* createApple() = 0;
    virtual BananaAbstract* createBanana() = 0;
};
/* 中国工厂 */
class FactoryChina : public FactoryAbstract {
public:
    virtual AppleAbstract* createApple() {
        return new AppleChina();
    }
    virtual BananaAbstract* createBanana() {
        return new BananaChina();
    }
};
/* 美国工厂 */
class FactoryUSA : public FactoryAbstract {
public:
    virtual AppleAbstract* createApple() {
        return new AppleUSA();
    }
    virtual BananaAbstract* createBanana() {
        return new BananaUSA();
    }
};
/* 倭国工厂 */
class FactoryJapan : public FactoryAbstract {
public:
    virtual AppleAbstract* createApple() {
        return new AppleJapan();
    }
    virtual BananaAbstract* createBanana() {
        return new BananaJapan();
    }
};



int main()
{
    //以中国工厂为例
    FactoryChina factoryChina;
    AppleAbstract* apple = factoryChina.createApple();
    apple->showName();
    delete apple;

    return 0;
}
