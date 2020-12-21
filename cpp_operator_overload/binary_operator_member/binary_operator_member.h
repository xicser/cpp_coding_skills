#ifndef __BINARY_OPERATOR_MEMBER_H__
#define __BINARY_OPERATOR_MEMBER_H__

class Complex {
private:
    double real;        //实部
    double imag;        //虚部

public:
    Complex();
    Complex(double r, double i);

    void display();

    Complex operator+ (Complex c2);     //重载加法运算符
};

#endif // __BINARY_OPERATOR_MEMBER_H__
