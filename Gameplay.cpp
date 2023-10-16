#include "Gameplay.h"

// Constructor
Gameplay::Gameplay() {
  // Initialize the variable
  score = 0;
  frame = 0;
  window->setTitle("GamePlay");
  pause = false;
  inAnimation = false;

  // Load the player selection
  load();

  // Set the background base on the save file
  if (choosenBackground == "1")
    backgroundTexture = Screen::loadTexture("resources/screenDark.jpg");
  else
    backgroundTexture = Screen::loadTexture("resources/screen.jpg");

  // Create and allocate Birds using new
  // Get the choosen bird base on the save file
  if (choosenBird == "0") {
    bird = new OriginalBird();
    birdTexture = Screen::loadTexture("resources/birds/OriginalBird.png");
    birdSprite.setTexture(birdTexture);
  } else if (choosenBird == "1") {
    bird = new Chicken();
    birdTexture = Screen::loadTexture("resources/birds/Chicken.png");
    birdSprite.setTexture(birdTexture);
  } else if (choosenBird == "2") {
    bird = new Penguin();
    birdTexture = Screen::loadTexture("resources/birds/Penguin.png");
    birdSprite.setTexture(birdTexture);
  } else if (choosenBird == "3") {
    bird = new Owl();
    birdTexture = Screen::loadTexture("resources/birds/Owl.png");
    birdSprite.setTexture(birdTexture);
  } else {
    bird = new Falcon();
    birdTexture = Screen::loadTexture("resources/birds/Falcon.png");
    birdSprite.setTexture(birdTexture);
  }

  // Create pipes;
  pipes = new Pipes *[2];
  for (int i = 0; i < 2; i++) {
    pipes[i] = new Pipes();
  }
  pipeTextures = new sf::Texture[2];
  pipeSprites = new sf::Sprite[2];
  pipePositions = new sf::Vector2f[2];

  // Set the bird variable based on the game mode
  bird->setSpeed(bird->getSpeed() * mode);

  // Display background and come to gaming state
  displayBackground();
}

// Destructor
Gameplay::~Gameplay() {
  delete bird;
  // Delete each pipes pointer and it self
  for (int i = 0; i < 2; i++) {
    delete pipes[i];
  }
  delete[] pipes;

  // Other delete
  delete[] pipePositions;
  delete[] pipeSprites;
  delete[] pipeTextures;
}

