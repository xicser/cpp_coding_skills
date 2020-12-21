/* 双目运算符重载为类的友元函数 */

#include <iostream>
#include "binary_operator_friend.h"

using namespace std;

Complex::Complex()
{

}
Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
}

void Complex::display()
{
    cout << "(" << real << "," << imag << ")" << endl;
}

//重载加法运算符
Complex operator+(Complex c1, Complex c2)
{
    Complex c;
    c.real = c1.real + c2.real;
    c.imag = c1.imag + c2.imag;
    return c;
}
