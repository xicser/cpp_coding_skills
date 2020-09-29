#include <stdio.h>
#include <stdlib.h>


int A[10] = {0};
int B[10] = {0};


int cal(int num, int times)
{
    int res = 0;
    for (int i = 0, j = 1; i < times; i++, j *= 10) {
        res += j * num;
    }
    return res;
}

int main()
{
    int Da, Db;
    int Pa, Pb;

    char c_tmp;
    while (1) {
        c_tmp = getchar();
        if (c_tmp != ' ') {
            A[c_tmp - 48]++;
        } else {
            break;
        }
    }
    scanf("%d", &Da);
    getchar();

    while (1) {
        c_tmp = getchar();
        if (c_tmp != ' ') {
            B[c_tmp - 48]++;
        } else {
            break;
        }
    }
    scanf("%d", &Db);

    Pa = cal(Da, A[Da]);
    Pb = cal(Db, B[Db]);

    printf("%d", Pa + Pb);

    return 0;
}
