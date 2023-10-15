// This class create another window for gameplay

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Menu.h"
#include "OriginalBird.h"
#include "Player.h"
#include "Screen.h"

class Gameplay : public Screen {
 private:
  // Time and Score
  int score;
  int time;
  // Texture, sprite and position of Bird
  sf::Texture birdTexture;
  sf::Sprite birdSprite;
  sf::Vector2f birdPosition;
  // List of available character
  OriginalBird *bird;

  // Other variable for gameplay purpose
  bool pause;
  bool inAnimation;
  int frame;

 public:
  // Constructor and destructor
  Gameplay();
  ~Gameplay();

  // Display the screen and be the main game logic
  void displayBackground();

  // Handle user input
  void action(sf::Event event);

  // Handle the game over
  void endgame();

  // Save the progress
  void save();
};

#endif