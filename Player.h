// This class present a player

#ifndef PLAYER_H
#define PLAYER_H

#include <fstream>
#include <iostream>
#include "nlohmann/json.hpp"
#include <string>

using json = nlohmann::json;

class Player {
 private:
  std::string name;
  int highscore;
  // Choosen feature
  int mode;
  std::string choosenBirds;
  std::string choosenBackground;

 public:
  // Constructor
  Player();

  int getHighscore();
  void setHighscore(int score);

  std::string getName();
  void setName(std::string name);

  std::string getBirds();
  void setBirds(std::string birds);

  std::string getBackground();
  void setBackground(std::string background);

  int getMode();
  void setMode(int mode);

  void save(std::string nameS, int highscoreS);
  void load();
  // void createBird(std::string choosenBirds);
};

#endif