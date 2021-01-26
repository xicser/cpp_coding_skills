
/*

只有在vector和string中，才允许使用vi.begin() + i这种迭代器加上整数的写法

*/

#include <iostream>
#include "vectorDemo.h"
#include "setDemo.h"
#include "stringDemo.h"
#include "mapDemo.h"

using namespace std;

int main()
{
    vectorDemo();
    setDemo();
    stringDemo();
    mapDemo();

    return 0;
}