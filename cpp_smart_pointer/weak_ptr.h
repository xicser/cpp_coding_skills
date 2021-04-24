#ifndef __WEAK_PTR_H
#define __WEAK_PTR_H

#include <iostream>

using namespace std;

class AA {
public:
    AA() {
        cout << "AA" << endl;
    }
    ~AA() {
        cout << "~AA" << endl;
    }
};

void test_weak_ptr(void);

#endif // __WEAK_PTR_H
