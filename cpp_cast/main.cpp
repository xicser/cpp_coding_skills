#include <iostream>

using namespace std;

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {

};

/*
①用于类层次结构中基类（父类）和派生类（子类）之间指针或引用的转换。
进行上行转换（把派生类的指针或引用转换成基类表示）是安全的；
进行下行转换（把基类指针或引用转换成派生类表示）时，由于没有动态类型检查，所以是不安全的。
*/
void static_cast_test(void)
{
    char a = 'a';
    int b = static_cast<int>(a);        //正确，将char型数据转换成int型数据

    double *c = new double;
    void *d = static_cast<void*>(c);    //正确，将double指针转换成void指针

    int e = 10;
    const int f = static_cast<const int>(e);    //正确，将int型数据转换成const int型数据

    const int g = 20;
    // int *h = static_cast<int*>(&g);          //编译错误，static_cast不能转换掉g的const属性


    Base *bp = new Base();
    Derived *dp = new Derived();
    if (Derived *dp = static_cast<Derived *>(bp)) {//下行转换是不安全的
      //使用dp指向的Derived对象
    }
    else {
      //使用bp指向的Base对象
    }

    if(Base *bp = static_cast<Base *>(dp)){//上行转换是安全的
      //使用bp指向的Derived对象
    }
    else{
      //使用dp指向的Base对象
    }
}

/*  dynamic_cast主要用于类层次间的上行转换和下行转换
    基类中必须有虚函数
 */
void dynamic_cast_test(void)
{
    Base *bp = new Base();
    if (Derived *dp = dynamic_cast<Derived *>(bp)){
      //使用dp指向的Derived对象
    }
    else {
      //使用bp指向的Base对象
    }
}
void f(const Base &b)
{
    try {
        const Derived &d = dynamic_cast<const Derived &>(b);
        //使用b引用的Derived对象
    }
    catch (std::bad_cast){
        //处理类型转换失败的情况
    }
}

/*
const_cast, 用于修改类型的const或volatile属性
①常量指针被转化成非常量的指针，并且仍然指向原来的对象；
②常量引用被转换成非常量的引用，并且仍然指向原来的对象；
*/
void const_cast_test(void)
{
    const int g = 20;
    int *h1 = const_cast<int*>(&g);      //去掉const常量const属性

    const int g1 = 20;
    int &h2 = const_cast<int &>(g1);     //去掉const引用const属性

    const char *g2 = "hello";
    char *h3 = const_cast<char *>(g2);   //去掉const指针const属性
}

/*
reinterpret_cast, 它可以把一个指针转换成一个整数，也可以把一个整数转换成一个指针
*/
int output(int p)
{
    cout << p <<endl;
    return 0;
}

typedef int (*test_func)(int );//定义函数指针test_func
int reinterpret_cast_test()
{
    int p = 10;
    test_func fun1 = output;
    fun1(p);//正确
    test_func fun2 = reinterpret_cast<test_func>(&p);
    fun2(p);//...处有未经处理的异常: 0xC0000005: Access violation
    return 0;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
