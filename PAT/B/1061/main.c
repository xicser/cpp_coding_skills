#include <stdio.h>
#include <stdlib.h>
/*
3 6
2 1 3 3 4 5
0 0 1 0 1 1

0 1 1 0 0 1
1 0 1 0 1 0
1 1 0 0 1 1
*/

typedef struct {
    int score;
    int anwser;
} Questtion_t;
int main()
{
    int N, M;

    scanf("%d%d", &N, &M);
    Questtion_t questtin[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", &questtin[i].score);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d", &questtin[i].anwser);
    }

    for (int i = 0; i < N; i++) {
        int got_score = 0;
        for (int j = 0; j < M; j++) {
            int answer_tmp;
            scanf("%d", &answer_tmp);
            if (answer_tmp == questtin[j].anwser) {
                got_score += questtin[j].score;
            }
        }
        printf("%d\n", got_score);

    }

    return 0;
}
