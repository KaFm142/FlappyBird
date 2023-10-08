#include "Menu.h"

Menu::Menu() {}

Menu::Menu(float height, float width) : Screen(height, width){};

Menu::~Menu() { delete window; };


void Menu::displayBackground() {
  bool menuOpen = true;
  
  if (!backgroundTexture.loadFromFile("resources/menu.jpg")) {
    std::cerr << "Failed to load menu.jpg" << std::endl;
    return;
  }

  backgroundSprite.setTexture(backgroundTexture);


  while (menuOpen) {
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();
        menuOpen = false;
      }
    }
    action();
    window->clear();
    window->draw(backgroundSprite);
    window->display();
  }
}

void Menu::action() {
  sf::Vector2i Mposition = sf::Mouse::getPosition(*window);

  float mouseX = static_cast<float>(Mposition.x);
  float mouseY = static_cast<float>(Mposition.y);

  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 190 && mouseY <= 260) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      std::cout << "play" << std::endl;
      // window->close();
    }
  }

  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 290 && mouseY <= 350) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      std::cout << "birds" << std::endl;
    }
  }

  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 385 && mouseY <= 450) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      std::cout << "backgrounds" << std::endl;
    }
  }

  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 490 && mouseY <= 560) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      std::cout << "mode" << std::endl;
    }
  }

  if (mouseX >= 1015 && mouseX <= 1190 && mouseY >= 545 && mouseY <= 590) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      std::cout << "delete" << std::endl;
    }
  }
}