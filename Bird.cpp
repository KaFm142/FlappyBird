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
void Bird::speedUp(float accel) { speed += accel; };

void Bird::setX(float xCoor) { this->xPosition = xCoor; };
void Bird::setY(float yCoor) { this->yPosition = yCoor; };

float Bird::getX() { return xPosition; };
float Bird::getY() { return yPosition; };
