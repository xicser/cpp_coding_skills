#ifndef __PRIOR_QUEUE_DEMO_H__
#define __PRIOR_QUEUE_DEMO_H__

#include <string>

using namespace std;

class fruit {
public:
    string name;
    int price;

    friend bool operator< (fruit f1, fruit f2);
};

void prior_queueDemo(void);

#endif // __PRIOR_QUEUE_DEMO_H__
