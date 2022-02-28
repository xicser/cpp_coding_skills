#include <iostream>

using namespace std;


/* ����ƻ�� */
class AppleAbstract {
public:
    virtual void showName() = 0;
};
/* �й�ƻ�� */
class AppleChina : public AppleAbstract {
public:
    virtual void showName() {
        cout << "China apple !" << endl;
    }
};
/* ����ƻ�� */
class AppleUSA : public AppleAbstract {
public:
    virtual void showName() {
        cout << "USA apple !" << endl;
    }
};
/* ����ƻ�� */
class AppleJapan : public AppleAbstract {
public:
    virtual void showName() {
        cout << "Japan apple !" << endl;
    }
};




/* �����㽶 */
class BananaAbstract {
public:
    virtual void showName() = 0;
};
/* �й��㽶 */
class BananaChina : public BananaAbstract {
public:
    virtual void showName() {
        cout << "China banana !" << endl;
    }
};
/* �����㽶 */
class BananaUSA : public BananaAbstract {
public:
    virtual void showName() {
        cout << "USA banana !" << endl;
    }
};
/* �����㽶 */
class BananaJapan : public BananaAbstract {
public:
    virtual void showName() {
        cout << "Japan banana !" << endl;
    }
};





/* �������� */
class FactoryAbstract {
public:
    virtual AppleAbstract* createApple() = 0;
    virtual BananaAbstract* createBanana() = 0;
};
/* �й����� */
class FactoryChina : public FactoryAbstract {
public:
    virtual AppleAbstract* createApple() {
        return new AppleChina();
    }
    virtual BananaAbstract* createBanana() {
        return new BananaChina();
    }
};
/* �������� */
class FactoryUSA : public FactoryAbstract {
public:
    virtual AppleAbstract* createApple() {
        return new AppleUSA();
    }
    virtual BananaAbstract* createBanana() {
        return new BananaUSA();
    }
};
/* �������� */
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
    //���й�����Ϊ��
    FactoryChina factoryChina;
    AppleAbstract* apple = factoryChina.createApple();
    apple->showName();
    delete apple;

    return 0;
}
