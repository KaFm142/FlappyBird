#include "Penguin.h"

// Class constructor
Penguin::Penguin() {
  // set up basic information
  health = 5;
  speed = 5;
  xPosition = 100;
  yPosition = 100;
}
// Class destructor

Penguin::~Penguin() {}

// Falling method of unflyable
void Penguin::fall() { Unflyable::fall(); }