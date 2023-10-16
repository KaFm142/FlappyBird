#include "Owl.h"

// Class constructor
Owl::Owl() {
  // set up basic information
  health = 3;
  speed = 3.5;
  xPosition =  100;
  yPosition = 300;
}
// Class destructor

Owl::~Owl() {}

void Owl::fall(){
  Flyable::fall();
}