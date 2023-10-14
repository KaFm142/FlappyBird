#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Player.h"
#include "Screen.h"
#include "Menu.h"

#include "OriginalBird.h"

class Gameplay : public Screen {
 private:
  int score;
  int time;
  sf::Texture birdTexture;
  sf::Sprite birdSprite;
  
  OriginalBird *bird;

  bool pause;
  bool inAnimation;
  int frame;

      public : Gameplay();
  ~Gameplay();

  void displayBackground();

  void action(sf::Event event);
  void endgame();
  void save();
};

#endif