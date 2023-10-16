// this class is the falcon

#ifndef FALCON_H
#define FALCON_H

#include "Flyable.h"

class Falcon : public Flyable {
 public:
  // class constructor and destructor
  Falcon();
  ~Falcon();
  void fall();
};

#endif
