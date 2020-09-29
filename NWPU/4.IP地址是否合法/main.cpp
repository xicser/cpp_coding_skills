#include <iostream>
#include <stdio.h>


using namespace std;

bool isValid(int a)
{
    if (0 <= a && a <= 255) return true;
    return false;
}

int main()
{
    int N;
    int a, b, c, d;

    scanf("%d", &N);

    for (int i =0 ; i< N; i++) {
        scanf("%d.%d.%d.%d", &a, &b, &c, &d);
        if (isValid(a) && isValid(b) && isValid(c) && isValid(d)) {
            printf("Yes\n");
        } else printf("No\n");
    }

    return 0;
}
