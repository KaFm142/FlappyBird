#include "TestGameplay.h"

void TestGameplay::runTest() {
  testSave();
  testLoad();
}

void TestGameplay::testSave() {
  try {
    Gameplay gameplay;
    Player player;
    int score = player.getHighscore() + 1;
    gameplay.setScore(score);
    gameplay.save();
    if (player.getHighscore() != score) throw;
  } catch (...) {
    std::cerr << "Error in saving player" << std::endl;
  }
}

void TestGameplay::testLoad() {
  try {
    Gameplay gameplay;
    Player player;
    gameplay.load();
    if (gameplay.getBirds() != player.getBirds() ||
        gameplay.getMode() != player.getMode() ||
        gameplay.getBacks() != player.getBackground())
      throw;

  } catch (...) {
    std::cerr << "Error in loading player choose" << std::endl;
  }
}

void TestGameplay::TestDisplay() {
  Gameplay Gameplay;
  Gameplay.displayBackground();
  Gameplay.displayHealth();
  Gameplay.displayObstancle(0);
  Gameplay.displayScore();
  Gameplay.displayTime(10);
};

int main(void) {
  TestGameplay test;
  test.runTest();
}