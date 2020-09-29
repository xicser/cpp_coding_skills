#include <iostream>
#include <stdio.h>

using namespace std;

int month[13][2] = {
{0, 0},
{31, 31},
{28, 29},
{31, 31},
{30, 30},
{31, 31},
{30, 30},
{31, 31},
{31, 31},
{30, 30},
{31, 31},
{30, 30},
{31, 31},
};

bool isLeapYear(int year)
{
    if((0 == year % 4 && 0 != year % 100) || (0 == year %400) ) return true;
    return false;
}
int main()
{
    int ans;
    int N;
    int time1, time2;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int y1, m1, d1;
        int y2, m2, d2;
        scanf("%d %d %d %d %d %d", &y1, &m1, &d1, &y2, &m2, &d2);
        ans = 1;

        while (y1 < y2 || m1 < m2 || d1 < d2) {
            d1++; //天数++
            if (d1 == month[m1][isLeapYear(y1)] + 1) {
                m1++;
                d1 = 1;
            }
            if (m1 == 13) {
                y1++;
                m1 = 1;
            }
            ans++;
        }

        printf("%d\n", ans);
    }

    return 0;
}
