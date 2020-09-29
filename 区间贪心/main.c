#include <stdio.h>
#include <stdlib.h>

#define MAXN 110


typedef struct {
    int x, y;
} Inteval;

Inteval I[MAXN];

static int cmp (const void *a, const void *b)
{
    Inteval *I1 = (Inteval *)a;
    Inteval *I2 = (Inteval *)b;

    //先按左端点从大到小排序
    if (I1->x != I2->x) {

        if (I1->x > I2->x) return -1;
        else return 1;

    } else {

        if (I1->y > I2->y) return 1;
        else return -1;

    }
}

int main(void)
{
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &I[i].x, &I[i].y);
    }

    qsort(I, n, sizeof(Inteval), cmp);

//    for (int i = 0; i < n; i++) {
//        printf("%d %d\n", I[i].x,I[i].y);
//    }

    int ans = 1, lastX = I[0].x;

    for (int i = 1; i < n; i++) {
        if (I[i].y <= lastX) {
            lastX = I[i].x;
            ans++;
            //可打印
        }
    }
    printf("%d\n", ans);

    return 0;
}
