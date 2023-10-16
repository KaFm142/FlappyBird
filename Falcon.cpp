#include "Falcon.h"

// Class constructor
Falcon::Falcon() {
  // set up basic information
  health = 5;
  speed = 5;
  xPosition =  100;
  yPosition = 300;
}
// Class destructor

Falcon::~Falcon() {}

void Falcon::fall(){
  Flyable::fall();
}