#include "Menu.h"

Menu::Menu() : Screen(){};

Menu::Menu(float height, float width) : Screen(height, width){};

Menu::~Menu(){
    // delete window;
};

void Menu::displayBackground() {
  backgroundTexture.loadFromFile("resources/menu.jpg");
  backgroundSprite.setTexture(backgroundTexture);

  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();
      }

      sf::Vector2i Mposition = sf::Mouse::getPosition(*window);
      if (sf::IntRect(490, 190, 260, 70).contains(Mposition)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          window->close();
        }
      }
    }
    window->clear();
    window->draw(backgroundSprite);
    window->display();
  }
}
void Menu::action(){};