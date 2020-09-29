#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
*/

typedef struct {
    char id[20];
    int score;
    int location;
    int local_rank;
    int final_rank;
} Student_t;


static int cmp (const void *a, const void *b)
{
    int res;
    Student_t *stu_a, *stu_b;
    stu_a = (Student_t *)a;
    stu_b = (Student_t *)b;

    if (stu_a->score < stu_b->score) {
        return 1;
    } else if ((stu_a->score > stu_b->score)) {
        return -1;
    } else {
        res = strcmp(stu_a->id, stu_b->id);
        if (res > 0) return 1;
        else if (res < 0) return -1;
        else return 0;
    }
}

int main()
{
    int T;
    int K;
    int index = 0;
    scanf("%d", &T);
    Student_t students[300 * T + 10];

    for (int i = 0; i < T; i++) {
        scanf("%d", &K);
        for (int j = 0; j < K; j++) {
            scanf("%s%d", students[index].id, &students[index].score);
            students[index].location = i + 1;
            index++;
        }
        //对这个考场的学生排序
        qsort(students + index - K, K, sizeof(Student_t), cmp);
        //计算local_rank
        (students + index - K)[0].local_rank = 1;
        for (int k = 1; k < K; k++) {
            if ( (students + index - K)[k].score != (students + index - K)[k - 1].score) {
                (students + index - K)[k].local_rank = k + 1;
            } else {
                (students + index - K)[k].local_rank =
                    (students + index - K)[k - 1].local_rank;
            }
        }
    }

    //对所有考生排名
    qsort(students, index, sizeof(Student_t), cmp);

    //计算每个考生的total_rank
    students[0].final_rank = 1;
    for (int k = 1; k < index; k++) {
        if ( students[k].score != students[k - 1].score) {
            students[k].final_rank = k + 1;
        } else {
            students[k].final_rank = students[k - 1].final_rank;
        }
    }

    printf("%d\n", index);
    for (int k = 0; k < index; k++) {
        printf("%s %d %d %d\n",
               students[k].id,
               students[k].final_rank,
               students[k].location,
               students[k].local_rank);
    }

    return 0;
}

//        printf("\n");
//        for (int j = 0; j < K; j++) {
//            printf("%s %d %d %d\n",
//                (students + index - K)[j].id,
//                (students + index - K)[j].score,
//                (students + index - K)[j].location,
//                (students + index - K)[j].local_rank);
//        }

