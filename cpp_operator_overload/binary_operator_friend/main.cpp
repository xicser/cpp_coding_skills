#include <iostream>
#include "binary_operator_friend.h"

using namespace std;

int main()
{
    Complex c, c1(3, 5), c2(-5, 6);
    c = c1 + c2;  //被解释为c = operator+(c1, c2);
    c1.display();
    c2.display();
    c.display();

    return 0;
}
