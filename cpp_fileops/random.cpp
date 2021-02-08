#include <iostream>
#include <fstream>
#include "random.h"
#include "Employee.h"

using namespace std;


void testRandom(void)
{
    Employee eVar1;
    Employee eVar2(1000, "张三", "河北");
    Employee eVar3(1001, "李四", "河南");
    Employee eVar4(1002, "王五", "山西");
    Employee eVar5(1003, "马六", "四川");
    Employee eVar6(1004, "田七", "西藏");

    ofstream ofile("employee.dat", ios::trunc | ios::binary);
    if (!ofile) {
        cout << "文件创建失败！" << endl;
        return;
    }
    ofile.seekp(0, ios::beg);
    ofile.write((char *)&eVar2, sizeof(Employee));
    ofile.write((char *)&eVar3, sizeof(Employee));
    ofile.write((char *)&eVar4, sizeof(Employee));
    ofile.write((char *)&eVar5, sizeof(Employee));
    ofile.write((char *)&eVar6, sizeof(Employee));
    ofile.close();

    ifstream ifile("employee.dat", ios::binary);
    if (!ifile) {
        cout << "文件打开失败！" << endl;
        return;
    }
    ifile.seekg(0, ios::beg);
    int id;
    cout << "输入查询雇员编号: ";
    cin >> id;
    int i;
    for (i = 0; i < 5; i++) {
        ifile.read((char *)&eVar1, sizeof(Employee));
        if (eVar1.isFound(id) == true) {
            eVar1.diaplay();
            break;
        }
    }
    ifile.close();

    if (i == 5) {
        cout << "\n无此编号雇员！" << endl;
    }
}
