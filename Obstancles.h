// This class represent obstancles

#ifndef OBSTANCLES_H
#define OBSTANCLES_H

#include "Screen.h"

class Obstancles {
 protected:
  // Basic variable
  int positionX;
  int positionY;

 public:
  // Class constructor and destructor
  Obstancles();
  ~Obstancles();

  // Set and get function
  void setPosition(sf::Vector2f position);
  sf::Vector2f getPosition();
};

#endif