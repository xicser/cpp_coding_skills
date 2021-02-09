#include <iostream>
#include <memory>

using namespace std;


class Dog {

};

int main()
{
    auto_ptr<Dog> pDog(new Dog());
    auto_ptr<double> pd(new double);

    *pd = 100.45;
    cout << *pd;

    return 0;
}
