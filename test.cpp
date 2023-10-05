#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
  sf::RenderWindow window;
  sf::VideoMode videomode;
  videomode.height = 600;
  videomode.width = 1200;

  window.create(videomode, "Test", sf::Style::Close | sf::Style::Titlebar);
  window.setPosition(sf::Vector2i(100, 200));

  window.setFramerateLimit(120);

  sf::Texture texture;
  if (!texture.loadFromFile("resources/download.jpg")) {
    return 1;
  }

  sf::Sprite sprite(texture);
  int x = -223;
  int y = 187;

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }
    window.clear();
    sprite.setPosition(x+=2, y);

    window.draw(sprite);
    window.display();
    if (x >= (1200 + 223)) x = -223;
  }

  return 0;
}