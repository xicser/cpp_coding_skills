#include <iostream>

using namespace std;

class Base {

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

void dynamic_cast_test(void)
{
//    Base *bp = new Base();
//    if(Derived *dp = dynamic_cast<Derived *>(bp)){
//      //ʹ��dpָ���Derived����
//    }
//    else{
//      //ʹ��bpָ���Base����
//    }
}





int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
