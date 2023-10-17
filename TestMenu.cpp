#include "TestMenu.h"

// Run test
void TestMenu::runTest() {
  testCreatePlayer();
  testNamePlayer();
  testPlay();
  testChooseBird();
  testChooseBackground();
  testChooseMode();
  testSaveProgress();
  testDeleteProgress();
  TestDisplay();
}

// testing function using try and catch

void TestMenu::testCreatePlayer() {
  try {
    Menu menu;
    menu.createPlayer();
    if (menu.getplayer() == nullptr) throw;
  } catch (...) {
    std::cerr << "Error in create player" << std::endl;
  }
}

void TestMenu::testNamePlayer() {
  try {
    Menu menu;
    std::string name = menu.namePlayer();
    if (name == "") throw;
    if (menu.getplayer() == nullptr) throw;
  } catch (...) {
    std::cerr << "Error in naming player" << std::endl;
  }
}

void TestMenu::testPlay() {
  try {
    Menu menu;
    menu.play();
    if (menu.getplayer() == nullptr) throw;
  } catch (...) {
    std::cerr << "Error in play function" << std::endl;
  }
}

void TestMenu::testChooseBird() {
  try {
    Menu menu;
    Player player;
    float positionX = 189;
    float posistionY = 202;
    menu.chooseBird(positionX, posistionY);
    if (player.getBirds() < "0" || player.getBirds() > "4") throw;
  } catch (...) {
    std::cerr << "Error in choosing bird" << std::endl;
  }
}

void TestMenu::testChooseBackground() {
  try {
    Menu menu;
    Player player;
    float positionX = 733;
    float posistionY = 511;
    menu.chooseBackground(positionX, posistionY);
    if (player.getBackground() != "1" && player.getBackground() != "0") throw;
  } catch (...) {
    std::cerr << "Error in choosing background" << std::endl;
  }
}

void TestMenu::testChooseMode() {
  try {
    Menu menu;
    Player player;
    float positionX = 235;
    float posistionY = 523;
    menu.chooseMode(positionX, posistionY);
    if (player.getMode() != 0 && player.getMode() != 1) throw;
  } catch (...) {
    std::cerr << "Error in choosing mode" << std::endl;
  }
}

void TestMenu::testSaveProgress() {
  try {
    Menu menu;
    Player player;

    std::string nameB = player.getName();
    int scoreB = player.getHighscore();
    int modeB = player.getMode();
    std::string birdB = player.getBirds();
    std::string backB = player.getBackground();
    menu.saveProgress();

    if (nameB != player.getName() || scoreB != player.getHighscore() ||
        modeB != player.getMode() || birdB != player.getBirds() ||
        backB != player.getBackground())
      throw;
  } catch (...) {
    std::cerr << "Error in saving" << std::endl;
  }
}

void TestMenu::testDeleteProgress() {
  try {
    Menu menu;
    Player player;

    std::string nameB = player.getName();
    int scoreB = player.getHighscore();
    int modeB = player.getMode();
    std::string birdB = player.getBirds();
    std::string backB = player.getBackground();
    menu.saveProgress();

    if (nameB == player.getName() && scoreB == player.getHighscore() &&
        modeB == player.getMode() && birdB == player.getBirds() &&
        backB == player.getBackground())
      throw;
  } catch (...) {
    std::cerr << "Error in deleting" << std::endl;
  }
}

void TestMenu::TestDisplay() {
  Menu menu;
  menu.displayBackground();
}

int main(void) {
  TestMenu test;
  test.runTest();
}