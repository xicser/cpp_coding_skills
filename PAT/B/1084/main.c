#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
1 8
1 11 12 1121 122111 112213

12221131
1123123111
1123123111

*/

void getNext(int *instr, int ilen, int *outstr, int *olen)
{
    int rec;
    int cnt;
    *olen = 0;

    for (int i = 0; i < ilen; ) {
        rec = instr[i];
        cnt = 1;
        for (int j = i + 1; ; j++) {
            if (instr[i] != instr[j]) {
                outstr[(*olen)++] = rec;
                outstr[(*olen)++] = cnt;
                break;
            } else {
                cnt++;
            }
        }
        i += cnt;
    }
}

int out_str[100000];
int out_index;
int in_str[100000];

int main()
{
    int tmp;
    int d, N;

    scanf("%d %d", &d, &N);

    if (N == 1) {
        printf("%d", d);
        return 0;
    }

    in_str[0] = d;
    getNext(in_str, 1, out_str, &out_index);

    for (int i = 1; i < N - 1; i++) {
        memcpy(in_str, out_str, out_index * 4);
        tmp = out_index;
        getNext(in_str, tmp, out_str, &out_index);
    }

    for (int i = 0; i < out_index; i++) {
        printf("%d", out_str[i]);
    }

    printf("\n");

    return 0;
}
