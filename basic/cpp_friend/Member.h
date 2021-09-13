#ifndef __MEMBER_H__
#define __MEMBER_H__

class Student;
class Teacher {
private:
    int bh;
    char name[10];

public:
    Teacher(int h, char n[]);
    void display();
    void modify_stu(Student &, float); //Student的友元函数
};

class Student {
private:
    int id;
    float score;

public:
    Student(int xh, float s);
    void display();

    //把Teacher类中的modify_stu函数作为本类的友元函数
    friend void Teacher::modify_stu(Student &, float);
};






#endif // __MEMBER_H__
