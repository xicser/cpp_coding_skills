#include <iostream>
#include <math.h>
#include "Normal.h"
#include "Member.h"

using namespace std;

int main()
{
    Point p(3, 5);
    Line l(4, 5, 6);
    cout << dist(p, l) << endl;

    cout << endl;

    Teacher t1(1000, "wanglin");
    Student c(1022, 67);
    c.display();
    t1.modify_stu(c, 89);
    c.display();

    return 0;
}

