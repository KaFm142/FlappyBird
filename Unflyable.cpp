#include "Unflyable.h"

#include "Screen.h"

Unflyable::Unflyable() {
  name = "yes";
  health = 1;
  speed = 1;
  height = 1;
  width = 1;
  xPosition = 50;
  yPosition = 100;
};
Unflyable::~Unflyable(){};

void Unflyable::fly() {
  xPosition += 2;
  yPosition -= 3;
};