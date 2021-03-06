#include <iostream>
#include <set>
#include <stdio.h>

using namespace std;

class Student {
private:
    int age;
    int grade;

public:
    Student(int age, int grade) {
        this->age = age;
        this->grade = grade;
    }

    int getAge() const {
        return age;
    }
    int getGrade() const {
        return grade;
    }

    bool operator< (const Student& s) const
    {
        return this->getAge() < s.getAge();
    }
};

void setDemo(void)
{
    printf("**************************set test****************************\n");

    ////定义
    //set<int> name;

    ////插入元素
    ////重复元素不起作用, 因为set是集合, 没有重复元素
    ////并且自动增序排列
    //name.insert(4);
    //name.insert(5);
    //name.insert(6);
    //name.insert(7);
    //name.insert(8);
    //name.insert(9);
    //name.insert(10);
    //name.insert(3);
    //name.insert(3);

    ////元素访问: 只能通过迭代器访问
    //for (set<int>::iterator it = name.begin(); it != name.end(); it++) {
    //    printf("%d ", *it);
    //}
    //printf("\n");

    ////find, erase
    //set<int>::iterator it = name.find(4);
    //printf("%d\n", *it);
    //name.erase(it);
    //for (set<int>::iterator it = name.begin(); it != name.end(); it++) {
    //    printf("%d ", *it);
    //}
    //printf("\n");

    //name.erase(9);
    //for (set<int>::iterator it = name.begin(); it != name.end(); it++) {
    //    printf("%d ", *it);
    //}
    //printf("\n");

    //name.erase(name.find(5), name.end());
    //for (set<int>::iterator it = name.begin(); it != name.end(); it++) {
    //    printf("%d ", *it);
    //}
    //printf("\n");


    /* 自定义顺序 */
    set<Student> aSet;
    aSet.insert(Student(76, 99));
    aSet.insert(Student(32, 99));
    aSet.insert(Student(54, 99));
    aSet.insert(Student(10, 99));
    aSet.insert(Student(12, 99));

    for (const auto& it : aSet) {
        cout << it.getAge() << endl;
    }
}

