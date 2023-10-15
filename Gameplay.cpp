#include "Gameplay.h"

// Constructor
Gameplay::Gameplay() {
  // Initialize the variable
  score = 0;
  time = 0;
  frame = 0;
  window->setTitle("GamePlay");
  pause = false;
  inAnimation = false;

  // Create and allocate Birds using new
  bird = new OriginalBird();
  // Display background and come to gaming state
  displayBackground();
}

// Destructor to delete Birds
Gameplay::~Gameplay() { delete bird; }

// Display background and come to gaming state

void Gameplay::displayBackground() {
  // Load textures and set up the sprite
  backgroundTexture = Screen::loadTexture("resources/screen.jpg");
  birdTexture = Screen::loadTexture("resources/birds/originalBird.png");
  birdSprite.setTexture(birdTexture);

  // Gameplay state
  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        // Close the window if player want to exit
        window->close();
      }
      // handling user input using other function
      if (event.type == sf::Event::KeyPressed) {
        action(event);
      }
    }

    // Set inAnimation back to false mean an action has been finished
    if (frame >= 60) {
      inAnimation = false;
    }

    // The game, variable will be update if the game is not pause
    if (!pause) {
      // Get the position
      birdPosition = birdSprite.getPosition();
      bird->setPosition(birdPosition);

      // Check for condition of losing
      if (birdPosition.y >= 540) {
        // Save the progress
        save();
        endgame();
        break;
      }

      // Check if an action is currently happen
      if (inAnimation) {
        // Update the bird position
        bird->fly();
        birdPosition = bird->getPosition();
        // Adding to frame condition
        frame++;
      } else {
        // If no action was take place, bird is falling
        bird->fall();
        birdPosition = bird->getPosition();
      }
      // Set new position for bird
      birdSprite.setPosition(birdPosition);
    }

    // clear old frame and display new
    window->clear();
    drawTexture(backgroundTexture, 0, 0);
    window->draw(birdSprite);
    window->display();
  }
}

// Handling event
void Gameplay::action(sf::Event event) {
  // The bird will fly if player hit 'space'
  if (event.key.code == sf::Keyboard::Space) {
    score++;
    // Set to know that an action is take place
    inAnimation = true;
    frame = 0;
  };

  // Pause the game if player hit 'esc'
  if (event.key.code == sf::Keyboard::Escape) pause = true;
  // Unpause if they hit any other key
  else if (event.type == sf::Event::KeyPressed)
    pause = false;
}

// Save the game
void Gameplay::save() {
  // Temporary save data holder
  json playerData;

  // Open the save file
  std::ifstream inputFile("save.json");
  if (inputFile.is_open()) {
    // Take the player data
    inputFile >> playerData;
    inputFile.close();
  }
  // get the Highscore in the save file
  int scoreSave = playerData["highscore"];

  std::cout << "save: " << scoreSave << std::endl;
  // Save the new score only if that is higher than the save file
  if (scoreSave < score) {
    playerData["highscore"] = score;
  } else {
    // else save the previous one
    playerData["highscore"] = scoreSave;
  }

  std::cout << score << std::endl;

  // Open the save file
  std::ofstream outputFile("save.json");
  if (outputFile.is_open()) {
    // Save the data back to the file
    outputFile << playerData.dump(4);
    outputFile.close();
  } else {
    std::cerr << "error in saving" << std::endl;
  }
}

// Endgame functiom
void Gameplay::endgame() {
  // Animation


  // Close the window
  window->close();
}
