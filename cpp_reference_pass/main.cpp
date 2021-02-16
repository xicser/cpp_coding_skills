#include <iostream>
#include <string>

using namespace std;


typedef struct {
    int id;
    string name;
} Student_t;

Student_t *pStudent;

void init(void)
{
    pStudent = new Student_t;
    pStudent->id = 9;
    pStudent->name = "zhang san";
}

Student_t *&getStudent(void)
{
    return pStudent;
}

class TestSub
{
public:
    TestSub(Student_t *&student) : studentSub(student)
    {

    }
    Student_t *&studentSub;
};

class Test
{
public:
    Test(Student_t *&student) : student(student)
    {
        testsub = new TestSub(this->student);
    }
    ~Test() {
        delete testsub;
    }

    void deleteNewStu(void) {
        delete student;
        student = new Student_t;
        student->id = 9999;
        student->name = "sha bi";
    }

    Student_t *&student;

    TestSub *testsub;
};


int main()
{
    init();
    cout << pStudent->id << " " << pStudent->name << endl;


    Student_t *&stu = getStudent();
    stu->id = 99;
    stu->name = "li si";
    cout << pStudent->id << " " << pStudent->name << endl;


    Test *test = new Test(stu);
    test->student->id = 999;
    test->student->name = "wang wu";
    cout << pStudent->id << " " << pStudent->name << endl;


    test->deleteNewStu();
    cout << pStudent->id << " " << pStudent->name << endl;


    test->testsub->studentSub->id = 99999;
    test->testsub->studentSub->name = "er qiu";
    cout << pStudent->id << " " << pStudent->name << endl;

    delete test;
    return 0;
}
