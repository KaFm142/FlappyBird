#include "Flyable.h"

// Class constructor
Flyable::Flyable() {
  health = 1;
  speed = 1;
  xPosition = 100;
  yPosition = 100;
};
// Destructor
Flyable::~Flyable(){};

// Bird falling
void Flyable::fly() {
  sf::Vector2f position = getPosition();
  if (yPosition > 0)
    yPosition -= 3;
  else {
    yPosition = 0;
  }

  position.y += 2;
  if (position.y < 300) position.x += 2;
  setPosition(position);
  // std::cout << "y: " << position.y << std::endl;
};

void Flyable::fall() {
  if (xPosition > 100) xPosition -= 4;
  if (yPosition > 0) yPosition -= 3;
}