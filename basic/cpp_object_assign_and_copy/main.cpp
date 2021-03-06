#include <iostream>
#include <string.h>

using namespace std;


class ClassBase
{
public:
    ClassBase() {
        cout << "ClassBase()" << endl;
    }
    ClassBase(const ClassBase &obj) {
        this->num = obj.num;
        cout << "ClassBase(const ClassBase &obj)" << endl;
    }

    int getNum(void) const {
        return num;
    }

    void setNum(int num) {
        this->num = num;
    }

private:
    int num;
};

class ClassA : public ClassBase
{
public:
    ClassA () {
        m_pszName = nullptr;
    }
    ClassA (int id, const char* name)
    {
        m_nId = id;
        m_pszName = new char[strlen(name) + 1];
        strcpy(m_pszName, name);
    }

    // 重载拷贝构造函数, 重载后的拷贝构造函数支持深拷贝
    ClassA(const ClassA &obj) : ClassBase(obj) //这里指定调用父类的拷贝构造函数
    {
        // 拷贝 stack 域的值
        m_nId = obj.m_nId;
        // 新建 heap 空间
        m_pszName = new char[strlen(obj.m_pszName) + 1];
        // 拷贝 heap 空间的内容
        if (m_pszName != nullptr)
        {
            strcpy(m_pszName, obj.m_pszName);
        }
    }

    ~ClassA ()
    {
        delete m_pszName;
    }

    // 赋值运算符重载需要返回对象的引用, 否则返回后其值立即消失
    ClassA & operator= (const ClassA &obj)
    {
        // 释放heap内存
        if (m_pszName != nullptr)
        {
            delete m_pszName;
            m_pszName = nullptr;
        }
        // 赋值stack内存的值
        this->m_nId = obj.m_nId;
        // 赋值heap内存的值
        int nLength = strlen(obj.m_pszName);
        m_pszName = new char[nLength + 1];
        strcpy(m_pszName, obj.m_pszName);

        //针对父类成员变量的深拷贝处理
        setNum(obj.getNum());

        return *this;
    }

//private:
    char *m_pszName;
    int m_nId;
};

int main()
{
    ClassA obj1(1, "liitdar");
    ClassA obj2;
    ClassA obj3(2, "wangxi");
    obj3.setNum(15);
    ClassA obj4(obj3);

    cout << obj4.m_pszName << endl;
    cout << obj4.getNum() << endl;

    obj3 = obj2 = obj1; //obj3 = obj2.operator=(obj1);

    cout << obj3.m_pszName << endl;
    cout << obj2.m_pszName << endl;
    cout << obj1.m_pszName << endl;

    return 0;
}
