#ifndef UNFLYABLE_H
#define UNFLYABLE_H

#include "Bird.h"

class Unflyable: public Bird{
    public:
    Unflyable();
    ~Unflyable();
    
    void fly();
};


#endif