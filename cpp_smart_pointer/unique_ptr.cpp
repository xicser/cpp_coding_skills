#include <iostream>
#include <memory>

using namespace std;

class Monkey {
public:
    Monkey(int age, int height) : height(height) {
        this->age = age;
        cout << "construct1 Monkey" << endl;
    }
    Monkey() {
        cout << "construct2 Monkey" << endl;
    }
    ~Monkey() {
        cout << "destruct Monkey" << endl;
    }

    void monkeyBarking(void) {
        cout << "monkey_Barking" << endl;
    }

    //��ȡ����
    int getAge(void) {
        return this->age;
    }

    //��ȡ���
    int getHeight(void) {
        return this->height;
    }

private:
    int age;
    int height;
};

void test_unique_ptr(void)
{
    unique_ptr<Monkey> mptr1(new Monkey(10, 20));

    //���ܿ�������
//    unique_ptr<Monkey> mptr2(mptr1);   //���뱨��

    //���ܸ�ֵ, ��ʼ��
//    unique_ptr<Monkey> mptr3 = mptr1;  //���뱨��
//    mptr3 = mptr1;          //���뱨��

    //���ܹ����������, �е�֧��, �ͱ��뻷���й�
//    unique_ptr<Monkey> mptr4(new Monkey[3]); //����

    //�����滻����Ȩ
    unique_ptr<Monkey> mptr5 = move(mptr1); //�滻����Ȩ
    mptr1.release();                        //�ͷ�����Ȩ

    mptr5->monkeyBarking();
}
