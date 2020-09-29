#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int hight;
} Person_t;

int cmp(const void *a, const void *b)
{
    Person_t *pA = (Person_t *)a;
    Person_t *pB = (Person_t *)b;

    if (pA->hight < pB->hight) {
        return 1;
    } else if (pA->hight == pB->hight) {

        if (strcmp(pA->name, pB->name) > 0) {
            return 1;
        } else {
            return -1;
        }

    } else {
        return -1;
    }
}

int main()
{
    int output_count;
    int lines;
    int line_count, last_count;
    int N, K;
    scanf("%d%d", &N, &K);
    Person_t persons[N];

    for (int i = 0; i < N; i++) {
        scanf("%s%d", persons[i].name, &persons[i].hight);
    }

    lines = K;             //排数
    line_count = N / K;    //每排人数
    last_count = N / K + N % line_count; //最后一排人数

    qsort(persons, N, sizeof(Person_t), cmp);

    output_count = 0;
    for (int i = 0; i < lines; i++) {

        //输出buffer
        char output_buffer[last_count * 2][20];
        int base_index = last_count;
        int step = 0;
        int direc = -1; //-1为向左
        int smallest_index = base_index;
        int plus_count;

        if (i != 0) { //不是最后一排
            plus_count = line_count;
        } else {
            plus_count = last_count;
        }

        //Ann Mike Eva
        for (int j = output_count; j < output_count + plus_count; j++) {
            if (smallest_index > base_index) {
                smallest_index = base_index;
            }
            strcpy(output_buffer[base_index], persons[j].name);
            step++;      //步进值++
            if (direc == -1) {
                base_index -= step;
            } else {
                base_index += step;
            }
            direc *= -1; //方向反向
        }
        output_count += plus_count;

        for (int j = smallest_index; j < smallest_index + plus_count; j++) {
            printf("%s", output_buffer[j]);
            if (j != smallest_index + plus_count - 1) printf(" ");
            else printf("\n");
        }
    }

    return 0;
}
