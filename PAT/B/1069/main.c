#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain

PickMe
Imgonnawin!
TryAgainAgain
*/
typedef struct {
    char name[22];
    int award_exist;
} Person_t;
int main()
{
    int have_print = 0;
    int M, N, S;

    scanf("%d%d%d", &M, &N, &S);
    Person_t person[M];

    for (int i = 0 ; i < M; i++) {
        getchar();
        scanf("%s", person[i].name);
        person[i].award_exist = 1;
    }

    for (int i = S - 1; i < M; ) {
        if (person[i].award_exist) {

            for (int j = i; j < M; j++) { //后面重复的全部标记已经取过奖金
                if (strcmp(person[i].name, person[j].name) == 0) {
                    person[j].award_exist = 0;
                }
            }

            printf("%s\n", person[i].name);
            i += N;
            have_print = 1;
        } else {
            i++;
        }
    }

    if (!have_print) {
        printf("Keep going...\n");
    }

    return 0;
}
