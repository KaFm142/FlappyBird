#include "Bird.h"

// Default constructor
Bird::Bird() {
  health = 0;
  speed = 0.0;
  height = 0.0;
  width = 0.0;
  xPosition = 0.0;
  yPosition = 0.0;
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
void Bird::fall() { yPosition += speed; }

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

void Bird::speedUp(float accel) { speed +=accel; }