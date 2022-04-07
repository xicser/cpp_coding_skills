#include <iostream>

using namespace std;

// ���ر����ú���, �鿴����ת����Ч��
void otherdef(int& t)
{
    cout << "lvalue\n";
}
void otherdef(const int& t)
{
    cout << "rvalue\n";
}

// ʵ������ת���ĺ���ģ��
template <typename T>
void func(T&& t)
{
    otherdef(forward<T>(t)); //����ת��
}

void test_forward()
{
    func(5);
    int x = 1;
    func(x);
}

//����ִ�н��Ϊ��

//rvalue
//lvalue
