#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char exam_id[15];
    char level;       //级别
    int exam_room;    //考场
    int exam_date;    //考试日期
    int number;       //考生编号
    int score;        //分数
} Student_t;

typedef struct {
    int type;           //类型
    char instruc[10];   //指令
} Request_t;

//12345
int str2num(char *str, int len)
{
    int res = 0;
    int k = 1;
    for (int i = len - 1; i >= 0; i--, k *= 10) {
        res += (str[i] - 48) * k;
    }
    return res;
}

int cmp1(const void *a, const void *b)
{
    Student_t *stuA = (Student_t *)a;
    Student_t *stuB = (Student_t *)b;

    if (stuA->score > stuB->score) {
        return -1;
    } else if (stuA->score == stuB->score) {

        if (strcmp(stuA->exam_id, stuB->exam_id) > 0) {
            return 1;
        } else {
            return -1;
        }

    } else {
        return 1;
    }
}
//处理类型1
void copeType1(Student_t *stus, int len, char level)
{
    int cnt = 0;
    qsort(stus, len, sizeof(Student_t), cmp1);
    for (int i = 0; i < len; i++) {
        if (stus[i].level == level) {
            cnt++;
            printf("%s %d\n", stus[i].exam_id, stus[i].score);
        }
    }
    if (cnt == 0) {
        printf("NA\n");
    }
}

//处理类型2
void copeType2(Student_t *stus, int len, int exam_room)
{
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (stus[i].exam_room == exam_room) {
            sum += stus[i].score;
            cnt++;
        }
    }
    if (cnt == 0) {
        printf("NA\n");
    } else {
        printf("%d %d\n", cnt, sum);
    }
}

//处理类型3
typedef struct {
    int times;
    int exam_room;
} Type3_t;
int cmp3(const void *a, const void *b)
{
    Type3_t *typeA = (Type3_t *)a;
    Type3_t *typeB = (Type3_t *)b;

    if (typeA->times >= typeB->times) {
        return -1;
    } else {
        return 1;
    }
}
void copeType3(Student_t *stus, int len, int date)
{
    int flag = 0;
    int exam_rooms[1005] = {0};
    Type3_t output[1005];
    int out_index = 0;

    for (int i = 0; i < len; i++) {
        if (stus[i].exam_date == date) {
            exam_rooms[stus[i].exam_room]++;
            flag = 1;
        }
    }

    if (flag == 0) {
        printf("NA\n");
        return;
    }

    for (int i = 0; i < 1005; i++) {
        if (exam_rooms[i]) {
            output[out_index].exam_room = i;
            output[out_index].times = exam_rooms[i];
            out_index++;
        }
    }

    qsort(output, out_index, sizeof(Type3_t), cmp3);
    for (int i = 0; i < out_index; i++) {
        printf("%03d %d\n", output[i].exam_room, output[i].times);
    }

}

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    Student_t stus[N];      //学生
    Request_t req[M];       //要求

    for (int i = 0; i < N; i++) {
        scanf("%s %d", stus[i].exam_id, &stus[i].score);
        stus[i].level = stus[i].exam_id[0];     //级别
        stus[i].exam_room = str2num(stus[i].exam_id + 1, 3);    //考场
        stus[i].exam_date = str2num(stus[i].exam_id + 4, 6);    //考试日期
        stus[i].number = str2num(stus[i].exam_id + 10, 3);      //考生编号
    }

    for (int i = 0 ; i < M; i++) {
        scanf("%d %s", &req[i].type, req[i].instruc);
    }

    for (int i = 0 ; i < M; i++) {
        printf("Case %d: %d %s\n", i + 1, req[i].type, req[i].instruc); //打印要求
        switch (req[i].type) {
            case 1: copeType1(stus, N, req[i].instruc[0]); break;
            case 2: copeType2(stus, N, str2num(req[i].instruc, strlen(req[i].instruc))); break;
            case 3: copeType3(stus, N, str2num(req[i].instruc, strlen(req[i].instruc))); break;
            default: break;
        }
    }

//    for (int i = 0; i < N; i++) {
//        printf("%d %c %d %d%d%d %d\n", stus[i].score, stus[i].level, stus[i].exam_room,
//               stus[i].exam_date.year, stus[i].exam_date.month, stus[i].exam_date.day,
//               stus[i].number);
//
//    }


    return 0;
}

/*
8 4
B 123 180908 127 99
B 102 180908 003 86
A 112 180318 002 98
T 107 150310 127 62
A 107 180908 108 100
T 123 180908 010 78
B 112 160918 035 88
A 107 180908 021 98


Case 3: 3 180908
107 2
123 2
102 1
*/
