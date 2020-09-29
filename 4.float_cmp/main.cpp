#include <iostream>
#include <math.h>

using namespace std;

const double eps = 1e-8;
const double Pi = acos(-1.0);

//==
#define Equ(a, b) ((fabs((a) - (b))) < (eps))

//More
#define More(a, b) ((a) - (b) > (eps))

//Less
#define Less(a, b) ((a) - (b) < (-eps))


int main()
{
    double db = 1.23;
    if (Equ(db, 1.23)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
