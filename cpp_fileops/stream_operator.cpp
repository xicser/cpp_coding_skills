#include <iostream>
#include <fstream>
#include "stream_operator.h"
#include "Employee.h"

using namespace std;

void testStreamOperatorNum(void)
{
    ofstream outfile;
    outfile.open("./int.dat", ios::out);
    if (!outfile) {
        cout << "��д���ļ�ʧ��" << endl;
        return;
    }
    outfile << 123 << " " << 456 << " " << 789;
    outfile.close();

    ifstream inputfile;
    inputfile.open("./int.dat", ios::in);
    if (!inputfile) {
        cout << "�򿪶�ȡ�ļ�ʧ��" << endl;
        return;
    }
    int x, y, z;
    inputfile >> x >> y >> z;
    cout << x << y << z << endl;
    inputfile.close();
}

void testStreamOperatorString(void)
{
    ofstream outfile;
    outfile.open("./string.dat", ios::out);
    if (!outfile) {
        cout << "��д���ļ�ʧ��" << endl;
        return;
    }
    outfile << "Hello buddy!";
    outfile.close();

    ifstream inputfile;
    inputfile.open("./string.dat", ios::in);
    if (!inputfile) {
        cout << "�򿪶�ȡ�ļ�ʧ��" << endl;
        return;
    }
    string str1, str2;
    inputfile >> str1 >> str2;
    cout << str1 << str2 << endl;
    inputfile.close();
}

void testStreamOperatorObj(void)
{
    ofstream outfile;
    outfile.open("./employee.dat", ios::out);
    if (!outfile) {
        cout << "��д���ļ�ʧ��" << endl;
        return;
    }
    char ch;
    Employee employeeVar;
    employeeVar.setId();
    employeeVar.setName();
    employeeVar.setAddr();
    outfile << employeeVar.getId() << " " << employeeVar.getName() << " " << employeeVar.getAddr();
    outfile.close();

    cout << "\n�Ƿ�鿴�ļ�����(y/n)";
    cin >> ch;
    if (ch == 'y') {
        ifstream inputfile;
        inputfile.open("./employee.dat", ios::in);
        if (!inputfile) {
            cout << "�򿪶�ȡ�ļ�ʧ��" << endl;
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

