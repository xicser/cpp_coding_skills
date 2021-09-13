#include <iostream>

using namespace std;

template<typename T>
void mySwap(T &x1, T &x2)
{
    T temp;
    temp = x1;
    x1 = x2;
    x2 = temp;
}

template<typename T>
T myMin(T a[], int n)
{
    T min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

template<typename T>
T myMax(T a, T b)
{
    return a > b ? a : b;
}

template<typename T1, typename T2>
void fun(T1 a, T2 b, int x)
{
    cout << a << ", " << b << ", " << x << endl;
}


void testFuncTemplate(void)
{
    char c1 = 'a', c2 = 'b';
    int i1 = 10, i2 = 20;
    double d1 = 1.23, d2 = 3.21;
    cout << "c1 = " << c1 << ", c2 = " << c2 << endl;
    cout << "i1 = " << i1 << ", i2 = " << i2 << endl;
    cout << "d1 = " << d1 << ", d2 = " << d2 << endl;

    mySwap(c1, c2);
    mySwap(i1, i2);
    mySwap(d1, d2);

    cout << "c1 = " << c1 << ", c2 = " << c2 << endl;
    cout << "i1 = " << i1 << ", i2 = " << i2 << endl;
    cout << "d1 = " << d1 << ", d2 = " << d2 << endl;

    int a[] = {1, 2, 23, 4, 0, 89};
    double b[] = {1.2, -3.4, 6.8, 9, 8};

    cout << myMin(a, sizeof(a) / sizeof(int)) << endl;
    cout << myMin(b, sizeof(b) / sizeof(double)) << endl;

    cout << myMax(1.2, 5.6) << endl;
    //cout << myMax(3, 5.6) << endl; //编译报错

    fun(3, 4, 5);
}
