#include "Unflyable.h"

// Class constructor
Unflyable::Unflyable() {
  health = 1;
  speed = 1;
 xPosition = 100;
  yPosition = 100;
};
// Destructor
Unflyable::~Unflyable(){};

// Bird falling
void Unflyable::fly() {
  if (yPosition > 0) yPosition -= 3;
  else{
    sf::Vector2f position = getPosition();
    position.y = 0;
    setPosition(position);
  }
};

void Unflyable::fall() {
  yPosition += fallSpeed;
  fallSpeed += 0.2;
}