// This class create another window for gameplay

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Chicken.h"
#include "Falcon.h"

#include "Menu.h"
#include "OriginalBird.h"
#include "Owl.h"
#include "Penguin.h"
#include "Pipes.h"
#include "Player.h"
#include "Screen.h"

class Gameplay : public Screen {
 private:
  // Player choosen feature
  int mode;
  std::string choosenBird;
  std::string choosenBackground;

  // Score
  int score;
  // Texture, sprite and position of Bird
  sf::Texture birdTexture;
  sf::Sprite birdSprite;
  sf::Vector2f birdPosition;
  // List of available character
  Bird* bird = nullptr;
  // Texture, sprite and position of Obstancles
  // Pipes
  sf::Texture* pipeTextures;
  sf::Sprite* pipeSprites;
  sf::Vector2f* pipePositions;

  // Flying Bird
 
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

  int spawnPipes();
  
  void displayObstancle(int used );

  void checkColapse(int used);

  void load();
};

#endif