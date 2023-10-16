#include "Bird.h"

// Default constructor
Bird::Bird() {
  health = 0;
  speed = 0.0;
  xPosition = 0.0;
  yPosition = 0.0;
  fallSpeed = 1;
}

// Class destructor
Bird::~Bird(){};

// Reduce health if player hit obstances
int Bird::hitObstance() {
  health--;
  return health;
}

// Fly method
void Bird::fly(){};

// Bird falling
void Bird::fall() {}

// get and set for the bird position
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

int Bird::getHealth() { return health; }

int Bird::getSpeed() { return speed; }

void Bird::speedUp(float accel) { speed += accel; }

float Bird::getFallSpeed() { return fallSpeed; }

void Bird::setFallSpeed(float fallSpeed) { this->fallSpeed = fallSpeed; };

void Bird::setSpeed(float speed) { this->speed = speed; }