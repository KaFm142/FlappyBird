// this class represent a chicken

#ifndef CHICKEN_H
#define CHICKEN_H

#include "Unflyable.h"

class Chicken : public Unflyable {
 public:
  // class constructor and destructor
  Chicken();
  ~Chicken();
  void fall();
};

#endif