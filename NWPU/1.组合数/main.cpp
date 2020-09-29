#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int up, down;
    int M, N;

    scanf("%d %d", &M, &N);

    up = 1;
    for (int i = 0, j = M; i < N; i++, j--) {
        up *= j;
    }

    down = 1;
    for (int i = 0; i < N; i++) {
        down *= (i + 1);
    }

    cout << up / down << endl;
    return 0;
}
