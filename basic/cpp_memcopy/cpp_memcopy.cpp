#include <iostream>


void testMemcpy(void* dest, void* src, size_t n)
{
    char* csrc = (char*)src;
    char* cdest = (char*)dest;

    for (int i = 0; i < n; i++) {
        cdest[i] = csrc[i];
    }
}

/* 内存重叠会破坏源字符串的值 */
void myMemMove(void* dest, void* src, size_t n)
{
    if (dest == NULL || src == NULL) {
        return;
    }

    char* csrc = (char* )src;
    char* cdest = (char* )dest;

    //有重叠
    if (cdest > csrc && cdest < csrc + n) {
        while (n) {
            cdest[n - 1] = csrc[n - 1];
            n--;
        }
    }
    //无重叠直接复制
    else {
        // Copy contents of src[] to dest[]
        for (int i = 0; i < n; i++) {
            cdest[i] = csrc[i];
        }
    }
}

void test1()
{
    char csrc[100] = "testCPY";
    myMemMove(csrc + 5, csrc, strlen(csrc));
    printf("%s", csrc);
}

void test2()
{
    char csrc[100] = "testCPY";

    testMemcpy(csrc + 5, csrc, strlen(csrc));
    printf("%s", csrc);
}

int main()
{
    test1();
    //test2();
}