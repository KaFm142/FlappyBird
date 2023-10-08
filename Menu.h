#ifndef MENU_H
#define MENU_H

#include "Screen.h"

class Menu : public Screen {
 private:

  sf::Texture buttonPlayTexture;
  sf::Texture buttonBirdsTexture;
  sf::Texture buttonBackgroundTexture;
  sf::Texture buttonModeTexture;
  sf::Texture buttonDeleteTexture;

  sf::Sprite buttonPlaySprite;
  sf::Sprite buttonBirdsSprite;
  sf::Sprite buttonBackgroundSprite;
  sf::Sprite buttonModeSprite;
  sf::Sprite buttonDeleteSprite;

 public:
  Menu();
  Menu(float height, float width);
  ~Menu();

  void displayBackground();
  void action();
  void loadButton();
  //   void chooseDifficulty();
  //   void chooseBackground();
  //   void chooseBird();
  //   void rename();
  //   void deleteProgess();
};

#endif