#ifndef __MOUSE_H__
#define __MOUSE_H__

#include "Cat.h"

class Cat;
class Mouse
{
public:
    Mouse();
    ~Mouse();

    void setCat(Cat* cat);
};

#endif // !_MOUSE_H_
