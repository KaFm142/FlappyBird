#ifndef MENU_H
#define MENU_H

#include "Screen.h"

class Menu : public Screen {
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