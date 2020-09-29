#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int addr;
    int data;
    int next;
} Node;


/*
00100   6    4
Address Data Next
00000   4    99999
00100   1    12309
68237   6    -1
33218   3    00000
99999   5    68237
12309   2    33218
Address = 00100, Data = 1, Next = 12309
Address = 12309, Data = 2, Next = 33218
Address = 33218, Data = 3, Next = 00000
Address = 00000, Data = 4, Next = 99999
Address = 99999, Data = 5, Next = 68237
Address = 68237, Data = 6, Next = -0001





*/


Node List[100000];
Node OutList[100000];
int OutListIndex = 0;


//反转
void reverse(Node *list, int len)
{
    Node tmp_node;
    for (int i = 0; i < len / 2; i++) {
        tmp_node = list[i];
        list[i] = list[len - i - 1];
        list[len - i - 1] = tmp_node;
    }
}

int main()
{
    int N, K;
    int first_node_addr;

    scanf("%d%d%d", &first_node_addr, &N, &K);

    //输入
    for (int i = 0; i < N; i++) {
        int tmp_addr;
        scanf("%d", &tmp_addr);
        scanf("%d%d", &List[tmp_addr].data, &List[tmp_addr].next);
    }

    //遍历
    int addr = first_node_addr;
    while(1) {
        //存入输出数组后再处理
        OutList[OutListIndex].addr = addr;
        OutList[OutListIndex].data = List[addr].data;
        OutList[OutListIndex].next = List[addr].next;

//        printf("Address = %05d, Data = %d, Next = %05d\n",
//            OutList[OutListIndex].addr, OutList[OutListIndex].data, OutList[OutListIndex].next);

        OutListIndex++;

        if (List[addr].next != -1) {
            addr = List[addr].next;
        } else break;
    }

    for (int i = 0; i < OutListIndex / K; i++) { //反转
        reverse(OutList + i * K, K);
    }

    //处理next
    for (int i = 0; i < OutListIndex - 1; i++) {
        OutList[i].next = OutList[i + 1].addr;
    }
    OutList[OutListIndex - 1].next = -1; //最后一个


    for (int i = 0; i < OutListIndex - 1; i++) {
//        printf("Addr = %05d, Data = %d, Next = %05d\n",
//            OutList[i].addr, OutList[i].data, OutList[i].next);
        printf("%05d %d %05d\n",
            OutList[i].addr, OutList[i].data, OutList[i].next);
    }
    printf("%05d %d %d\n",
           OutList[OutListIndex - 1].addr,
           OutList[OutListIndex - 1].data,
           OutList[OutListIndex - 1].next);

    return 0;
}
