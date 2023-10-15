// This class create another window for gameplay

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Menu.h"
#include "OriginalBird.h"
#include "Pipes.h"
#include "Player.h"
#include "Screen.h"

class Gameplay : public Screen {
 private:
  // Time and Score
  int score;
  // Texture, sprite and position of Bird
  sf::Texture birdTexture;
  sf::Sprite birdSprite;
  sf::Vector2f birdPosition;
  // List of available character
  OriginalBird* bird;

  // Texture, sprite and position of Obstancles
  sf::Texture* pipeTextures;    
  sf::Sprite* pipeSprites;      
  sf::Vector2f* pipePositions;  
  // List of Obstancles
  Pipes** pipes;

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

  // Display time and point
  void displayTime(int second);
  void displayScore();

  int spawnObstancle();
  void displayObstancle(int used);
};

#endif