#include "Menu.h"

// The constructor set the title of the screen into "Menu" and create player
Menu::Menu() {
  player = new Player();
  player->setName(createPlayer());
  window->setTitle("MENU");
  displayBackground();
}

Menu::~Menu(){};

void Menu::displayBackground() {
  // Load the background texture
  backgroundTexture = Screen::loadTexture("resources/menu.jpg");
  // A loop while the window is open
  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {
      // If there is close in the event pool list, close the window
      if (event.type == sf::Event::Closed) {
        window->close();
        system("clear");
      }
    }
    // Clear and update the window for each frame
    window->clear();
    Screen::drawTexture(backgroundTexture, 0, 0);
    // Action that take place
    action();
    window->display();
  }
}

void Menu::action() {
  // Create these to hold the button
  sf::Texture buttonTexture;
  sf::Sprite buttonSprite;
  // Get the mouse position
  sf::Vector2i Mposition = sf::Mouse::getPosition(*window);
  float mouseX = static_cast<float>(Mposition.x);
  float mouseY = static_cast<float>(Mposition.y);
  // Check for the mouse and click
  // Mouse in play button
  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 190 && mouseY <= 260) {
    // Highlight button
    buttonTexture = loadTexture("resources/menuPlayOn.jpg");
    drawTexture(buttonTexture, 490, 190);
    // Call for function when player click
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && playButton) {
      std::cout << "play" << std::endl;
      // Deactivate the playButton
      playButton = false;
      std::cout << player->getName() << std::endl;
    }
  }
  // Mouse in Birds button
  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 290 && mouseY <= 350) {
    // Highlight button
    buttonTexture = loadTexture("resources/menuBirdsOn.jpg");
    Screen::drawTexture(buttonTexture, 493, 285);
    // Call for function
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && chooseButton) {
      std::cout << "birds" << std::endl;
      // Deactivate the chooseButton
      chooseButton = false;
    }
  }
  // Mouse in Background button
  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 385 && mouseY <= 450) {
    // Highlight button
    buttonTexture = loadTexture("resources/menuBackgroundOn.jpg");
    Screen::drawTexture(buttonTexture, 491, 383);
    // Call for function
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && chooseButton) {
      std::cout << "backgrounds" << std::endl;

      chooseButton = false;
    }
  }
  // Mouse in Mode button
  if (mouseX >= 490 && mouseX <= 750 && mouseY >= 490 && mouseY <= 560) {
    // Highlight button
    buttonTexture = loadTexture("resources/menuModeOn.jpg");
    Screen::drawTexture(buttonTexture, 492, 489);
    // Call for function
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && chooseButton) {
      std::cout << "mode" << std::endl;
      chooseButton = false;
    }
  }
  // Mouse in Delete button
  if (mouseX >= 1018 && mouseX <= 1192 && mouseY >= 544 && mouseY <= 590) {
    // highlight button
    buttonTexture = loadTexture("resources/menuDeleteOn.jpg");
    Screen::drawTexture(buttonTexture, 972, 530);
    // Call for function
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && chooseButton) {
      std::cout << "delete" << std::endl;
      chooseButton = false;
    }
  }
}

std::string Menu::createPlayer() {
  // Set up font and color
  sf::Font font;
  font.loadFromFile("resources/arial.ttf");
  sf::Color color(169, 176, 168);

  // Set the background and title
  backgroundTexture = Screen::loadTexture("resources/createPlayer.jpg");
  window->setTitle("Create Player");
  window->setFramerateLimit(60);

  // Set up variable to set and display user input
  sf::String nameInput = "";
  sf::Text textDisplay;
  textDisplay.setFont(font);
  textDisplay.setCharacterSize(100);
  textDisplay.setPosition(80, 300);
  textDisplay.setFillColor(color);

  // While loop when window is open
  while (window->isOpen()) {
    sf::Event event;
    // Event pool
    while (window->pollEvent(event)) {
      // Close the window
      if (event.type == sf::Event::Closed) {
        window->close();
        system("clear");
      }
      // Handle user input
      // If user press text key
      if (event.type == sf::Event::TextEntered) {
        // Ignore the backspace key, we handle it later
        if (event.text.unicode != '\b')
          if (event.text.unicode < 128) {
            // Only 15 letter is allow
            if (nameInput.getSize() < 15) {
              // Update the input string
              nameInput += static_cast<char>(event.text.unicode);
              textDisplay.setString(nameInput);
            }
          }
      }
      // If user press special key
      if (event.type == sf::Event::KeyPressed) {
        // 'Enter' mean finish, return the name
        if (event.key.code == sf::Keyboard::Enter) {
          return nameInput;
        }
        // 'Backspace' to delete previous
        if (event.key.code == sf::Keyboard::BackSpace) {
          if (!nameInput.isEmpty()) {
            nameInput.erase(nameInput.getSize() - 1, 1);
            textDisplay.setString(nameInput);
          }
        }
      }
    }
    // Clear old frame and display user input
    window->clear();
    drawTexture(backgroundTexture, 0, 0);
    window->draw(textDisplay);
    window->display();
  }
  // Result in null if error happen
  nameInput = "";
  return nameInput;
};
