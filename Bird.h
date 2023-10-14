// This class is a hierachy for other classes

#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>

class Bird {
 protected:
  std::string name;
  int health;
  float speed;
  float height;
  float width;
  float xPosition;
  float yPosition;

 public:
  Bird();
  virtual ~Bird();

  void hitObstance();
  virtual void fly();
  void speedUp(float accel);

  void setX(float xCoor);
  void setY(float yCoor);

  float getX();
  float getY();
};

#endif