#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

typedef struct {
    int i, j;
    int value;
} Tuple_t;


Tuple_t tuple3[12505];
int index = 0;

int cmp(const void *a, const void *b);

int main()
{
    int r, c;

    scanf("%d%d", &r, &c);

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int tmp;
            scanf("%d", &tmp);
            if (tmp != 0) {
                tuple3[index].i = i;
                tuple3[index].j = j;
                tuple3[index].value = tmp;
                index++;
            }
        }
    }

    for (int i = 0 ; i < index; i++) {
        int tmp;
        tmp = tuple3[i].i;
        tuple3[i].i = tuple3[i].j;
        tuple3[i].j = tmp;
    }
    qsort(tuple3, index, sizeof(Tuple_t), cmp);

    //输出
    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= r; j++) {

            int flag = 0, k;
            for (k = 0; k < index; k++) {
                if (tuple3[k].i == i && tuple3[k].j == j) {
                    flag = 1;
                    break;
                }
            }
            if (flag) printf("%d", tuple3[k].value);
            else printf("0");

            if (j == r) printf("\n");
            else printf(" ");
        }
    }


//
//
//    for (int i = 0 ; i < index; i++) {
//        printf("(i = %d, j = %d) %d\n", tuple3[i].i, tuple3[i].j, tuple3[i].value);
//    }

    return 0;
}


/*
(i = 1, j = 2) 12
(i = 1, j = 3) 9
(i = 3, j = 1) -3
(i = 3, j = 6) 14
(i = 4, j = 3) 24
(i = 5, j = 2) 18
(i = 6, j = 1) 15
(i = 6, j = 4) -7

(i = 1, j = 3) -3
(i = 1, j = 6) 15
(i = 2, j = 1) 12
(i = 2, j = 5) 18
(i = 3, j = 1) 9
(i = 3, j = 4) 24
(i = 4, j = 6) -7
(i = 6, j = 3) 14

*/


int cmp(const void *a, const void *b)
{
    Tuple_t *t1 = (Tuple_t *)a;
    Tuple_t *t2 = (Tuple_t *)b;

    if (t1->i < t2->i) {
        return -1;
    } else if (t1->i == t2->i) {

        if (t1->j < t2->j) {
            return -1;
        } else {
            return 1;
        }

    } else {
        return 1;
    }
}
