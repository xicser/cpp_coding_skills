#include <stdio.h>
#include <stdlib.h>



int teams[10005] = {0};
int main()
{
    int i;
    int max_index = 0;
    int N;
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        int t_num, one_num, score;
        scanf("%d-%d %d", &t_num, &one_num, &score);
        teams[t_num] += score;
    }

    for (i = 0; i < 10005; i++) {
        if (teams[i] > teams[max_index]) {
            max_index = i;
        }
    }

    printf("%d %d\n", max_index, teams[max_index]);
    return 0;
}
