/*
线性表类模板
*/

#include <iostream>

using namespace std;

const int Maxsize = 100;

template<typename T>
class SwqList
{
private:
    T data[Maxsize];
    int length;

public:
    void init();
    bool Insert(int, T);
    bool Delete(int);
    void Display() {
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

template<typename T>
void SwqList<T>::init()
{
    length = 0;
}

template<typename T>
bool SwqList<T>::Insert(int i, T e)
{
    if (length == Maxsize) return false;
    if (i < 1 || i > length + 1) return false;
    for (int j = length - 1; j > i; j--) {
        data[j + 1] = data[j];
    }
    data[i - 1] = e;
    length++;

    return true;
}

template<typename T>
bool SwqList<T>::Delete(int i)
{
    if (length == 0) return false;
    if (i < 1 || i > length) return false;
    for (int j = i; j < length; j++) {
        data[j - 1] = data[j];
    }
    length--;

    return true;
}

void testListTemplate(void)
{
    SwqList<int> s1;
    s1.init();
    s1.Insert(1, 4);
    s1.Insert(2, 6);
    s1.Insert(3, 8);
    s1.Insert(4, 2);
    s1.Display();
    s1.Delete(1);
    s1.Delete(3);
    s1.Display();

    SwqList<double> s2;
    s2.init();
    s2.Insert(1, 4.5);
    s2.Insert(2, 6.4);
    s2.Insert(3, 8.5);
    s2.Insert(4, 2.9);
    s2.Display();
    s2.Delete(1);
    s2.Delete(3);
    s2.Display();
}
