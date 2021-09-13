#ifndef __BINARY_OPERATOR_FRIEND_H__
#define __BINARY_OPERATOR_FRIEND_H__

class Complex {
private:
    double real;        //实部
    double imag;        //虚部

public:
    Complex();
    Complex(double r, double i);

    void display();

    friend Complex operator+(const Complex &c1, const Complex &c2);     //重载加法运算符
};



#endif // __BINARY_OPERATOR_FRIEND_H__
