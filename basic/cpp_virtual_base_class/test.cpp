//间接基类A
class A {
protected:
    int m_a;
};

//直接基类B
class B: public A {
protected:
    int m_b;
};

//直接基类C
class C: public A {
protected:
    int m_c;
};

//派生类D
class D: public B, public C{
public:
    void seta(int a){ m_a = a; }  //命名冲突, 其实有两份, 除非使用下面的语句
//    void seta(int a){ B::m_a = a; }  //命名冲突
    void setb(int b){ m_b = b; }  //正确
    void setc(int c){ m_c = c; }  //正确
    void setd(int d){ m_d = d; }  //正确
private:
    int m_d;
};

int test(){
    D d;
    return 0;
}
