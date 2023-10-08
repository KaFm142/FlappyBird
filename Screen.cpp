#include "Screen.h"

Screen::Screen(){
    // videomode.height = height;
    // videomode.width = width;
    // window = std::make_unique<sf::RenderWindow>(
    //     videomode, "Screen", sf::Style::Close | sf::Style::Titlebar);
    // window->setPosition(sf::Vector2i(100, 200));
    // window->setFramerateLimit(120);
};

Screen::Screen(float height, float width) : height(height), width(width) {}

Screen::~Screen(){};

void Screen::displayBackground() {
  backgroundTexture.loadFromFile("resources/screenBackground.jpg");
  backgroundSprite.setTexture(backgroundTexture);
  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();
      }
    }

    window->clear();
    window->draw(backgroundSprite);
    window->display();
  }
}
void Screen::action(){};
