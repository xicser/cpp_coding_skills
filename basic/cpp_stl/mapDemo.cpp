#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;


class Person {
private:
    int age;
    int grade;

public:
    Person(int age, int grade) {
        this->age = age;
        this->grade = grade;
    }

    int getAge() const {
        return age;
    }
    int getGrade() const {
        return grade;
    }

    /* 自定义key的排序规则 */
    bool operator< (const Person& s) const
    {
        return this->getAge() < s.getAge();
    }
};

void mapDemo(void)
{
    printf("**************************map test****************************\n");

    //定义
    map<char, int> mp;

    //元素访问
    //通过下标
    mp['c'] = 20;
    mp['d'] = 30;
    mp['b'] = 20;
    mp['c'] = 30;   //20被覆盖
    mp['a'] = 10;
    printf("%d\n", mp['c']);
    //通过迭代器, map会以键从小到大的顺序自动排序
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        printf("%c %d\n", it->first, it->second);
    }
    printf("\n");

    //find
    map<char, int>::iterator it = mp.find('d');
    printf("%c %d\n", it->first, it->second);
    printf("\n");

    //erase
    it = mp.find('b');
    mp.erase(it);
    mp.erase('a');
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        printf("%c %d\n", it->first, it->second);
    }
    printf("\n");
    mp.clear();
    mp['c'] = 20;
    mp['d'] = 30;
    mp['b'] = 20;
    mp['a'] = 10;
    mp.erase(mp.find('b'), mp.end());
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        printf("%c %d\n", it->first, it->second);
    }

    /* 自定义顺序 */
    map<Person, int> aSet;

}
