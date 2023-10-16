// This class present a group of flyable birds

#ifndef FLYABLE_H
#define FLYABLE_H

#include "Bird.h"

class Flyable : public Bird {
 public:
  // Class constructor and destructor
  Flyable();
  ~Flyable();

  // Different flying method
  void fly();
  virtual void fall();
};

#endif