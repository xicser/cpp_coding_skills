#include <iostream>
#include <string.h>

using namespace std;

class ClassA
{
public:
    ClassA ()
    {

    }
    ClassA (int id, const char* name)
    {
        m_nId = id;
        m_pszName = new char[strlen(name) + 1];
        strcpy(m_pszName, name);
    }

    ~ClassA ()
    {
        delete m_pszName;
    }

    // 赋值运算符重载需要返回对象的引用, 否则返回后其值立即消失
    ClassA & operator= (const ClassA &obj)
    {
        // 释放heap内存
        if (m_pszName != NULL)
        {
            delete m_pszName;
        }
        // 赋值stack内存的值
        this->m_nId = obj.m_nId;
        // 赋值heap内存的值
        int nLength = strlen(obj.m_pszName);
        m_pszName = new char[nLength + 1];
        strcpy(m_pszName, obj.m_pszName);

        return *this;
    }

//private:
    char *m_pszName;
    int m_nId;
};

const ClassA & test(void)
{
    ClassA *retA = new ClassA();
    return *retA;
}

int main()
{
    ClassA obj1(1, "liitdar");
    ClassA obj2;
    ClassA obj3;

    const ClassA &temp = test();

    obj3
    = obj2
    = obj1; //obj3 = obj2.operator=(obj1);

    cout << obj3.m_pszName << endl;
    cout << obj2.m_pszName << endl;
    cout << obj1.m_pszName << endl;

    return 0;
}