// Display background and come to gaming state
void Gameplay::displayBackground() {
  // Reset window position
  window->setPosition(sf::Vector2i(100, 200));
  // Set the initial position for the bird
  birdSprite.setPosition(bird->getPosition());

  // Setup a clock for gaming purpose
  sf::Clock clock;

  // Variable to control pipes
  int usedPipes = 0;
  bool pipeSpawned = false;

  // Spawn rate
  int spawnSec = 0;

  // Set up acceleration
  float accel = 0.2 + (static_cast<float>(mode) / 10.0);

  // Gameplay state
  while (window->isOpen()) {
    // Event holder
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

    // Calculate elapsed time
    sf::Time inGame = clock.getElapsedTime();
    int second = static_cast<int>(inGame.asSeconds());

    // Spawn pipes if meet requirement
    if (second == spawnSec && !pipeSpawned) {
      // Update the spawn
      spawnSec = spawnSec + (25 / bird->getSpeed());
      // Only spawn and update score if not pause
      if (!pause) {
        score++;

        pipeSpawned = true;
        // Spawn pipes
        usedPipes = spawnPipes();

        // Error display
        if (usedPipes <= -1) {
          std::cout << "fail to spawn pipes" << std::endl;
        } else {
          // Speed up bird for every pipes spawn
          bird->speedUp(accel);

          // Delete other pipes
          for (int i = 0; i < 2; i++) {
            if (i != usedPipes) {
              delete pipes[i];
              // Create new
              pipes[i] = new Pipes();
            }
          }
        };
      }
    } else {
      // Set this to false to prepare for new pipes spawn
      pipeSpawned = false;
    }

    // Set inAnimation back to false mean an action has been finished
    if (frame >= 40) {
      inAnimation = false;
    }

    // The game, variable will be update if the game is not pause
    if (!pause) {
      // Update pipes position
      for (int i = 0; i < 2; i++) {
        if (pipes[i]->getGapY() != 0 && pipes[i] != nullptr) {
          pipePositions[i] = pipeSprites[i].getPosition();
          pipePositions[i].x -= bird->getSpeed();
          pipeSprites[i].setPosition(pipePositions[i]);
          pipes[i]->setPosition(pipePositions[i]);
        }
      }

      // Get the position of bird
      birdPosition = birdSprite.getPosition();
      bird->setPosition(birdPosition);

      // Check for condition of losing
      if (birdPosition.x + 80 >= pipePositions[usedPipes].x ||
          birdPosition.y >= 560)
        checkColapse(usedPipes);

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
    displayObstancle(usedPipes);
    window->draw(birdSprite);
    displayTime(second);
    displayScore();
    displayHealth();
    window->display();
  }
}

// Handling event
void Gameplay::action(sf::Event event) {
  // The bird will fly if player hit 'space'
  if (event.key.code == sf::Keyboard::Space) {
    // Set to know that an action is take place
    inAnimation = true;
    bird->setFallSpeed(1);
    frame = 0;
  };

  // Pause the game if player hit 'esc'
  if (event.key.code == sf::Keyboard::Escape) pause = true;
  // Unpause if they hit any other key
  else if (event.type == sf::Event::KeyPressed)
    pause = false;
}

// Display time function
void Gameplay::displayTime(int second) {
  // Set up font
  sf::Font font;
  font.loadFromFile("resources/arial.ttf");

  // Set up text and display
  sf::Text timeText;
  // Set string
  timeText.setString("Time: " + std::to_string(second));
  timeText.setFont(font);
  timeText.setCharacterSize(40);
  timeText.setFillColor(sf::Color::Yellow);
  timeText.setPosition(930, 10);

  window->draw(timeText);
}

// Display score function
void Gameplay::displayScore() {
  sf::Font font;
  font.loadFromFile("resources/arial.ttf");

  sf::Text scoreText;
  scoreText.setString("Point: " + std::to_string(score));
  scoreText.setFont(font);
  scoreText.setCharacterSize(40);
  scoreText.setFillColor(sf::Color::Yellow);
  scoreText.setPosition(930, 60);

  window->draw(scoreText);
}

// Display health function
void Gameplay::displayHealth() {
  sf::Font font;
  font.loadFromFile("resources/arial.ttf");

  sf::Text healthText;
  healthText.setString("Health: " + std::to_string(bird->getHealth()));
  healthText.setFont(font);
  healthText.setCharacterSize(40);
  healthText.setFillColor(sf::Color::Yellow);
  healthText.setPosition(930, 110);

  window->draw(healthText);
};

// Endgame function
void Gameplay::endgame() {
  // Close the window
  window->close();
}

// Spawn pipes function
int Gameplay::spawnPipes() {
  // Set up random seed
  std::random_device rand;
  std::mt19937 seed(rand());

  // Take the random number generated
  std::uniform_int_distribution<int> dist(30, 400);
  int obstancle_Y = dist(seed);

  // Run a loop to choose a new pipes
  for (int i; i < 2; i++) {
    if (pipes[i]->getGapY() == 0) {
      // Set up the pipes
      pipeTextures[i] = Screen::loadTexture("resources/pipes.png");
      pipeSprites[i].setTexture(pipeTextures[i]);
      pipePositions[i].x = 1200;
      pipePositions[i].y = obstancle_Y - 532;

      pipes[i]->setPosition(pipePositions[i]);
      pipes[i]->setGapY(obstancle_Y);
      pipeSprites[i].setPosition(pipes[i]->getPosition());
      return i;
    }
  }
  return -1;
}

// Display pipes
void Gameplay::displayObstancle(int usedPipe) {
  window->draw(pipeSprites[usedPipe]);
};

// Check for collapsing
void Gameplay::checkColapse(int used) {
  // Create new variable to holp importain stat
  int birdEnd = birdPosition.x + 80;      // Bird rightmost Xvalue
  int gapStart = pipes[used]->getGapY();  // Where the gap start in Yvalue
  int pipesX = pipes[used]->getPosition().x;
  int pipeEnd = pipesX + 80;

  // Check for collapse
  if (birdEnd >= pipesX && birdEnd <= pipeEnd) {
    if (birdPosition.y <= gapStart || birdPosition.y >= gapStart + 100) {
      // If the bird has no health
      if (bird->hitObstance() == 0) {
        // Save game and end
        save();
        endgame();
      } else {
        // Else the bird will perform a "jump"
        birdPosition.x += 60;
        birdPosition.y -= 60;
        bird->setPosition(birdPosition);
      }
    }
  }
  // Check if bird hit ground
  if (birdPosition.y >= 570) {
    if (bird->hitObstance() == 0) {
      // Save and end game
      save();
      endgame();
    } else {
      // Perform bird "jump"
      birdPosition.y -= 100;
      bird->setPosition(birdPosition);
    }
  }
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

  // Get the Highscore in the save file
  int scoreSave = playerData["highscore"];

  // Save the new score only if that is higher than the save file
  if (scoreSave < score) {
    playerData["highscore"] = score;
  } else {
    // Else save the previous one
    playerData["highscore"] = scoreSave;
  }

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

// Load save file
void Gameplay::load() {
  // Open save file
  std::ifstream inputFile("save.json");
  if (inputFile.is_open()) {
    json playerData;
    // Get tha data and hold it to a temporary json
    inputFile >> playerData;
    // Load to the variable;
    mode = playerData["mode"];
    choosenBackground = playerData["background"];
    choosenBird = playerData["bird"];

    // Close the file
    inputFile.close();
  } else {
    // Error handling
    std::cerr << "error in loading" << std::endl;
  }
}