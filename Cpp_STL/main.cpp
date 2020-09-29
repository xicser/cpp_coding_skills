#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>

using namespace std;

void VectorTest(void)
{
    vector<int> input;
    vector<int>::iterator it;

    for (int i = 0; i < 3; i++) {
        input.push_back(i);
    }

//    it = input.end() - 1;
//    printf("%d ", *it);
//    it = input.begin() + 10;
//    input.insert(it, -1);

//    input.pop_back();
//    cout << input.size() << endl;

    for (it = input.begin(); it != input.end(); it++) {
        printf("%d ", *it);
    }

}

void SetTest(void)
{
    set<int> st;
    set<int>::iterator it;

    st.insert(100);
    st.insert(101);
    st.insert(102);
    st.insert(103);


    it = st.find(100);
    st.erase(it);


    for (it = st.begin(); it != st.end(); it++) {
        printf("%d ", *it);
    }

    cout<< *it <<endl;
}


int main()
{
//    VectorTest();
    SetTest();

    return 0;
}
