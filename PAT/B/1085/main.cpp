#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;

typedef struct {
    int Ascore;
    int Bscore;
    int Tscore;
    int score;
    int people;
    char name[7];
} School_t;


//转换成大写
void toLowerCase(char *str)
{
    for (int i = 0 ; str[i]; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

map<string, School_t>schools;
map<string, School_t>::iterator sch_it;

int cmp(const void *a, const void *b);
int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0 ; i < N; i++) {
        int tmp_score;
        char tmp_id[6], tmp_school[7];
        scanf("%s %d %s", tmp_id, &tmp_score, tmp_school);
        toLowerCase(tmp_school);
        switch (tmp_id[0]) {
            case 'A': schools[tmp_school].Ascore += tmp_score; break;
            case 'B': schools[tmp_school].Bscore += tmp_score; break;
            case 'T': schools[tmp_school].Tscore += tmp_score; break;
            default: break;
        }
        strcpy(schools[tmp_school].name, tmp_school);
        schools[tmp_school].people++;
    }

    School_t output[schools.size()];
    int oindex = 0;
    //下面开始处理
    for (sch_it = schools.begin(); sch_it != schools.end(); sch_it++) {
        sch_it->second.score = sch_it->second.Bscore / 1.5 + sch_it->second.Ascore + sch_it->second.Tscore * 1.5;
        memcpy(&output[oindex++], &(sch_it->second), sizeof(School_t));
    }

    qsort(output, oindex, sizeof(School_t), cmp);
    printf("%d\n", schools.size());

    int rank_cur, rank_last = 1;
    printf("1 %s %d %d\n", output[0].name, output[0].score, output[0].people);
    for (int i = 1; i < oindex; i++) {
        if (output[i].score == output[i - 1].score) {
            rank_cur = rank_last;
        } else {
            rank_cur = i + 1;
            rank_last = i + 1;
        }

        printf("%d %s %d %d\n", rank_cur, output[i].name, output[i].score, output[i].people);
    }

    return 0;
}

int cmp(const void *a, const void *b)
{
    School_t *schA = (School_t *)a;
    School_t *schB = (School_t *)b;

    if (schA->score > schB->score) {
        return -1;
    } else if (schA->score == schB->score) {

        if (schA->people < schB->people) {
            return -1;
        } else if (schA->people == schB->people) {

            if (strcmp(schA->name, schB->name) > 0) {
                return 1;
            } else {
                return -1;
            }

        } else {
            return 1;
        }

    } else {
        return 1;
    }
}
