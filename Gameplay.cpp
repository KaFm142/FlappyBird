#include "Gameplay.h"

// Constructor
Gameplay::Gameplay() {
  // Initialize the variable
  score = 0;
  frame = 0;
  window->setTitle("GamePlay");
  pause = false;
  inAnimation = false;

  // Create and allocate Birds using new
  bird = new OriginalBird();

  // Create pipes;
  pipes = new Pipes *[5];
  for (int i = 0; i < 5; i++) {
    pipes[i] = new Pipes();
  }
  pipeTextures = new sf::Texture[5];
  pipeSprites = new sf::Sprite[5];
  pipePositions = new sf::Vector2f[5];
  // Display background and come to gaming state
  displayBackground();
}

// Destructor
Gameplay::~Gameplay() {
  delete bird;
  for (int i = 0; i < 5; i++) {
    delete pipes[i];
  }
  delete[] pipes;

  delete[] pipePositions;
  delete[] pipeSprites;
  delete[] pipeTextures;
}

// Display background and come to gaming state

void Gameplay::displayBackground() {
  // Load textures and set up the sprite
  backgroundTexture = Screen::loadTexture("resources/screen.jpg");
  birdTexture = Screen::loadTexture("resources/birds/originalBird.png");
  birdSprite.setTexture(birdTexture);
  birdSprite.setPosition(bird->getPosition());

  // Setup a clock for gaming purpose
  sf::Clock clock;

  bool obstancleSpawned = false;
  int usedPipes = 0;
  int spawnSec = 0;
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

    // Calculate elapsed time
    sf::Time inGame = clock.getElapsedTime();
    int second = static_cast<int>(inGame.asSeconds());

    if (second == spawnSec && !obstancleSpawned) {
      spawnSec += 5;
      obstancleSpawned = true;
      usedPipes = spawnObstancle();
      if (usedPipes <= -1) {
        std::cout << "fail to spawn" << std::endl;
      } else {
        std::cout << "using: " << usedPipes << std::endl;
      };

    } else {
      obstancleSpawned = false;
    }

    // Delete other pipe
    for (int i = 0; i < 5; i++) {
      if (i != usedPipes) {
        delete pipes[i];
        pipes[i] = new Pipes();
      }
    }

    // Set inAnimation back to false mean an action has been finished
    if (frame >= 60) {
      inAnimation = false;
    }

    // The game, variable will be update if the game is not pause
    if (!pause) {
      // Update pipes position
      for (int i = 0; i < 5; i++) {
        if (pipes[i]->getGapY() != 0 && pipes[i] != nullptr) {
          pipePositions[i] = pipeSprites[i].getPosition();
          pipePositions[i].x -= 4;
          pipeSprites[i].setPosition(pipePositions[i]);
        }
      }

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

    displayObstancle(usedPipes);

    window->draw(birdSprite);

    displayTime(second);
    displayScore();
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

void Gameplay::displayTime(int second) {
  sf::Font font;
  font.loadFromFile("resources/arial.ttf");

  sf::Text timeText;
  timeText.setString("Time: " + std::to_string(second));
  timeText.setFont(font);
  timeText.setCharacterSize(40);
  timeText.setFillColor(sf::Color::Yellow);
  timeText.setPosition(930, 10);

  window->draw(timeText);
}

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

int Gameplay::spawnObstancle() {
  std::random_device rand;
  std::mt19937 seed(rand());

  std::uniform_int_distribution<int> dist(10, 570);
  int obstancle_Y = dist(seed);

  for (int i; i < 5; i++) {
    if (pipes[i]->getGapY() == 0) {
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
void Gameplay::displayObstancle(int used) { window->draw(pipeSprites[used]); };