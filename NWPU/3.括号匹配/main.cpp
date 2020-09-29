#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

//"[","]","(",")"
bool isCorrect(char *str)
{
    stack <char> st;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {

        if (str[i] == '[' || str[i] == '(' || str[i] == '{') {
            st.push(str[i]);
        } else {
            if (st.empty()) return false;
            switch (str[i]) {
                case ']':
                    if (st.top() == '[') {
                        st.pop();
                    } else return false;
                    break;

                case ')':
                    if (st.top() == '(') {
                        st.pop();
                    } else return false;
                    break;

                case '}':
                    if (st.top() == '{') {
                        st.pop();
                    } else return false;
                    break;

                default: break;
            }
        }
    }

    if (st.empty()) return true;
    else return false;
}

char str[10005];


void getStr(char *str)
{
    int index = 0;
    while(1) {
        char tmp_char = getchar();
        if (tmp_char != '\n')
        {
            if (tmp_char == '[' || tmp_char == ']' || tmp_char == '(' ||
                tmp_char == ')' || tmp_char == '{' || tmp_char == '}')
            {
                str[index++] = tmp_char;
            }

        } else break;
    }
    str[index] = 0;
}

int main()
{
    int N;
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        getStr(str);

        if (isCorrect(str)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}
