#include <iostream>
#include <stdio.h>

using namespace std;

int toSec(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}
void toHMS(int sec)
{
    printf("%d ", sec / 3600);
    sec %= 3600;

    printf("%d ", sec / 60);
    sec %= 60;

    printf("%d\n", sec);
}
//0  20 30 11 30 30
//
int main()
{
    int sec1, sec2;
    int h1, m1, s1;
    int h2, m2, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

    sec1 = toSec(h1, m1, s1);
    cout << sec1 << endl;

    sec2 = toSec(h2, m2, s2);
    cout << sec2 << endl;

    toHMS( (sec1 + sec2) / 2 );



    return 0;
}
