// This class is a unit testing for the menu function

#ifndef TESTMENU_H
#define TESTMENU_H

#include "Menu.h"

class TestMenu {
 public:
  // Testing function
  void testCreatePlayer();
  void testNamePlayer();
  void testPlay();
  void testChooseBird();
  void testChooseBackground();
  void testChooseMode();
  void testSaveProgress();
  void testDeleteProgress();


  void TestDisplay();  
  // Run all test
  void runTest();
};

#endif