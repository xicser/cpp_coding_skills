#include <iostream>
#include "Employee.h"

using namespace std;


Employee::Employee()
{

}

Employee::Employee(int id, string name, string addr)
{
    this->id = id;
    this->name = name;
    this->addr = addr;
}
void Employee::diaplay(void)
{
    cout << "\n雇员编号: " << id << "\n雇员姓名: " << name << "\n雇员地址: " << addr << endl;
}
bool Employee::isFound(int id)
{
    if (this->id == id) {
        return true;
    }
    return false;
}

void Employee::setId(void)
{
    cout << "\n输入雇员编号：";
    cin >> id;
}

void Employee::setName(void)
{
    cout << "\n输入雇员姓名：";
    cin >> name;
}

void Employee::setAddr(void)
{
    cout << "\n输入雇员地址：";
    cin >> addr;
}

int Employee::getId(void)
{
    return id;
}

string Employee::getName(void)
{
    return name;
}

string Employee::getAddr(void)
{
    return addr;
}
