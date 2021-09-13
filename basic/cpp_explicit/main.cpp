#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class CxString1  // 没有使用explicit关键字的类声明, 即默认为隐式声明
{
public:
    char *_pstr;
    int _size;
    CxString1(int size)
    {
        printf("CxString1(int size)\n");

        _size = size;                // string的预设大小
        _pstr = static_cast<char *>(malloc(size + 1));    // 分配string的内存
        memset(_pstr, 0, size + 1);
    }
    CxString1(const char *p)
    {
        printf("CxString1(const char *p)\n");

        int size = strlen(p);
        _pstr = static_cast<char *>(malloc(size + 1));    // 分配string的内存
        strcpy(_pstr, p);            // 复制字符串
        _size = strlen(_pstr);
    }
};

class CxString2  // 使用关键字explicit的类声明, 显示转换
{
public:
    char *_pstr;
    int _size;
    explicit CxString2(int size)
    {
        _size = size;
    }
    CxString2(const char *p)
    {
    }
};

/*
当除了第一个参数以外的其他参数都有默认值的时候,
explicit关键字依然有效, 此时, 当调用构造函数时只传入一个参数,
等效于只有一个参数的类构造函数
*/

class CxString3  // 使用关键字explicit声明
{
public:
    int _age;
    int _size;
    explicit CxString3(int age, int size = 8)
    {
        _age = age;
        _size = size;
    }
    CxString3(const char *p)
    {
    }
};

void testCxString1(void)
{
    CxString1 string1(24);     // 这样是OK的, 为CxString预分配24字节的大小的内存
    CxString1 string2 = 10;    // 这样是OK的, 为CxString预分配10字节的大小的内存
    // CxString1 string3;         // 这样是不行的, 因为没有默认构造函数, 错误为: "CxString1": 没有合适的默认构造函数可用
    CxString1 string4("aaaa"); // 这样是OK的
    CxString1 string5 = "bbb"; // 这样也是OK的, 调用的是CxString1(const char *p)
    CxString1 string6 = 'c';   // 这样也是OK的, 其实调用的是CxString(int size), 且size等于'c'的ascii码
    string1 = 2;              // 这样也是OK的, 为CxString预分配2字节的大小的内存
    string2 = 3;              // 这样也是OK的, 为CxString预分配3字节的大小的内存
    string2 = "123";
    printf("%s\n", string2);
}

void testCxString2(void)
{
    CxString2 string1(24);     // 这样是OK的
    // CxString2 string2 = 10;    // 这样是不行的, 因为explicit关键字取消了隐式转换
    CxString2 string4("aaaa"); // 这样是OK的
    CxString2 string5 = "bbb"; // 这样也是OK的, 调用的是CxString(const char *p)
//    CxString2 string6 = 'c';   // 这样是不行的, 其实调用的是CxString(int size), 且size等于'c'的ascii码, 但explicit关键字取消了隐式转换
//    string1 = 2;               // 这样也是不行的
    string4 = string5;         // 这样是OK的
}

void testCxString3(void)
{
    CxString3 string1(24);    // 这样是OK的
//    CxString3 string2 = 10;   // 这样是不行的, 因为explicit关键字取消了隐式转换
//    printf("%d %d\n", string2._age, string2._size);

//    string1 = 2;              // 这样也是不行的, 因为取消了隐式转换
//    string2 = 3;              // 这样也是不行的, 因为取消了隐式转换
//    string1 = string2;        // 这样是OK的
}


int main()
{
    //testCxString1();
    //testCxString2();
    testCxString3();

    return 0;
}
