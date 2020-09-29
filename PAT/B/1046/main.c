#include <stdio.h>
#include <stdlib.h>

/*

甲喊 甲划 乙喊 乙划
5
8 10 9 12
5 10 5 10
3 8 5 12
12 18 1 13
4 16 12 15
*/
int main()
{
    int N;
    int A_lose = 0, B_lose = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int A_speak, A_do;
        int B_speak, B_do;

        scanf("%d %d %d %d", &A_speak, &A_do, &B_speak, &B_do);

        if (A_do == A_speak + B_speak && B_do != A_speak + B_speak) {
            B_lose++;
        } else if (A_do != A_speak + B_speak && B_do == A_speak + B_speak) {
            A_lose++;
        }
    }


    printf("%d %d\n", A_lose, B_lose);
    return 0;
}
