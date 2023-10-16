// this class is the original of the game Flappy Bird

#ifndef ORIGINALBIRD_H
#define ORIGINALBIRD_H

#include "Unflyable.h"

class OriginalBird : public Unflyable {
 public:
  // class constructor and destructor
  OriginalBird();
  ~OriginalBird();

  // Fall method
  void fall();
};

#endif