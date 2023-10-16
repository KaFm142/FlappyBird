// this class represent a chicken

#ifndef CHICKEN_H
#define CHICKEN_H

#include "Unflyable.h"

// Inheritage of Unflyable
class Chicken : public Unflyable {
 public:
  // class constructor and destructor
  Chicken();
  ~Chicken();

  // Falling method
  void fall();
};

#endif