#include "deque.h"
#include <deque>
#include <iostream>

using namespace std;

void testDeque()
{
	//c.begin() 返回指向第一个元素的迭代器
	//c.end(）  返回指向最后一个元素下一个位置的迭代器
	deque<int> d1{ 1,2,3,4,5 };
	for (deque<int>::iterator it = d1.begin(); it != d1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//c.rbegin()返回指向反向队列的第一个元素的迭代器(即原队列的最后一个元素)
	//c.rend()返回指向反向队列的最后一个元素的下一个位置(即原队列的第一个元素的前一个位置)
	deque<int> d2{ 1,2,3,4,5 };
	for (deque<int>::reverse_iterator it = d2.rbegin(); it != d2.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//c.assign(n,num)将n个num拷贝复制到容器c
	//c.assign(beg, end)将[beg, end)区间的数据拷贝复制到容器c

	//c.operator[]下标运算符重载
	//c.empty()判断c容器是否为空
	//c.front()返回c容器的第一个元素
	//c.back()返回c容器的最后一个元素
	//c.size()返回c容器中实际拥有的元素个数
	//c.push_back(num)在末尾位置插入元素
	//c.pop_back()删除末尾位置的元素
	//c.push_front(num)在开头位置插入元素
	//c.pop_front()删除开头位置的元素

	deque<int> d3{ 1,2,3,4,5 };
	d3.push_back(20);
	d3.push_front(0);
	for (deque<int>::iterator it = d3.begin(); it != d3.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;


	//c.resize(num)从新定义容器的大小
	deque<int> d4{ 1,2,3,4,5 };
	d4.resize(d4.size() + 5);
	for (deque<int>::iterator it = d4.begin(); it != d4.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}