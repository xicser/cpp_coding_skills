#include <iostream>

using namespace std;


void swap(int * &p1, int * &p2)
{
    int *temp = p1;
    p1 = p2;
    p2 = temp;
}


int main()
{
    int a = 1, b = 2;
    int *p1 = &a, *p2 = &b;

    swap(p1, p2);

    cout << "a = " << *p1 << "\n" << "b = "  << *p2 << endl;
    return 0;
}
