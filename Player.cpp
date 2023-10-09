#include "Player.h"

Player::Player() {
  name = "";
  highscore = 0;
  choosenBackground = "";
  choosenBirds = "";
  mode = 1;
}

int Player::getHighscore() { return this->highscore; }

void Player::setHighscore(int score) { this->highscore = score; }

std::string Player::getName() { return this->name; }

void Player::setName(std::string name) { this->name = name; }

std::string Player::getBirds() { return this->choosenBirds; }

void Player::setBirds(std::string birds) { this->choosenBirds = birds; }

std::string Player::getBackground() { return this->choosenBackground; }

void Player::setBackground(std::string background) {
  this->choosenBackground = background;
}

int Player::getMode() { return this->mode; }

void Player::setMode(int mode) { this->mode = mode; }