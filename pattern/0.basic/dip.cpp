/*
依赖倒置原则：
上层模块不应该依赖于下层模块，他们共同依赖于一个抽象层，即：父类不能依赖子类，他们都要依赖抽象类。
抽象不能依赖于具体，具体应该要依赖于抽象。
一般情况下抽象的变化概率很小，让用户程序依赖于抽象，实现的细节也依赖于抽象。即使实现细节不断变动，只要抽象不变，客户程序就不需要变化。这大大降低了客户程序与实现细节的耦合度。
*/
#include <iostream>

using namespace std;

//class BankWorker {
//public:
//    void saveService() {
//        cout << "saveService" << endl;
//    }
//    void payService() {
//        cout << "payService" << endl;
//    }
//    void transferService() {
//        cout << "transferService" << endl;
//    }
//};

//void doSaveBussiness(BankWorker* worker)
//{
//    worker->saveService();
//}
//
//void doPayBussiness(BankWorker* worker)
//{
//    worker->payService();
//}
//
//void doTransBussiness(BankWorker* worker)
//{
//    worker->transferService();
//}
//
//void test4()
//{
//    BankWorker bankWorker;
//
//}

class AbstractBankWorker {
public:
    virtual void doBusiness() = 0;

};

class SaveBankWorker : public AbstractBankWorker {
public:
    virtual void doBusiness() {
        cout << "办理存款业务..." << endl;
    }
};

class PayBankWorker : public AbstractBankWorker {
public:
    virtual void doBusiness() {
        cout << "办理支付业务..." << endl;
    }
};

/* 中层业务: 让它依赖于一个抽象层 */
void doNewBusiness(AbstractBankWorker* worker)
{
    worker->doBusiness();
}

void test4()
{
    SaveBankWorker saveBankWorker;
    doNewBusiness(&saveBankWorker);
}
