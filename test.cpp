#include "Screen.h"
int main() {
  sf::Texture bg;
  sf::Sprite sp;

  sf::Texture b;
  sf::Sprite s;

  bg.loadFromFile("resources/screen.jpg");
  sp.setTexture(bg);

  b.loadFromFile("resources/originalBird.png");
  s.setTexture(b);
  int x = -223;
  int y = 187;
  sf::RenderWindow window;
  sf::VideoMode videomode;
  videomode.height = 600;
  videomode.width = 1200;

  window.create(videomode, "Test", sf::Style::Close | sf::Style::Titlebar);
  window.setPosition(sf::Vector2i(100, 100));

  window.setFramerateLimit(120);

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }
    window.clear();
    s.setPosition(x += 2, y);
    window.draw(sp);
    window.draw(s);
    window.display();
    if (x >= (1200 + 223)) x = -223;
  }

  return 0;
}