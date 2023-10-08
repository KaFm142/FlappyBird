#include "Menu.h"

Menu::Menu() {
  videomode.height = 600.0;
  videomode.width = 1200.0;
  window = new sf::RenderWindow(videomode, "Screen",
                                sf::Style::Close | sf::Style::Titlebar);
  window->setPosition(sf::Vector2i(100, 200));
  window->setFramerateLimit(120);
};

Menu::Menu(float height, float width) : Screen(height, width){};

Menu::~Menu(){};

void Menu::loadButton() {
  // if (!backgroundTexture.loadFromFile("resources/menu.jpg")) {
  //   std::cerr << "Failed to load menu" << std::endl;
  //   return;
  // }
  // backgroundSprite.setTexture(backgroundTexture);

  // if (!buttonPlayTexture.loadFromFile("resources/menuPlayOff.jpg")) {
  //   std::cerr << "Failed to load play" << std::endl;
  //   return;
  // }
  // buttonPlaySprite.setTexture(buttonPlayTexture);
  // buttonPlaySprite.setPosition(490, 190);

  // if (!buttonBirdsTexture.loadFromFile("resources/menuBirdsOff.jpg")) {
  //   std::cerr << "Failed to load bird" << std::endl;
  //   return;
  // }
  // buttonBirdsSprite.setTexture(buttonBirdsTexture);
  // buttonBirdsSprite.setPosition(490, 290);

  // if (!buttonBackgroundTexture.loadFromFile(
  //         "resources/menuBackgroundOff.jpg")) {
  //   std::cerr << "Failed to load background" << std::endl;
  //   return;
  // }
  // buttonBackgroundSprite.setTexture(buttonBackgroundTexture);
  // buttonBackgroundSprite.setPosition(490, 385);

  // if (!buttonModeTexture.loadFromFile("resources/menuModeOff.jpg")) {
  //   std::cerr << "Failed to load mode" << std::endl;
  //   return;
  // }
  // buttonModeSprite.setTexture(buttonModeTexture);
  // buttonModeSprite.setPosition(490, 490);

  // if (!buttonDeleteTexture.loadFromFile("resources/menuDeleteOff.jpg")) {
  //   std::cerr << "Failed to load delete" << std::endl;
  //   return;
  // }
  // buttonDeleteSprite.setTexture(buttonDeleteTexture);
  // buttonDeleteSprite.setPosition(1015, 545);
}

void Menu::displayBackground() {
  bool menuOpen = true;

  if (!backgroundTexture.loadFromFile("resources/menu.jpg")) {
    std::cerr << "Failed to load menu.jpg" << std::endl;
    return;
  }

  backgroundSprite.setTexture(backgroundTexture);

  while (menuOpen) {
    // loadButton();
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
    // window->draw(buttonPlaySprite);
    // window->draw(buttonBirdsSprite);
    // window->draw(buttonBackgroundSprite);
    // window->draw(buttonModeSprite);
    // window->draw(buttonDeleteSprite);
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