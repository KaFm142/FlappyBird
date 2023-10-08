#ifndef MENU_H
#define MENU_H

#include "Screen.h"

class Menu : public Screen {
 private:
  sf::Texture buttonTexture;
  sf::Sprite buttonSprite;
  bool playButton = true;
  bool chooseButton = true;
 public:
  Menu();
  Menu(float height, float width);
  ~Menu();

  void displayBackground();
  void action();

  //   void chooseDifficulty();
  //   void chooseBackground();
  //   void chooseBird();
  //   void rename();
  //   void deleteProgess();
};

#endif