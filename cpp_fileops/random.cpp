#include <iostream>
#include <fstream>
#include "random.h"
#include "Employee.h"

using namespace std;


void testRandom(void)
{
    Employee eVar1;
    Employee eVar2(1000, "����", "�ӱ�");
    Employee eVar3(1001, "����", "����");
    Employee eVar4(1002, "����", "ɽ��");
    Employee eVar5(1003, "����", "�Ĵ�");
    Employee eVar6(1004, "����", "����");

    ofstream ofile("employee.dat", ios::trunc | ios::binary);
    if (!ofile) {
        cout << "�ļ�����ʧ�ܣ�" << endl;
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
        cout << "�ļ���ʧ�ܣ�" << endl;
        return;
    }
    ifile.seekg(0, ios::beg);
    int id;
    cout << "�����ѯ��Ա���: ";
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
        cout << "\n�޴˱�Ź�Ա��" << endl;
    }
}
