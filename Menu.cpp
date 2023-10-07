#include "Menu.h"

Menu::Menu() : Screen(){};

Menu::Menu(float height, float width) : Screen(height, width){};

Menu::~Menu() { delete window; };

void Menu::displayBackground(){

    backgroundTexture.loadFromFile("resources/menu.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    
    while(window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window->close();
            }
        }
        window->clear();
        window->draw(backgroundSprite);
        window->display();
    }
}

void Menu::action(){};