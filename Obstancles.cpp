#include "Obstancles.h"

Obstancles::Obstancles() {
  positionX = 1200;
  positionY = 0;
};

Obstancles::~Obstancles() {}

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