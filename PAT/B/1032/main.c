#include <stdio.h>
#include <stdlib.h>


int scores[100000] = {0};

int main()
{
    int id, id_max, score;
    int max_score, max_score_index;
    int N;
    scanf("%d", &N);

    id_max = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &id, &score);
        if (id_max < id) {
            id_max = id;
        }
        scores[id] += score;
    }

    max_score = max_score_index = 0;
    for (int i = 1; i < id_max + 1; i++) {
        if (scores[i] != 0) {
            if (max_score < scores[i]) {
                max_score = scores[i];
                max_score_index = i;
            }
        }
    }

    printf("%d %d\n", max_score_index, max_score);

    return 0;
}
