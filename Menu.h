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

  // Include a pointer to player class
  Player *player;

 public:
  // Class constructor and destructor
  Menu();
  ~Menu();
  // Display background and action function
  void displayBackground();
  void action();

  // Create Player for new player
  void createPlayer();
  std::string namePlayer();

  // Display player stat
  void displayPlayer();

  // Play function
  void play();

  // Choose function
  void chooseBird(float mouseX, float mouseY);
  void chooseBackground(float mouseX, float mouseY);
  void chooseMode(float mouseX, float mouseY);

  // Save and delete function
  void saveProgress();
  void deleteProgess();
};

#endif