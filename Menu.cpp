#include "Menu.h"

Menu::Menu() {}

Menu::~Menu(){};

void Menu::displayBackground() {
  bool menuOpen = true;
  backgroundTexture = loadTexture("resources/menu.jpg");

  while (menuOpen) {
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();
        menuOpen = false;
        system("clear");
      }
    }

    window->clear();
    drawTexture(backgroundTexture, 0, 0);
    action();
    window->display();
  }
}

sf::Texture Menu::loadTexture(std::string fileName) {
  sf::Texture texture;
  if (!texture.loadFromFile(fileName)) {
    std::cerr << "Failed to load image" << std::endl;
    return texture;
  }
  return texture;
}
  
void Menu::drawTexture(sf::Texture texture, int x, int y) {
  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(x, y);
  window->draw(sprite);
}

void Menu::action() {
  sf::Texture buttonTexture;
  sf::Sprite buttonSprite;

  sf::Vector2i Mposition = sf::Mouse::getPosition(*window);

  float mouseX = static_cast<float>(Mposition.x);
  float mouseY = static_cast<float>(Mposition.y);

  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 190 && mouseY <= 260) {
    buttonTexture = loadTexture("resources/menuPlayOn.jpg");
    drawTexture(buttonTexture, 490, 190);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && playButton) {
      std::cout << "play" << std::endl;
      playButton = false;
    }
  }

  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 290 && mouseY <= 350) {
    buttonTexture = loadTexture("resources/menuBirdsOn.jpg");
    drawTexture(buttonTexture, 493, 285);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && chooseButton) {
      std::cout << "birds" << std::endl;
      chooseButton = false;
    }
  }

  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 385 && mouseY <= 450) {
    buttonTexture = loadTexture("resources/menuBackgroundOn.jpg");
    drawTexture(buttonTexture, 491, 383);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && chooseButton) {
      std::cout << "backgrounds" << std::endl;
      chooseButton = false;
    }
  }

  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 490 && mouseY <= 560) {
    buttonTexture = loadTexture("resources/menuModeOn.jpg");
    drawTexture(buttonTexture, 492, 489);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && chooseButton) {
      std::cout << "mode" << std::endl;
      chooseButton = false;
    }
  }

  if (mouseX >= 1018 && mouseX <= 1192 && mouseY >= 544 && mouseY <= 590) {
    buttonTexture = loadTexture("resources/menuDeleteOn.jpg");
    drawTexture(buttonTexture, 972, 530);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && chooseButton) {
      std::cout << "delete" << std::endl;
      chooseButton = false;
    }
  }
}