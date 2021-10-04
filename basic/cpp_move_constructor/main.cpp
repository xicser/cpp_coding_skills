#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
/*
用对象a初始化对象b，后对象a我们就不在使用了，
但是对象a的空间还在（在析构之前），既然拷贝构造函数，
实际上就是把a对象的内容复制一份到b中，
那么为什么我们不能直接使用a的空间呢？
这样就避免了新的空间的分配，大大降低了构造的成本。
这就是移动构造函数设计的初衷。
*/

class Str
{
public:
    char *str;
    Str(char value[])
    {
        cout << "constructor..."<< endl;
        int len = strlen(value);
        str = (char *)malloc(len + 1);
        strcpy(str, value);
    }
    Str(const Str &s)
    {
        cout << "copy constructor..." << endl;
        int len = strlen(s.str);
        str = (char *)malloc(len + 1);
        strcpy(str, s.str);
    }
    Str(Str &&s)
    {
        cout << "move constructor..." << endl;
        str = s.str;
        s.str = nullptr;
    }
    ~Str()
    {
        cout << "destructor" << endl;
        if(str != nullptr) {
            free(str);
            str = nullptr;
        }
    }
};

int main()
{
    char value[] = "I love C++11";

    Str s(value);

    vector<Str> vs;

    vs.push_back(move(s));   //调用移动构造函数
    // vs.push_back(s);
    cout << vs[0].str << endl;

    if(s.str != nullptr) {
        cout << s.str << endl;
    }

    return 0;
}
