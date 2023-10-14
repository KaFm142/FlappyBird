#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Mouse.hpp>
#include <stdlib.h>
#include <iostream>

class Screen {
 protected:
  sf::RenderWindow* window;
  sf::VideoMode videomode;
  sf::Texture backgroundTexture;
  sf::Sprite backgroundSprite;

  float height;
  float width;

 public:
  Screen();
  ~Screen();

  virtual void displayBackground();
  virtual void action();
};

#endif