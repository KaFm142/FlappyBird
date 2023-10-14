#include "Gameplay.h"

Gameplay::Gameplay() {
  score = 0;
  time = 0;
  frame = 0;
  window->setTitle("GamePlay");
  bird = new OriginalBird();
  displayBackground();
}

Gameplay::~Gameplay() { delete bird; }

void Gameplay::displayBackground() {
  // Load textures and set up the sprite
  backgroundTexture = Screen::loadTexture("resources/screen.jpg");
  birdTexture = Screen::loadTexture("resources/birds/originalBird.png");
  birdSprite.setTexture(birdTexture);
  pause = false;
  inAnimation = false;
  while (window->isOpen()) {
    sf::Event event;

    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();
      }
      if (event.type == sf::Event::KeyPressed) {
        action(event);
      }
    }

    if (frame >= 60) {
      inAnimation = false;
    }

    if (!pause) {
      sf::Vector2f position = birdSprite.getPosition();
      bird->setPosition(position);

      if (position.y >= 540) {
        score++;

        save();
        endgame();
        break;
      }

      if (inAnimation) {
        bird->fly();
        position = bird->getPosition();
        frame++;
      } else {
        bird->fall();
        position = bird->getPosition();
      }
      birdSprite.setPosition(position);
    }
    window->clear();
    drawTexture(backgroundTexture, 0, 0);
    window->draw(birdSprite);
    window->display();
  }
}

void Gameplay::action(sf::Event event) {
  if (event.key.code == sf::Keyboard::Space) {
    score++;

    inAnimation = true;
    frame = 0;
  };

  if (event.key.code == sf::Keyboard::Escape)
    pause = true;
  else if (event.type == sf::Event::KeyPressed)
    pause = false;
}

void Gameplay::save() {
  json playerData;

  std::ifstream inputFile("save.json");
  if (inputFile.is_open()) {
    inputFile >> playerData;
    inputFile.close();
  }
  int curScore = playerData["highscore"];

  std::cout << "Cur" << curScore << std::endl;
  curScore += score;
  playerData["highscore"] = curScore;

  std::cout << score << std::endl;
  playerData["name"] = "KaFm";

  std::ofstream outputFile("save.json");
  if (outputFile.is_open()) {
    outputFile << playerData.dump(4);
    outputFile.close();
  } else {
    std::cerr << "error in saving" << std::endl;
  }
}

void Gameplay::endgame() {
  // Animation

  window->close();
}
