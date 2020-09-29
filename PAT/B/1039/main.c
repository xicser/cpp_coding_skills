#include <stdio.h>
#include <stdlib.h>


int beads[300] = {0};
int beads_index = 0;
int make[300] = {0};
int make_index = 0;

int main()
{
    while (1) {
        char tmp_char;
        scanf("%c", &tmp_char);
        if (tmp_char != '\n') {
            beads[(int)tmp_char]++;
        } else break;
    }

    while (1) {
        char tmp_char;
        scanf("%c", &tmp_char);
        if (tmp_char != '\n') {
            make[(int)tmp_char]++;
        } else break;
    }


    int less_count = 0;
    int less_flag = 0;
    for (int i = 0; i < 300; i++) {
        if (beads[i] < make[i]) {
            less_count += make[i] - beads[i];
            less_flag = 1;
        }
    }

    if (less_flag) {
        printf("No %d\n", less_count);
    } else {
        int more_count = 0;
        for (int i = 0; i < 300; i++) {
            if (beads[i] > make[i]) {
                more_count += beads[i] - make[i];
            }
        }
        printf("Yes %d\n", more_count);
    }

    return 0;
}
