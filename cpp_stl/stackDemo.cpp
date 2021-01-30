#include <iostream>
#include <stack>
#include <stdio.h>

using namespace std;


void stackDemo(void)
{
    printf("**************************stack test****************************\n");

    //定义
    stack<int> st;

    //push
    for (int i = 1; i <= 5; i++) {
        st.push(i);
    }

    //top
    printf("%d\n", st.top());

    //pop
    st.pop();
    printf("%d\n", st.top());

    //empty
    printf("%d\n", st.empty());

    //size
    printf("%d\n", st.size());
}
