#include <iostream>
#include <fstream>
#include "stream_operator.h"

using namespace std;

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


void testInputOutputNum(void)
{
    ofstream outfile;
    outfile.open("./int.dat", ios::out);
    if (!outfile) {
        cout << "打开写入文件失败" << endl;
        return;
    }
    outfile << 123 << " " << 456 << " " << 789;
    outfile.close();

    ifstream inputfile;
    inputfile.open("./int.dat", ios::in);
    if (!inputfile) {
        cout << "打开读取文件失败" << endl;
        return;
    }
    int x, y, z;
    inputfile >> x >> y >> z;
    cout << x << y << z << endl;
    inputfile.close();
}

void testInputOutputString(void)
{
    ofstream outfile;
    outfile.open("./string.dat", ios::out);
    if (!outfile) {
        cout << "打开写入文件失败" << endl;
        return;
    }
    outfile << "Hello buddy!" << endl;
    outfile.close();

    ifstream inputfile;
    inputfile.open("./string.dat", ios::in);
    if (!inputfile) {
        cout << "打开读取文件失败" << endl;
        return;
    }
    string str1, str2;
    inputfile >> str1 >> str2;
    cout << str1 << str2 << endl;
    inputfile.close();
}

void testInputOutputObj(void)
{
    ofstream outfile;
    outfile.open("./employee.dat", ios::out);
    if (!outfile) {
        cout << "打开写入文件失败" << endl;
        return;
    }
    char ch;
    Employee employeeVar;
    employeeVar.setId();
    employeeVar.setName();
    employeeVar.setAddr();
    outfile << employeeVar.getId() << " " << employeeVar.getName() << " " << employeeVar.getAddr();
    outfile.close();

    cout << "\n是否查看文件内容(y/n)";
    cin >> ch;
    if (ch == 'y') {
        ifstream inputfile;
        inputfile.open("./employee.dat", ios::in);
        if (!inputfile) {
            cout << "打开读取文件失败" << endl;
            return;
        }
        int id;
        string name;
        string addr;
        inputfile >> id >> name >> addr;
        cout << id << name << addr << endl;
        inputfile.close();
    }
}

