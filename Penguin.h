// this class is the penguin

#ifndef PENGUIN_H
#define PENGUIN_H

#include "Unflyable.h"

class Penguin : public Unflyable {
 public:
  // class constructor and destructor
  Penguin();
  ~Penguin();
  void fall();
};

#endif