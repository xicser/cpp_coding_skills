/* 成员函数作为友元函数 */
#include <iostream>
#include <math.h>
#include <string.h>
#include "Member.h"

using namespace std;

Teacher::Teacher(int h, char n[])
{
    bh = h;
    strcpy(name, n);
}
void Teacher::display()
{
    cout << "bh:" << bh << endl;
    cout << "name:" << name << endl;
}

//Student的友元函数
void Teacher::modify_stu(Student &stu, float score)
{
    //可以直接访问Student类的私有成员
    stu.score = score;
}



Student::Student(int xh, float s)
{
    id = xh;
    score = s;
}
void Student::display()
{
    cout << "id:" << id << endl;
    cout << "score:" << score << endl;
}

