/*
auto_ptr������
*/

#include <iostream>
#include <memory>

using namespace std;

class Tiger {
public:
    Tiger(int age, int height) : height(height) {
        this->age = age;
        cout << "construct1 Tiger" << endl;
    }
    Tiger() {
        cout << "construct2 Tiger" << endl;
    }
    ~Tiger() {
        cout << "destruct Tiger" << endl;
    }

    void tigerBarking(void) {
        cout << "tiger_Barking" << endl;
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

void test_auto_ptr(void)
{
    auto_ptr<Tiger> tptr1(new Tiger(10, 20));

    //һ������ָ�����ֻ�ܹ���һ������
    //���ܸ�ֵ, ���ܳ�ʼ����һ������ָ��
    //��ֵ, ��ʼ���ᵼ��ԭ��������ָ��ʧЧ
//    auto_ptr<Tiger> tptr2 = tptr1;
//    tptr1->tigerBarking();
//    tptr2->tigerBarking();

//    auto_ptr<Tiger> tptr3;
//    tptr3 = tptr1;          //���ܸ�ֵ
//    tptr3->tigerBarking();


    //ֻ�ܹ���һ������, ���ܹ����������
    auto_ptr<Tiger> tptr4(new Tiger[3] {Tiger(12, 23), Tiger(23, 34), Tiger(45, 56)}); //����
}
