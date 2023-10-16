// This class is a heritage of "Screen", which is the display of menu screen
// with its following funtion

#ifndef MENU_H
#define MENU_H

#include "Gameplay.h"
#include "Player.h"
#include "Screen.h"

class Menu : public Screen {
 private:
  // Set up these to make sure only 1 click is allowed
  bool birdPopup = false;
  bool backgroundPopup = false;
  bool modePopup = false;
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

  void chooseMode(float mouseX, float mouseY);
  void chooseBackground(float mouseX, float mouseY);
  void chooseBird(float mouseX, float mouseY);
  void deleteProgess();
  void saveProgress();
};

#endif