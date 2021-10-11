#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/*
������ʽ                ˵��
[]               �������κ��ⲿ����
[������, ��]         Ĭ����ֵ����ʽ����ָ���Ķ���ⲿ�������ö��ŷָ�����������ò�����Ҫ��ʾ������ʹ��&˵������
[this]           ��ֵ����ʽ����thisָ��
[=]              ��ֵ����ʽ���������ⲿ����
[&]              ��������ʽ���������ⲿ����
[=, &x]          ����x��������ʽ������������Դ�ֵ��ʽ����
[&, x]           ����x��ֵ����ʽ�������������������ʽ����

Lambda���ʽ������������ʽ���£�
[capture list] (params list) mutable exception-> return type { function body }
���ӣ�
auto f = []() -> int {
    return 4;
};

[capture list] (params list) -> return type {function body}
[capture list] (params list) {function body}
[capture list] {function body}

��Lambda���ʽ�д��ݲ�������һЩ���ƣ���Ҫ�����¼��㣺
�����б��в�����Ĭ�ϲ���
��֧�ֿɱ����
���в��������в�����

*/

void test1()
{
    vector<int> lbvec{ 3, 2, 5, 7, 3, 2 };

    sort(lbvec.begin(), lbvec.end(), [](int a, int b) -> bool { return a < b; });   // Lambda���ʽ
    cout << "lambda expression:" << endl;
    for (int it : lbvec)
        cout << it << ' ';
}

void test2()
{
    int a = 123;
    auto f = [a] { cout << a << endl; };
    f(); // �����123

    //��ͨ���������塱����ġ�()���������
    [](int a){cout << a << endl;}(123);
}

void test3()
{
    int a = 123;
    auto f = [a] { cout << a << endl; };
    a = 321;
    f(); // �����123
}

void test4()
{
    int a = 123;
    auto f = [&a] { cout << a << endl; };
    a = 321;
    f(); // �����321
}

void test5()
{
    int a = 123;
    auto f = [=] { cout << a << endl; };      // ֵ����
//    auto f = [=] { cout << a << endl; };    // ���ò���
    f(); // �����123
}

void test6()
{
    int a = 123;
    auto f = [a]()mutable { cout << ++a << endl; }; // ���ᱨ��, ����mutable�ᱨ��
    cout << a << endl; // �����123
    f(); // �����124
    cout << a << endl; // �����123
}

void test7()
{
    int m = [](int x) {
        return [](int y) { return y * 2; }(x) + 6;
    }(5);
    std::cout << "m:" << m << std::endl;    //���16

    std::cout << "n:" << [](int x, int y) { return x + y; }(5, 4) << std::endl;            //���9

    auto gFunc = [](int x) -> function<int(int)> { return [=](int y) { return x + y; }; };
    auto lFunc = gFunc(4);
    std::cout << lFunc(5) << std::endl;

    auto hFunc = [](const function<int(int)>& f, int z) { return f(z) + 1; };
    cout << hFunc(gFunc(7), 8) << endl;
}

void test8()
{
    int a = 111, b = 222;
    auto func = [=, &b]()mutable { a = 22; b = 333; std::cout << "a:" << a << " b:" << b << std::endl; };
    func();
    std::cout << "a:" << a << " b:" << b << std::endl;

    a = 333;
    auto func2 = [=, &a] { a = 444; std::cout << "a:" << a << " b:" << b << std::endl; };
    func2();

    auto func3 = [](int x) -> function<int(int)> {
        return [=](int y) {
            return x + y;
        };
    };
    cout << func3(11)(15) << endl;

    std::function<void(int)> f_display_42 = [](int x) { cout << x << endl; };
    f_display_42(44);
}

int main()
{
//    test2();
//    test6();

//    test7();
    test8();

}
