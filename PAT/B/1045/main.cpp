#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[100001], b[100001],c[100001];
    int n, cnt = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(a, a + n);

    int max = -1;
    for (int i = 0; i < n; i++)
    {
        if(a[i] == b[i] && b[i] > max)
            c[cnt++] = b[i];

        //保持max取最大值
        if(b[i] > max) {
            max = b[i];
        }
    }

    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++) {
        if (i != 0) printf(" ");
        printf("%d", c[i]);
    }
    printf("\n");
}
