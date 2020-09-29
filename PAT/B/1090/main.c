#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int partner[5];
    int count;
} Forbidden_t;

Forbidden_t forbidden[100005] = {0};
char isPartnerIn(int a, int *array, int len)
{
    for (int i = 0; i < len; i++) {
        if (a == array[i]) {
            return 1;
        }
    }
    return 0;
}
/*
6 3
20001 20002
20003 20004
20005 20006
20003 20001
20005 20004
20004 20006
4 00001 20004 00002 20003
5 98823 20002 20003 20006 10010
3 12345 67890 23333
*/
int main()
{
    int N, M;

    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; i++) {
        int tmp1, tmp2;
        scanf("%d%d", &tmp1, &tmp2);

        forbidden[tmp1].partner[forbidden[tmp1].count++] = tmp2;
        forbidden[tmp2].partner[forbidden[tmp2].count++] = tmp1;
    }

    for (int i = 0; i < M; i++) {


        int cnt, j;
        scanf("%d", &cnt);
        int things[cnt];
        for (int j = 0; j < cnt; j++) {
            scanf("%d", &things[j]);
        }

        //处理每个数things[j]
        for (j = 0; j < cnt; j++) {
            int partner_count = forbidden[things[j]].count;

            if (partner_count != 0) {

                //遍历和他不相容的所有, 看看每个都在不在
                for (int k = 0; k < partner_count; k++) {

                    if (isPartnerIn(forbidden[things[j]].partner[k], things, cnt)) {
                        printf("No\n");
                        goto finish;
                    }
                }
            }
        }

        if (j == cnt) {
            printf("Yes\n");
        }
finish:;

    }


    return 0;
}
