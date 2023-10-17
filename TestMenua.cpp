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

void TestMenu::testCreatePlayer() {
  try {
    Menu menu;
    menu.createPlayer();
    if (menu.getplayer() == nullptr) throw ; }
    
}