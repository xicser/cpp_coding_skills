#include <stdio.h>
#include <stdlib.h>



int get_1(unsigned int a)
{
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if ((a >> i) & 1) count++;
    }
    return count;
}
int get_all(unsigned int a)
{
    int count = 0;
    for (int i = 31; i >= 0; i--) {
        if ((a >> i) & 1) {
            return i + 1;
        }
    }

    return count;
}

unsigned int lower(char *str)
{
    int sum = 0;
    for (int i = 0; str[i] != 0; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] += 32;
            sum += str[i] - 96;
        } else if ('a' <= str[i] && str[i] <= 'z') {
            sum += str[i] - 96;
        }
    }

    return sum;
}

char str[100005];
int main()
{
    int _1count, _0count;
    gets(str);
    int sum = lower(str);

    _1count = get_1(sum);
    _0count = get_all(sum) - _1count;

    printf("%d %d\n", _0count, _1count);

    return 0;
}
