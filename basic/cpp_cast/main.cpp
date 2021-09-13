#include <iostream>

using namespace std;

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {

};

/*
���������νṹ�л��ࣨ���ࣩ�������ࣨ���ࣩ֮��ָ������õ�ת����
��������ת�������������ָ�������ת���ɻ����ʾ���ǰ�ȫ�ģ�
��������ת�����ѻ���ָ�������ת�����������ʾ��ʱ������û�ж�̬���ͼ�飬�����ǲ���ȫ�ġ�
*/
void static_cast_test(void)
{
    char a = 'a';
    int b = static_cast<int>(a);        //��ȷ����char������ת����int������

    double *c = new double;
    void *d = static_cast<void*>(c);    //��ȷ����doubleָ��ת����voidָ��

    int e = 10;
    const int f = static_cast<const int>(e);    //��ȷ����int������ת����const int������

    const int g = 20;
    // int *h = static_cast<int*>(&g);          //�������static_cast����ת����g��const����


    Base *bp = new Base();
    Derived *dp = new Derived();
    if (Derived *dp = static_cast<Derived *>(bp)) {//����ת���ǲ���ȫ��
      //ʹ��dpָ���Derived����
    }
    else {
      //ʹ��bpָ���Base����
    }

    if(Base *bp = static_cast<Base *>(dp)){//����ת���ǰ�ȫ��
      //ʹ��bpָ���Derived����
    }
    else{
      //ʹ��dpָ���Base����
    }
}

/*  dynamic_cast��Ҫ�������μ������ת��������ת��
    �����б������麯��
 */
void dynamic_cast_test(void)
{
    Base *bp = new Base();
    if (Derived *dp = dynamic_cast<Derived *>(bp)){
      //ʹ��dpָ���Derived����
    }
    else {
      //ʹ��bpָ���Base����
    }
}
void f(const Base &b)
{
    try {
        const Derived &d = dynamic_cast<const Derived &>(b);
        //ʹ��b���õ�Derived����
    }
    catch (std::bad_cast){
        //��������ת��ʧ�ܵ����
    }
}

/*
const_cast, �����޸����͵�const��volatile����
�ٳ���ָ�뱻ת���ɷǳ�����ָ�룬������Ȼָ��ԭ���Ķ���
�ڳ������ñ�ת���ɷǳ��������ã�������Ȼָ��ԭ���Ķ���
*/
void const_cast_test(void)
{
    const int g = 20;
    int *h1 = const_cast<int*>(&g);      //ȥ��const����const����

    const int g1 = 20;
    int &h2 = const_cast<int &>(g1);     //ȥ��const����const����

    const char *g2 = "hello";
    char *h3 = const_cast<char *>(g2);   //ȥ��constָ��const����
}

/*
reinterpret_cast, �����԰�һ��ָ��ת����һ��������Ҳ���԰�һ������ת����һ��ָ��
*/
int output(int p)
{
    cout << p <<endl;
    return 0;
}

typedef int (*test_func)(int );//���庯��ָ��test_func
int reinterpret_cast_test()
{
    int p = 10;
    test_func fun1 = output;
    fun1(p);//��ȷ
    test_func fun2 = reinterpret_cast<test_func>(&p);
    fun2(p);//...����δ��������쳣: 0xC0000005: Access violation
    return 0;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
