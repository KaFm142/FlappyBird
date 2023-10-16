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

  // Other functions

  // Reduce health if hit Obstance;
  int hitObstance();
  // Speed up by an amout of acceleration
  void speedUp(float accel);

  // Vitual function for fly and fall method
  virtual void fly();
  virtual void fall();

  // set and get functions

  void setPosition(sf::Vector2f position);
  sf::Vector2f getPosition();

  int getHealth();
  
  int getSpeed();
  void setSpeed(float speed);

  float getFallSpeed();
  void setFallSpeed(float fallSpeed);
};

#endif