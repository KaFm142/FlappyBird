#include "Player.h"

// Constructor
Player::Player() {
  loadProgress();
  choosenBackground = "0";
  choosenBirds = "0";
  mode = 1;
}

// Dextructor
Player::~Player(){};

// Initialize the set and get functions
int Player::getHighscore() {
  // load player befor get the highscore
  loadProgress();
  return this->highscore;
}

void Player::setHighscore(int score) { this->highscore = score; }

std::string Player::getName() {
  loadProgress();
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

// Save function
void Player::saveProgress(std::string nameS, int highscoreS, int modeS,
                          std::string birdS, std::string backS) {
  // Create a temporary json to hold datas
  json playerData;
  playerData["name"] = nameS;
  playerData["highscore"] = highscoreS;
  playerData["mode"] = modeS;
  playerData["bird"] = birdS;
  playerData["background"] = backS;

  // Open file
  std::ofstream outputFile("save.json");
  if (outputFile.is_open()) {
    // Write data and close file
    outputFile << playerData.dump(4);
    outputFile.close();
  } else {
    // Display error message
    std::cerr << "error in saving" << std::endl;
  }
};

// Load function
void Player::loadProgress() {
  // Open save file
  std::ifstream inputFile("save.json");
  if (inputFile.is_open()) {
    json playerData;
    // Get tha data and hold it to a temporary json
    inputFile >> playerData;
    // Set the player stat according to the save
    name = playerData["name"];
    highscore = playerData["highscore"];
    mode = playerData["mode"];
    choosenBackground = playerData["background"];
    choosenBirds = playerData["bird"];

    // Close the file
    inputFile.close();
  } else {
    // Error handling
    std::cerr << "error in loading" << std::endl;
  }
}

// Delete Function
void Player::deleteProgress() {
  // Delete is saving null and 0 in to the save file
  saveProgress("", 0, 1, "0", "0");
}