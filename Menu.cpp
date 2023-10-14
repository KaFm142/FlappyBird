#include "Menu.h"

Menu::Menu() {}

Menu::Menu(float height, float width) : Screen(height, width){};

Menu::~Menu(){};

void Menu::displayBackground() {
  bool menuOpen = true;
  backgroundTexture = loadTexture("resources/menu.jpg");
  backgroundSprite.setTexture(backgroundTexture);

  while (menuOpen) {
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        
        window->close();
        menuOpen = false;
        system ("clear");
      }
    }

    window->clear();
    window->draw(backgroundSprite);
    action();
    window->display();
  }
}

sf::Texture Menu::loadTexture(std::string fileName){
  sf::Texture TbuttonTexture;
  if(!TbuttonTexture.loadFromFile(fileName)){
        std::cerr << "Failed to load image" << std::endl;
        return TbuttonTexture;
  }
  return TbuttonTexture;
}



void Menu::action() {
  sf::Texture buttonTexture;
  sf::Sprite buttonSprite;
  
  sf::Vector2i Mposition = sf::Mouse::getPosition(*window);

  float mouseX = static_cast<float>(Mposition.x);
  float mouseY = static_cast<float>(Mposition.y);

  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 190 && mouseY <= 260) {

    buttonTexture = loadTexture("resources/menuPlayOn.jpg");
    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setPosition(490, 190);
    window->draw(buttonSprite);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && playButton) {
      std::cout << "play" << std::endl;
      playButton = false;
    }
  }

  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 290 && mouseY <= 350) {
    buttonTexture = loadTexture("resources/menuBirdsOn.jpg");
    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setPosition(493, 285);
    window->draw(buttonSprite);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && chooseButton) {
      std::cout << "birds" << std::endl;
      chooseButton = false;
    }
  }

  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 385 && mouseY <= 450) {
    buttonTexture = loadTexture("resources/menuBackgroundOn.jpg");
    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setPosition(491, 383);
    window->draw(buttonSprite);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && chooseButton) {
      std::cout << "backgrounds" << std::endl;
      chooseButton = false;
    }
  }

  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 490 && mouseY <= 560) {
     buttonTexture = loadTexture("resources/menuModeOn.jpg");
    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setPosition(492, 489);
    window->draw(buttonSprite);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && chooseButton) {
      std::cout << "mode" << std::endl;
      chooseButton = false;
    }
  }

  if (mouseX >= 1018 && mouseX <= 1192 && mouseY >= 544 && mouseY <= 590) {
    buttonTexture = loadTexture("resources/menuDeleteOn.jpg");
    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setPosition(972, 530);
    window->draw(buttonSprite);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && chooseButton) {
      std::cout << "delete" << std::endl;
      chooseButton = false;
    }
  }
}