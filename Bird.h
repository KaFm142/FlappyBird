// This class is a hierachy for other classes

#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>

class Bird {
 protected:
  // Variable of the bird
  int health;
  float speed;
  float fallSpeed;
  float xPosition;
  float yPosition;

 public:
  // Constructor and destructor
  Bird();
  virtual ~Bird();

  // Other function
  int hitObstance();
  virtual void fly();
  virtual void fall();
  void speedUp(float accel);

  // set and get function
  void setPosition(sf::Vector2f position);
  sf::Vector2f getPosition();
  int getHealth();
  int getSpeed();
  float getFallSpeed();
  void setFallSpeed(float fallSpeed);
  void setSpeed(float speed);
};

#endif