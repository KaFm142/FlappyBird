#include "TestPlayer.h"

void TestPlayer::runTest() {
  testSave();
  testLoad();
  testDelete();
}

void TestPlayer::testSave() {
  try {
    Player player;

    std::string name = player.getName();
    int score = player.getHighscore();
    std::string bird = player.getBirds();
    std::string back = player.getBackground();
    int mode = player.getMode();

    player.saveProgress("Ka", 122, 23, "231", "224");

    if (name == player.getName() && score == player.getHighscore() &&
        bird == player.getBirds() && back == player.getBackground() &&
        mode == player.getMode())
      throw;
  } catch (...) {
    std::cerr << "Error in saving" << std::endl;
  }
}

void TestPlayer::testLoad() {
  try {
    Player player;

    std::string name = player.getName();
    int score = player.getHighscore();
    std::string bird = player.getBirds();
    std::string back = player.getBackground();
    int mode = player.getMode();

    player.saveProgress("0", 2314, 12, "12e12", "19");
    player.loadProgress();

    if (name == player.getName() || score == player.getHighscore() ||
        bird == player.getBirds() || back == player.getBackground() ||
        mode == player.getMode())
      throw;
  } catch (...) {
    std::cerr << "Error in loading" << std::endl;
  }
}

void TestPlayer::testDelete() {
  try {
    Player player;

    player.deleteProgress();

    if (player.getName() != "" || player.getHighscore() != 0 ||
        player.getBirds() != "0" || player.getBackground() != "0" ||
        player.getMode() != 1)
      throw;
  } catch (...) {
    std::cerr << "Error in deleting" << std::endl;
  }
}

int main(void) {
  TestPlayer test;
  test.runTest();
}