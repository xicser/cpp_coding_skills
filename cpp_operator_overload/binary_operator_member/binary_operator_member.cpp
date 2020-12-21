/* 双目运算符重载为类的成员函数 */

#include <iostream>
#include "binary_operator_member.h"

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
Complex Complex::operator+(Complex c2)
{
    Complex c;
    c.real = this->real + c2.real;
    c.imag = this->imag + c2.imag;
    return c;
}
