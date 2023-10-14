// This class is a heritage of "Screen", which is the display of menu screen
// with its following funtion

#ifndef MENU_H
#define MENU_H

#include "Player.h"
#include "Screen.h"
#include "Gameplay.h"

class Menu : public Screen {
 private:
  // Set up these to make sure only 1 click is allowed
  bool playButton = true;
  bool chooseButton = true;
  Player *player;

 public:
  // Class constructor and destructor
  Menu();
  ~Menu();
  // Display background and action function
  void displayBackground();
  void action();
  // Create Player for new player
  std::string namePlayer();
  void createPlayer();
  void displayPlayer();
  void play();
  //   void chooseDifficulty();
  //   void chooseBackground();
  //   void chooseBird();
  //   void deleteProgess();
};

#endif