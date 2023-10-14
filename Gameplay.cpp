#include "Gameplay.h"

Gameplay::Gameplay() {
  score = 0;
  time = 0;
  window->setTitle("GamePlay");
  unflyable = new Unflyable();
  displayBackground();
}

Gameplay::~Gameplay() { delete unflyable; }

void Gameplay::displayBackground() {
  // Load textures and set up the sprite
  backgroundTexture = Screen::loadTexture("resources/screen.jpg");
  birdTexture = Screen::loadTexture("resources/birds/originalBird.png");
  birdSprite.setTexture(birdTexture);

  bool inAnimation = false;

  while (window->isOpen()) {
    sf::Event event;
    int frame;
    if (frame >= 60) {
      inAnimation = false;
    }
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();
      }
      if (event.type == sf::Event::KeyPressed) {
        action(event);

        if (event.key.code == sf::Keyboard::Space) {
          frame = 0;
          inAnimation = true;
        }
      }
    }
    if (!pause) {
      sf::Vector2f position = birdSprite.getPosition();

      if (inAnimation) {
        position.y -= 2;
        frame++;
      } else
        position.y += 2;

      birdSprite.setPosition(position);
    }
    window->clear();
    drawTexture(backgroundTexture, 0, 0);
    window->draw(birdSprite);
    window->display();
  }
}

void Gameplay::action(sf::Event event) {
  if (event.key.code == sf::Keyboard::Space) std::cout << "yes" << std::endl;

  if (event.key.code == sf::Keyboard::Q)
    pause = true;
  else if (event.type == sf::Event::KeyPressed)
    pause = false;
}