/*
��������ԭ��
�ϲ�ģ�鲻Ӧ���������²�ģ�飬���ǹ�ͬ������һ������㣬�������಻���������࣬���Ƕ�Ҫ���������ࡣ
�����������ھ��壬����Ӧ��Ҫ�����ڳ���
һ������³���ı仯���ʺ�С�����û����������ڳ���ʵ�ֵ�ϸ��Ҳ�����ڳ��󡣼�ʹʵ��ϸ�ڲ��ϱ䶯��ֻҪ���󲻱䣬�ͻ�����Ͳ���Ҫ�仯�����󽵵��˿ͻ�������ʵ��ϸ�ڵ���϶ȡ�
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
        cout << "������ҵ��..." << endl;
    }
};

class PayBankWorker : public AbstractBankWorker {
public:
    virtual void doBusiness() {
        cout << "����֧��ҵ��..." << endl;
    }
};

/* �в�ҵ��: ����������һ������� */
void doNewBusiness(AbstractBankWorker* worker)
{
    worker->doBusiness();
}

void test4()
{
    SaveBankWorker saveBankWorker;
    doNewBusiness(&saveBankWorker);
}
