#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b) {
        return 1;
    }
    return -1;
}
int main()
{
    int N, M;

    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; i++) {

        int tmp_arry[N];
        int _index = 0;
        int teacher_score;
        scanf("%d", &teacher_score); //老师打的分

        for (int j = 1; j < N; j++) {
            int tmp;
            scanf("%d", &tmp);
            if (0 <= tmp && tmp <= M) {
                tmp_arry[_index++] = tmp;
            }
        }
        qsort(tmp_arry, _index, sizeof(int), cmp);
//        for (int j = 0; j <= _index - 1; j++) {
//            printf("%d ", tmp_arry[j]);
//        }
//        printf("\n");

        double score = 0;
        for (int j = 1; j <= _index - 2; j++) {
            score += tmp_arry[j];
        }
        score /= _index - 2;
        score += teacher_score;
        score /= 2;
        printf("%d\n", (int)(score + 0.5));
    }

    return 0;
}
