#include "Screen.h"
int main() {
  sf::Texture bg;
  sf::Sprite sp;

  sf::Texture b;
  sf::Sprite s;

  bg.loadFromFile("resources/screen.jpg");
  sp.setTexture(bg);

  b.loadFromFile("resources/birds/originalBird.png");
  s.setTexture(b);
  int x = 10;
  int y = 187;
  sf::RenderWindow window;
  sf::VideoMode videomode;
  videomode.height = 600;
  videomode.width = 1200;

  window.create(videomode, "Test", sf::Style::Close | sf::Style::Titlebar);
  window.setPosition(sf::Vector2i(100, 100));

  window.setFramerateLimit(120);
  bool animationStarted = false;
  int frame = 0;

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (!animationStarted && event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
          animationStarted = true;
        }
      }
    }

    if (animationStarted) {
      if (frame < 60) {
        frame++;
        window.clear();
        s.setPosition(x += 1, y--);
        window.draw(sp);
        window.draw(s);
        window.display();
      } else {
        frame = 0;
        animationStarted = false;  // Reset the flag
      }
    } else {
      window.draw(sp);
      s.setPosition(x += 1, y++);

      window.draw(s);
      window.display();
      if (x >= (1200 + 10)) x = 10;
    }
  }
  return 0;
}