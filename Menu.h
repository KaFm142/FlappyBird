#ifndef MENU_H
#define MENU_H

#include "Screen.h"
#include "Player.h"

class Menu : public Screen {
 
 private:
  
  bool playButton = true;
  bool chooseButton = true;
  Player *player;
  
 public:
  Menu();
  ~Menu();

  void displayBackground();
  void action();

  sf::Texture loadTexture(std::string fileName);

  //   void createPlayer();
  //   void chooseDifficulty();
  //   void chooseBackground();
  //   void chooseBird();
  //   void rename();
  //   void deleteProgess();
};

#endif