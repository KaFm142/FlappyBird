#include "Player.h"

int main(void) {
  Player player;

  player.load();  // Load player data from a JSON file
  std::cout << "Player's name: " << player.getName() << std::endl;

  player.setName("KaFm");
  player.save();  // Save player data to a JSON file

  return 0;
}