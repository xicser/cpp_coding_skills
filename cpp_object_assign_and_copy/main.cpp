#include <iostream>
#include <string.h>

using namespace std;

class ClassA
{
public:
    ClassA()
    {
        cout << "ClassA" << endl;
    }

    ClassA(int id, char* name)
    {
        cout << "ClassA" << endl;
        m_nId = id;
        m_pszName = new char[strlen(name) + 1];
        strcpy(m_pszName, name);
    }

    ~ClassA()
    {
        delete m_pszName;
    }
private:
    char* m_pszName;
    int m_nId;
};


int main()
{
    ClassA obj1(1, "liitdar");
    ClassA obj2;

    obj2 = obj1;

    return 0;
}
