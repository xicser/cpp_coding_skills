/*
vector����һ�䳤����

3�� resize() �� reserve()
resize()���ı䵱ǰ�����ں���Ԫ�ص�����(size())��?��������������
1. ��resize(len)��len>v.capacity()���������е�size��capacity���������𣿴�����֤�������������ģ�������Ϊlen;
2. ��resize(len)��len<=v.capacity()���������е�size����Ϊlen��?capacity����;

reserve()���ı䵱ǰ��������?������capacity��
1. ���reserve(len)��ֵ > ��ǰ��capacity()����ô�����·���?���ܴ�len������Ŀռ䣬Ȼ���֮ǰ�Ķ���ͨ
��copy construtor���ƹ���������֮ǰ���ڴ�;
2. ��reserve(len)��len<=��ǰ��capacity()���������е�capacity���䣬 size���䣬�������������κθı䡣

*/

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

void vectorDemo(void)
{
    printf("**************************vector test****************************\n");

    //����
    vector<int> name1;
    vector< vector<int> > name2;
    vector<int> Arrayname[100];

    //push_back��ĩβ���Ԫ��
    for (int i = 0; i < 5; i++) {
        name1.push_back(i);
    }

    //Ԫ�ط���
    vector<int>::iterator it;
    it = name1.begin();
    for (int i = 0; i < 5; i++) {
        printf("%d ", name1[i]);         //1ͨ���±�[]����, ������һ��
        printf("%d\n", *(it + i));       //2ͨ������������
    }
    printf("\n"); //name1.end()��βԪ�ص���һ����ַ
    for (vector<int>::iterator it = name1.begin(); it != name1.end(); it++) {
        printf("%d", *it);
    }

    //pop_backɾ��β��Ԫ��
    name1.pop_back();
    printf("\n"); //name1.end()��βԪ�ص���һ����ַ
    for (vector<int>::iterator it = name1.begin(); it != name1.end(); it++) {
        printf("%d", *it);
    }
    printf("\n");

    //size()��ȡԪ�ظ���
    printf("%d\n", name1.size());

    //clear()���vector
    name1.clear();
    printf("%d\n", name1.size());

    //insert����Ԫ��
    name1.push_back(4);
    name1.push_back(5);
    name1.push_back(6);
    name1.insert(name1.begin() + 1, -9999);
    name1.insert(name1.begin() + 1, -8888);
    for (vector<int>::iterator it = name1.begin(); it != name1.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");

    //eraseɾ��Ԫ��, ע�������� ����ҿ�
    name1.erase(name1.begin(), name1.begin() + 2);  //ɾ��name1[0], name1[1]
    for (vector<int>::iterator it = name1.begin(); it != name1.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
    name1.erase(name1.begin());   //ɾ��name1[0]
    for (vector<int>::iterator it = name1.begin(); it != name1.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
}

void resizeTest()
{
    vector<int> arr;
    for (int i = 1; i <= 10; i++) {
        arr.push_back(i);
    }
    printf("cap = %d\n", arr.capacity());
    printf("size = %d\n", arr.size());
    for (int i = 0; i < arr.size(); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\n");

    arr.resize(15);

    printf("cap = %d\n", arr.capacity());
    printf("size = %d\n", arr.size());
    for (int i = 0; i < arr.size(); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

class testDemo
{
public:
    testDemo(int num) :num(num) {
        std::cout << "���ù��캯��." << endl;
    }
    testDemo(const testDemo& other) :num(other.num) {
        std::cout << "���ÿ������캯��." << endl;
    }
    testDemo(testDemo&& other) :num(other.num) {
        std::cout << "�����ƶ����캯��." << endl;
    }
private:
    int num;
};
void emplaceBackTest()
{
    cout << "emplace_back:" << endl;
    std::vector<testDemo> demo1;
    demo1.emplace_back(2);
    cout << "push_back:" << endl;
    std::vector<testDemo> demo2;
    demo2.push_back(2);
}

