#ifndef MENU_H
#define MENU_H

#include "Player.h"
#include "Screen.h"

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
  void drawTexture(sf::Texture texture, int x, int y);
  
  //   void createPlayer();
  //   void chooseDifficulty();
  //   void chooseBackground();
  //   void chooseBird();
  //   void rename();
  //   void deleteProgess();
};

#endif