// this class is the falcon

#ifndef FALCON_H
#define FALCON_H

#include "Flyable.h"

// Inheritage of Flyable
class Falcon : public Flyable {
 public:
  // class constructor and destructor
  Falcon();
  ~Falcon();

  //Falling method
  void fall();
};

#endif
