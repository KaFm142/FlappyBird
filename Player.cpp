#include "Player.h"

// Constructor
Player::Player() {
  load();
  choosenBackground = "";
  choosenBirds = "";
  mode = 1;
}

// Initialize the function
int Player::getHighscore() {
  load();
  return this->highscore;
}

void Player::setHighscore(int score) { this->highscore = score; }

std::string Player::getName() {
  load();
  return this->name;
}

void Player::setName(std::string name) { this->name = name; }

std::string Player::getBirds() { return this->choosenBirds; }

void Player::setBirds(std::string birds) { this->choosenBirds = birds; }

std::string Player::getBackground() { return this->choosenBackground; }

void Player::setBackground(std::string background) {
  this->choosenBackground = background;
}

int Player::getMode() { return this->mode; }

void Player::setMode(int mode) { this->mode = mode; }

void Player::save(std::string nameS, int highscoreS) {
  json playerData;
  playerData["name"] = nameS;
  playerData["highscore"] = highscoreS;

  std::ofstream outputFile("save.json");
  if (outputFile.is_open()) {
    outputFile << playerData.dump(4);
    outputFile.close();
  } else {
    std::cerr << "error in saving" << std::endl;
  }
};

void Player::load() {
  std::ifstream inputFile("save.json");
  if (inputFile.is_open()) {
    json playerData;
    inputFile >> playerData;
    name = playerData["name"];
    highscore = playerData["highscore"];
    inputFile.close();
  } else {
    std::cerr << "error in loading" << std::endl;
  }
}