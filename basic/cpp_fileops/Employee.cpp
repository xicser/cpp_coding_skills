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
    cout << "\n��Ա���: " << id << "\n��Ա����: " << name << "\n��Ա��ַ: " << addr << endl;
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
    cout << "\n�����Ա��ţ�";
    cin >> id;
}

void Employee::setName(void)
{
    cout << "\n�����Ա������";
    cin >> name;
}

void Employee::setAddr(void)
{
    cout << "\n�����Ա��ַ��";
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
