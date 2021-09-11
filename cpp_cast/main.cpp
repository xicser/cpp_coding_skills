#include <iostream>

using namespace std;

class Base {

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

void dynamic_cast_test(void)
{
//    Base *bp = new Base();
//    if(Derived *dp = dynamic_cast<Derived *>(bp)){
//      //使用dp指向的Derived对象
//    }
//    else{
//      //使用bp指向的Base对象
//    }
}





int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
