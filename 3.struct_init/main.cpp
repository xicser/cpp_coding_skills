#include <iostream>

using namespace std;



struct Point {
    int x, y;
//    Point() {
//
//    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};











int main()
{
    Point p(1, 2);


    cout << "Hello world!" << endl;
    return 0;
}
