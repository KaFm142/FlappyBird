// This class is a abtract class to held the window

#ifndef SCREEN_H
#define SCREEN_H

#include <stdlib.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>

class Screen {
 protected:
  // Variable from the SFML library
  sf::RenderWindow* window;
  sf::VideoMode videomode;
  sf::Texture backgroundTexture;
  // height and width of screen
  float height;
  float width;

 public:
  // Constructor and destructor
  Screen();
  ~Screen();
  // virtual functions for polymophism
  //virtual void popupWindow();
  virtual void displayBackground();
  virtual void action();
  // load and draw funtion
  sf::Texture loadTexture(std::string fileName);
  void drawTexture(sf::Texture texture, int x, int y);
};

#endif