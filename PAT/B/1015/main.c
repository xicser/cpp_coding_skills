#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char id[20];
    int de_score;
    int cai_score;
} Student_t;

/*
H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；
才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；
德才分均低于 H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；
其他达到最低线 L 的考生也按总分排序，但排在第三类考生之后。
*/
int cmp1 (const void *a, const void *b)
{
    Student_t *stuA = (Student_t *)a;
    Student_t *stuB = (Student_t *)b;
    if (stuA->de_score + stuA->cai_score > stuB->de_score + stuB->cai_score) {
        return -1;
    } else if (stuA->de_score + stuA->cai_score == stuB->de_score + stuB->cai_score) {
        if (stuA->de_score > stuB->de_score) {
            return -1;
        } else if (stuA->de_score == stuB->de_score) {

            if (strcmp(stuA->id, stuB->id) > 0) {
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

/*
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
*/
int main()
{
    int N, L, H;
    int M = 0;

    scanf("%d%d%d", &N, &L, &H);
    getchar();
    Student_t students[N];
    for (int i = 0; i < N; i++) {
        char id_tmp[20];
        int de_score, cai_score;
        scanf("%s%d%d", id_tmp, &de_score, &cai_score);
        if (de_score >= L && cai_score >= L) {
            strcpy(students[M].id, id_tmp);
            students[M].de_score = de_score;
            students[M].cai_score = cai_score;
            M++;
        }
    }

    printf("%d\n", M);
    Student_t stu_out[M];
    int out_index = 0;

    //才德全尽
    for (int i = 0; i < M; i++) {
        if (students[i].de_score >= H && students[i].cai_score >= H) {
            stu_out[out_index++] = students[i];
        }
    }
    qsort(stu_out, out_index, sizeof(Student_t), cmp1);
    for (int i = 0; i < out_index; i++) {
        printf("%s %d %d\n", stu_out[i].id, stu_out[i].de_score, stu_out[i].cai_score);
    }

    //德胜才
    out_index = 0;
    for (int i = 0; i < M; i++) {
        if (students[i].de_score >= H && students[i].cai_score < H) {
            stu_out[out_index++] = students[i];
        }
    }
    qsort(stu_out, out_index, sizeof(Student_t), cmp1);
    for (int i = 0; i < out_index; i++) {
        printf("%s %d %d\n", stu_out[i].id, stu_out[i].de_score, stu_out[i].cai_score);
    }

    //才德兼亡”但尚有“
    out_index = 0;
    for (int i = 0; i < M; i++) {
        if (students[i].de_score < H && students[i].cai_score < H
            && students[i].de_score >= students[i].cai_score) {
            stu_out[out_index++] = students[i];
        }
    }
    qsort(stu_out, out_index, sizeof(Student_t), cmp1);
    for (int i = 0; i < out_index; i++) {
        printf("%s %d %d\n", stu_out[i].id, stu_out[i].de_score, stu_out[i].cai_score);
    }

    //其他
    out_index = 0;
    for (int i = 0; i < M; i++) {
        if (students[i].de_score < H && students[i].cai_score > students[i].de_score)
        {
            stu_out[out_index++] = students[i];
        }
    }
    qsort(stu_out, out_index, sizeof(Student_t), cmp1);
    for (int i = 0; i < out_index; i++) {
        printf("%s %d %d\n", stu_out[i].id, stu_out[i].de_score, stu_out[i].cai_score);
    }

    return 0;
}
