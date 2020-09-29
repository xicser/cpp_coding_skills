#include <stdio.h>
#include <stdlib.h>


int input[200] = {0};

int main()
{
    while (1) {
        char tmp = getchar();
        if (tmp != '\n') {
            input[(int)tmp]++;
        } else {
            break;
        }
    }
    //PATest
    while (input['P'] || input['A'] || input['T'] || input['e'] || input['s'] || input['t']) {
        if (input['P']) {
            printf("P");
            input['P']--;
        }
        if (input['A']) {
            printf("A");
            input['A']--;
        }
        if (input['T']) {
            printf("T");
            input['T']--;
        }
        if (input['e']) {
            printf("e");
            input['e']--;
        }
        if (input['s']) {
            printf("s");
            input['s']--;
        }
        if (input['t']) {
            printf("t");
            input['t']--;
        }
    }

    return 0;
}
