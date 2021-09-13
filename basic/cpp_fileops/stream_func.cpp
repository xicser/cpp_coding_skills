#include <iostream>
#include <fstream>
#include <string.h>
#include "stream_func.h"

using namespace std;


//get函数
void testStreamFuncGet(void)
{
    //1, 不带参数的get
    char c;
    ifstream inputfile;
    inputfile.open("./string.dat");
    while ((c = inputfile.get()) != EOF ) {
        cout << c;
    }
    cout << endl;
    inputfile.close();

    //2, 带一个参数的get(char)
    inputfile.open("./string.dat");
    while (inputfile.get(c)) {
        cout << c;
    }
    cout << endl;
    inputfile.close();

    //3, 带三个参数的get
    //略
}

//getline函数
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

//put函数
void testStreamFuncPut(void)
{
    //复制source.dat中的内容到object.dat中
    char c;
    ifstream inputfile("source.dat");
    ofstream outputfile("object.dat");
    while ((c = inputfile.get()) != EOF) {
        outputfile.put(c);
    }
    inputfile.close();
    outputfile.close();
}

//read, write函数
void testStreamFuncWrite(void)
{
    char str[1024];
    strcpy(str, "Hello Xing Ping 王熙!");
    ofstream outputfile("object.dat");
    if (!outputfile) {
        cout << "文件打开失败！" << endl;
        return;
    }
    outputfile.write(str, strlen(str));
    outputfile.close();

    ifstream inputfile("object.dat");
    inputfile.read(str, strlen(str));
    cout << str << endl;
    inputfile.close();

}
