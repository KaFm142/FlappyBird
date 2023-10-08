#include "Menu.h"

Menu::Menu() {}

Menu::Menu(float height, float width) : Screen(height, width){};

Menu::~Menu(){};

void Menu::displayBackground() {
  bool menuOpen = true;

  if (!backgroundTexture.loadFromFile("resources/menu.jpg")) {
    std::cerr << "Failed to load menu" << std::endl;
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

    window->clear();
    window->draw(backgroundSprite);
    action();
    window->display();
  }
}

void Menu::action() {
  sf::Vector2i Mposition = sf::Mouse::getPosition(*window);

  float mouseX = static_cast<float>(Mposition.x);
  float mouseY = static_cast<float>(Mposition.y);

  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 190 && mouseY <= 260) {
    if (!buttonTexture.loadFromFile("resources/menuPlayOn.jpg")) {
      std::cerr << "Failed to load play" << std::endl;
      return;
    }
    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setPosition(490, 190);
    window->draw(buttonSprite);
    

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && playButton) {
      std::cout << "play" << std::endl;
      playButton = false;
    }
  }

  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 290 && mouseY <= 350) {
    if (!buttonTexture.loadFromFile("resources/menuBirdsOn.jpg")) {
      std::cerr << "Failed to load birds" << std::endl;
      return;
    }
    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setPosition(493, 285);
    window->draw(buttonSprite);
    

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && chooseButton) {
      std::cout << "birds" << std::endl;
      chooseButton = false;
    }
  }

  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 385 && mouseY <= 450) {
    if (!buttonTexture.loadFromFile("resources/menuBackgroundOn.jpg")) {
      std::cerr << "Failed to load background" << std::endl;
      return;
    }
    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setPosition(491, 383);
    window->draw(buttonSprite);
    

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&chooseButton) {
      std::cout << "backgrounds" << std::endl;
      chooseButton = false;
    }
  }

  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 490 && mouseY <= 560) {
    if (!buttonTexture.loadFromFile("resources/menuModeOn.jpg")) {
      std::cerr << "Failed to load mode" << std::endl;
      return;
    }
    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setPosition(492, 489);
    window->draw(buttonSprite);
  

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&chooseButton) {
      std::cout << "mode" << std::endl;
      chooseButton = false;
    }
  }

  if (mouseX >= 1018 && mouseX <= 1192 && mouseY >= 544 && mouseY <= 590) {
    if (!buttonTexture.loadFromFile("resources/menuDeleteOn.jpg")) {
      std::cerr << "Failed to load delete" << std::endl;
      return;
    }
    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setPosition(972, 530);
    window->draw(buttonSprite);
    

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&chooseButton) {
      std::cout << "delete" << std::endl;
      chooseButton = false;
    }
  }
}