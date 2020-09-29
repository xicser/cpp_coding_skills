#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    int m, n;
} Pair;

Pair pairs[110];
int pairs_index = 0;
int input[10050];

static int cmp1 (const void *a, const void *b)
{
    Pair *P1 = (Pair *)a, *P2 = (Pair *)b;

    if (P1->m - P1->n < P2->m - P2->n) return 1;
    return -1;
}
static int cmp2 (const void *a, const void *b)
{
    if ( *((int *)a) < *((int *)b) ) return 1;
    return -1;
}
int main()
{
    int N, sqrt_N;
    scanf("%d", &N);
    sqrt_N = (int)sqrt(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
    }
    //非递增
    qsort(input, N, sizeof(int), cmp2);

    //先找出m, n
    int m, n;
    for (n = 1; n <= sqrt_N; n++) {
        for (m = n; m <= N; m++) {
            if (m * n == N) {
                pairs[pairs_index].m = m;
                pairs[pairs_index].n = n;
                pairs_index++;

            }
        }
    }
    qsort(pairs, pairs_index, sizeof(Pair), cmp1);
    m = pairs[pairs_index - 1].m;
    n = pairs[pairs_index - 1].n;

    int chart[m][n], i, j, cnt;
    memset(chart, 0, sizeof(chart));
    chart[i = 0][j = 0] = input[cnt = 0];
    while(cnt < N - 1)
    {
        while(j + 1 <= n - 1 && !chart[i][j + 1]) //在填充之前先检查能否填充, 能的话坐标再加
            chart[i][++j] = input[++cnt];
        while(i + 1 <= m - 1 && !chart[i + 1][j])
            chart[++i][j] = input[++cnt];
        while(j - 1 >= 0 && !chart[i][j - 1])
            chart[i][--j] = input[++cnt];
        while(i - 1 >= 0 && !chart[i - 1][j])
            chart[--i][j] = input[++cnt];
    }
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            printf("%d%c", chart[i][j], j == n - 1 ? '\n' : ' ');

    return 0;
}
/*


98 95 93 34 95
42 37 81 34 95
53 20 76 34 95
58 60 76 54 95
58 60 76 54 95
58 60 76 54 95

    for (int i = 0; i < pairs_index; i++) {
        printf("%d %d\n", pairs[i].m, pairs[i].n);
    }

*/
