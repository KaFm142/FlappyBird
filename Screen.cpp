#include "Screen.h"

// Screen constructor
Screen::Screen() {
  // Setting up height and width
  videomode.height = 600.0;
  videomode.width = 1200.0;
  // Create and display new window with the name "SCREEN"
  window = new sf::RenderWindow(videomode, "SCREEN",
                                sf::Style::Close | sf::Style::Titlebar);
  // Set the position and FPS for the window
  window->setPosition(sf::Vector2i(100, 200));
  window->setFramerateLimit(120);
};

// Screen destructor
Screen::~Screen(){};

void Screen::displayBackground() {
  // Load the initial background
  backgroundTexture = loadTexture("resources/screenBackground.jpg");
  // Set a while loop for the game
  while (window->isOpen()) {
    // Set up an event to hold
    sf::Event event;
    // Check if there are any event in the pool list
    while (window->pollEvent(event)) {
      // If the event is close, close the window 
      if (event.type == sf::Event::Closed) {
        window->close();
        // Clear the terminal
        system("clear");
      }
    }

    // Clear the last frame 
    window->clear();
    // Draw the window
    drawTexture(backgroundTexture, 0, 0);
    // Display the window
    window->display();
  }
}

// Action have no use in this class
void Screen::action(){};

sf::Texture Screen::loadTexture(std::string fileName) {
  // Set up a texture variable
  sf::Texture texture;
  // Handling error if the file is not loaded
  if (!texture.loadFromFile(fileName)) {
    std::cerr << "Failed to load image" << std::endl;
  }
  // return texture with the loaded image
  return texture;
}

void Screen::drawTexture(sf::Texture texture, int x, int y) {
  // Set up a sprite variable
  sf::Sprite sprite;
  // Set the sprite with the given texture and cordinator
  sprite.setTexture(texture);
  sprite.setPosition(x, y);
  // Draw the sprite
  window->draw(sprite);
}