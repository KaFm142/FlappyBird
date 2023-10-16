#include "Chicken.h"

// Class constructor
Chicken::Chicken() {
  // set up basic information
  health = 3;
  speed = 3.5;
  xPosition =  100;
  yPosition = 100;
}
// Class destructor

Chicken::~Chicken() {}

// Falling method
void Chicken::fall(){
  Unflyable::fall();
}