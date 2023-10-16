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

// Bird flying
void Flyable::fly() {
  // Temporary position holder
  sf::Vector2f position = getPosition();
  // Control the bird to be in screen
  if (position.y <= 0) position.y = 0;

  // Bird glide down
  position.y += 2;

  // If the bird is above half, its x value also change
  if (position.y < 300) position.x += 2;

  // set the new position
  setPosition(position);
  // std::cout << "y: " << position.y << std::endl;
};

// Falling method
void Flyable::fall() {
  if (xPosition > 100) xPosition -= 4;
  if (yPosition > 0) yPosition -= 3;
}