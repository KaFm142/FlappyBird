#include "Unflyable.h"

// Class constructor
Unflyable::Unflyable() {
  health = 1;
  speed = 1;
  height = 1;
  width = 1;
  xPosition = 100;
  yPosition = 100;
};
// Destructor
Unflyable::~Unflyable(){};

// Bird falling
void Unflyable::fly() {
  if (yPosition > 0) yPosition -= 3;
};