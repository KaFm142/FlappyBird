#include "Obstancles.h"

// COnstructor
Obstancles::Obstancles() {
  // Set the x position in the rightmost
  positionX = 1200;
  positionY = 0;
};

// Destructor
Obstancles::~Obstancles() {}

// Set and get position
void Obstancles::setPosition(sf::Vector2f position) {
  positionX = position.x;
  positionY = position.y;
}

sf::Vector2f Obstancles::getPosition() {
  sf::Vector2f position;
  position.x = positionX;
  position.y = positionY;
  return position;
}