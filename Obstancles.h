#ifndef OBSTANCLES_H
#define OBSTANCLES_H

#include "Screen.h"

class Obstancles {
 protected:
  int positionX;
  int positionY;

 public:
  Obstancles();
  ~Obstancles();

  void setPosition(sf::Vector2i position);
  sf::Vector2i getPosition();
};

#endif