// This class present a group of unflyable bird

#ifndef UNFLYABLE_H
#define UNFLYABLE_H

#include "Bird.h"

class Unflyable: public Bird{
    public:
    // Class constructor and destructor 
    Unflyable();
    ~Unflyable();
    
    // Different flying method
    void fly();
    virtual void fall();
};


#endif