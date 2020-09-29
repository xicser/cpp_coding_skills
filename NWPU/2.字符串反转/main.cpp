#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int N;

    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        char tmp_str[100];
        gets(tmp_str);

        reverse(tmp_str, tmp_str + strlen(tmp_str));
        printf("%s\n", tmp_str);
    }




    cout << "Hello world!" << endl;
    return 0;
}
