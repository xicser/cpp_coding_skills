#include <iostream>
#include <fstream>
#include <string.h>
#include "stream_func.h"

using namespace std;


//get����
void testStreamFuncGet(void)
{
    //1, ����������get
    char c;
    ifstream inputfile;
    inputfile.open("./string.dat");
    while ((c = inputfile.get()) != EOF ) {
        cout << c;
    }
    cout << endl;
    inputfile.close();

    //2, ��һ��������get(char)
    inputfile.open("./string.dat");
    while (inputfile.get(c)) {
        cout << c;
    }
    cout << endl;
    inputfile.close();

    //3, ������������get
    //��
}

//getline����
void testStreamFuncGetline(void)
{
    char str[20];
    ifstream inputfile("string.dat");
    inputfile.getline(str, 20, 'x');
    cout << str << endl;
//    inputfile.getline(str, 20, '\n');
//    cout << str << endl;

    inputfile.close();
}

//put����
void testStreamFuncPut(void)
{
    //����source.dat�е����ݵ�object.dat��
    char c;
    ifstream inputfile("source.dat");
    ofstream outputfile("object.dat");
    while ((c = inputfile.get()) != EOF) {
        outputfile.put(c);
    }
    inputfile.close();
    outputfile.close();
}

//read, write����
void testStreamFuncWrite(void)
{
    char str[1024];
    strcpy(str, "Hello Xing Ping ����!");
    ofstream outputfile("object.dat");
    if (!outputfile) {
        cout << "�ļ���ʧ�ܣ�" << endl;
        return;
    }
    outputfile.write(str, strlen(str));
    outputfile.close();

    ifstream inputfile("object.dat");
    inputfile.read(str, strlen(str));
    cout << str << endl;
    inputfile.close();

}
