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

//&& ��ʾ�����������buffer���ö�Ӧ�Ķ����Ǹ�����ֵ(��ֵ)
void setBuffer(Buffer&& buffer)
{
    printf("%p &&\n", &buffer);

    //���ý���ֵ���ڴ�(�൱��͵����)
    char* p = buffer.p;
    buffer.p = nullptr;
}

void test()
{
    /*
    ���������õĵĻ�, setBuffer������ô���������ַ�ʽ:
    1, setBuffer(Buffer&& buffer);          �������ֵ����, ��Ϊ"getBuffer()"��������ʽ�Ǹ���ֵ
    2, setBuffer(const Buffer& buffer);     ����Ǵ�const����ֵ����, "getBuffer()"��������ʽ�Ǹ���ֵ����Ϊֻ��const��ֵ���ò���ָ����ֵ
    */
    setBuffer(getBufferObj());
    getchar();

    printf("<----------------------------------------------->\n");
    /*
    ��buffer��getBuffer�е���ʱ����, 
    ��ô�����ʱ������������ھͻᱻ�ӳ����������������ͬ�ĳ���
    */
    //const Buffer& buffer = getBuffer();
    //printf("%p, getBuffer\n", &buffer);
    //getchar();
}
