#include "deque.h"
#include <deque>
#include <iostream>

using namespace std;

void testDeque()
{
	//c.begin() ����ָ���һ��Ԫ�صĵ�����
	//c.end(��  ����ָ�����һ��Ԫ����һ��λ�õĵ�����
	deque<int> d1{ 1,2,3,4,5 };
	for (deque<int>::iterator it = d1.begin(); it != d1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//c.rbegin()����ָ������еĵ�һ��Ԫ�صĵ�����(��ԭ���е����һ��Ԫ��)
	//c.rend()����ָ������е����һ��Ԫ�ص���һ��λ��(��ԭ���еĵ�һ��Ԫ�ص�ǰһ��λ��)
	deque<int> d2{ 1,2,3,4,5 };
	for (deque<int>::reverse_iterator it = d2.rbegin(); it != d2.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//c.assign(n,num)��n��num�������Ƶ�����c
	//c.assign(beg, end)��[beg, end)��������ݿ������Ƶ�����c

	//c.operator[]�±����������
	//c.empty()�ж�c�����Ƿ�Ϊ��
	//c.front()����c�����ĵ�һ��Ԫ��
	//c.back()����c���������һ��Ԫ��
	//c.size()����c������ʵ��ӵ�е�Ԫ�ظ���
	//c.push_back(num)��ĩβλ�ò���Ԫ��
	//c.pop_back()ɾ��ĩβλ�õ�Ԫ��
	//c.push_front(num)�ڿ�ͷλ�ò���Ԫ��
	//c.pop_front()ɾ����ͷλ�õ�Ԫ��

	deque<int> d3{ 1,2,3,4,5 };
	d3.push_back(20);
	d3.push_front(0);
	for (deque<int>::iterator it = d3.begin(); it != d3.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;


	//c.resize(num)���¶��������Ĵ�С
	deque<int> d4{ 1,2,3,4,5 };
	d4.resize(d4.size() + 5);
	for (deque<int>::iterator it = d4.begin(); it != d4.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}