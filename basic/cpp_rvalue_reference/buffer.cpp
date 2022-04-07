#include <stdio.h>
#include <iostream>

using namespace std;

class Buffer {
public:
    char* p;

    Buffer() {
        p = new char;
        printf("Buffer()\n");
    }

    Buffer(Buffer&& buff) {
        printf("Buffer move\n");
        p = buff.p;
        buff.p = nullptr;
    }

    ~Buffer() {
        if (p != nullptr) {
            printf("~Buffer()\n");
            delete p;
            p = nullptr;
        }
    }
};

const Buffer& getBuffer()
{
    Buffer buffer;
    printf("%p, getBuffer\n", &buffer);
    return buffer;
}

Buffer getBufferObj()
{
    Buffer buffer;
    printf("%p, getBufferObj\n", &buffer);
    return buffer;
}

void setBuffer(const Buffer& buffer)
{
    printf("%p, &\n", &buffer);
}

//&& 表示传进来的这个buffer引用对应的对象是个将亡值(右值)
void setBuffer(Buffer&& buffer)
{
    printf("%p &&\n", &buffer);

    //重用将亡值的内存(相当于偷过来)
    char* p = buffer.p;
    buffer.p = nullptr;
}

void test()
{
    /*
    能这样调用的的话, setBuffer必须这么声明，两种方式:
    1, setBuffer(Buffer&& buffer);          入参是右值引用, 因为"getBuffer()"，这个表达式是个右值
    2, setBuffer(const Buffer& buffer);     入参是带const的左值引用, "getBuffer()"，这个表达式是个右值，因为只有const左值引用才能指向右值
    */
    setBuffer(getBufferObj());
    getchar();

    printf("<----------------------------------------------->\n");
    /*
    用buffer接getBuffer中的临时对象, 
    那么这个临时对象的生命周期就会被延长到和这个常引用相同的长度
    */
    //const Buffer& buffer = getBuffer();
    //printf("%p, getBuffer\n", &buffer);
    //getchar();
}
