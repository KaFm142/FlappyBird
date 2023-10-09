#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
 private:
  std::string name;
  int highscore;
  std::string choosenBirds;
  std::string choosenBackground;
  int mode;

 public:
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
};

#endif