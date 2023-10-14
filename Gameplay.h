#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Player.h"
#include "Screen.h"
#include "Unflyable.h"

class Gameplay : public Screen {
 private:
  int score;
  int time;
  sf::Texture birdTexture;
  sf::Sprite birdSprite;
  Unflyable *unflyable;  
bool pause = false; 

  public:
  Gameplay();
  ~Gameplay();
  
  void displayBackground();
  
  void action(sf::Event event);

};

#endif