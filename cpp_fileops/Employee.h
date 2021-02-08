#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <string>

using namespace std;

class Employee
{
private:
    int id;
    string name;
    string addr;

public:
    Employee();
    Employee(int, string, string);

    void setId(void);
    void setName(void);
    void setAddr(void);
    int getId(void);
    string getName(void);
    string getAddr(void);
    void diaplay(void);
    bool isFound(int id);
};

#endif // __EMPLOYEE_H__

