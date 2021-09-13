#include <iostream>
#include <utility>
#include <map>
#include <stdio.h>

using namespace std;

void pairDemo(void)
{
    printf("**************************pair test****************************\n");

    //定义
    pair<string, int> p1("haha", 5);
    pair<string, int> p2;
    p2 = make_pair("wang", 8);

    //元素访问
    printf("%s %d\n", p1.first.c_str(), p1.second);
    printf("%s %d\n", p2.first.c_str(), p2.second);

    //常用函数
    pair<int, int> p_1(5, 10);
    pair<int, int> p_2(5, 15);
    pair<int, int> p_3(10, 5);
    if (p_1 < p_3) printf("p1 < p3\n");
    if (p_1 <= p_3) printf("p1 <= p3\n");
    if (p_1 < p_2) printf("p1 < p2\n");

    //用途demo
    map<string, int> mp;
    mp.insert(make_pair("wangxi", 5));
    mp.insert(pair<string, int>("haha", 10));
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}
