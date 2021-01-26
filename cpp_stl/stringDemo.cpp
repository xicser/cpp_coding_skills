#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


void stringDemo(void)
{
    printf("**************************string test****************************\n");

    string str = "wang";

    //输入输出
    string str2;
    cin >> str2;
    cout << str2 << endl;
    printf("%s\n", str2.c_str());

    //元素访问
    //通过下标
    for (int i = 0; i < str.length(); i++) {
        printf("%c ", str[i]);
    }
    printf("\n");
    //通过迭代器
    for (string::iterator it = str.begin(); it != str.end(); it++) {
        printf("%c ",  *it);
    }
    printf("\n");

    //拼接
    cout << str + str2 << endl;

    //比较, 按照字典序, 和strcmp类似
    cout << (str > str2) << endl;

    //长度
    printf("%d\n", str.length());
    printf("%d\n", str.size());

    //插入
    str.insert(str.begin() + 1, str2.begin(), str2.end());
    cout << str << endl;
    str.insert(3, str2);
    cout << str << endl;

    //erase
    str = "qwer";
    str.erase(str.begin() + 1);
    cout << str << endl;
    str = "qwer99999";
    str.erase(str.begin() + 4, str.end());
    cout << str << endl;
    str = "asdf99999";
    str.erase(4, 5);
    cout << str << endl;

    //clear
    str.clear();
    cout << str.size() << endl;

    //substr()返回子串
    str = "123456";
    cout << str.substr(1, 2) << endl;

    //find和string::nops
    str = "Thank you for your smile.";
    str2 = "you";
    string str3 = "me";
    if (str.find(str2) != string::npos) {
        cout << "pos = " << str.find(str2) << endl;
    }
    if (str.find(str2, 7) != string::npos) {
        cout << "pos = " << str.find(str2, 7) << endl;
    }
    if (str.find(str3) != string::npos) {
        cout << "pos = " << str.find(str2, 7) << endl;
    } else {
        cout << "I know there is no position for me." << endl;
    }

    //replace
    str = "Maybe you will turn around.";
    str2 = "will not";
    str3 = "surely";
    cout << str.replace(10, 4, str2) << endl;
    cout << str.replace(str.begin(), str.begin() + 5, str3) << endl;


}
