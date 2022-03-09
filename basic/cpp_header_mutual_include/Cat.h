#ifndef __CAT_H__
#define __CAT_H__

#include "Mouse.h"

class Mouse;
class Cat
{
public:
    Cat();
    ~Cat();

    void setMouse(Mouse* mouse);
};

#endif
