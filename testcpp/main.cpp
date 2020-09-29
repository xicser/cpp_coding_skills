#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int cnt = 0;
    int n;
    double sum = 0;
//    char str[100];
//    cin.getline(str, 100);
//
//    cout << str << " 2" << "" << "" << "" << "" << endl;

    while (scanf("%d", &n) != EOF) {
        cnt++;
        sum += n;
    }
    cout << sum / cnt;


    return 0;
}
