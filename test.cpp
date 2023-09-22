#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
  sf::RenderWindow window;
  sf::VideoMode videomode;
  videomode.height = 800;
  videomode.width = 600;

  window.create(videomode, "Test", sf::Style::Close | sf::Style::Titlebar);
  window.setPosition(sf::Vector2i(100, 100));

  
  while (window.isOpen()) {
    


    sf::Event event;
    while (window.pollEvent(event)) {


      if (event.type == sf::Event::Closed) window.close();
    }
  }

  return 0;
}