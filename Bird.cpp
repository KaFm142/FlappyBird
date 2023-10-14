#include "Bird.h"

Bird::Bird() {
  name = "";
  health = 0;
  speed = 0.0;
  height = 0.0;
  width = 0.0;
  xPosition = 0.0;
  yPosition = 0.0;
}
Bird::~Bird(){};

void Bird::hitObstance() {
  if (health != 1) {
    health--;
  }
}

void Bird::fly(){};

void Bird::fall(){
  yPosition += speed;
}

void Bird::speedUp(float accel) { speed += accel; };

void Bird::setPosition(sf::Vector2f position) {
  xPosition = position.x;
  yPosition = position.y;
}

sf::Vector2f Bird::getPosition() {
  sf::Vector2f position;
  position.x = xPosition;
  position.y = yPosition;
  return position;
}
