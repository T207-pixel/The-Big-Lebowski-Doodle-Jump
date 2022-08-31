#include "Menu.h"

Menu::Menu() {
    menuTexture.loadFromFile(FILEMAMEMENU);
    menuSprite.setTexture(menuTexture);
    menuSprite.setOrigin(BACKGROUNDWIDTH / 2, BACKGROUNDHEIGHT / 2);
    menuSprite.setPosition(menuSprite.getOrigin());
    playButtonTexture.loadFromFile(FILENAMEPLAYBUTTON);
    playButtonSprite.setTexture(playButtonTexture);
    playButtonSprite.setOrigin(playButtonSprite.getLocalBounds().width / 2, playButtonSprite.getLocalBounds().height / 2);
    playButtonSprite.setPosition(385, 900);
}

void Menu::menuMechanic(sf::RenderWindow &window, int &flag){
     if (flag == 0){
        drawMenu(window);
        if (ifButtonIsPressed(window)){
            //ANIMATION
            flag = 1;
        }
    }
}

void Menu::drawMenu(sf::RenderWindow &window) const{
    window.draw(menuSprite);
    window.draw(playButtonSprite);
    window.display();
}

bool Menu::ifButtonIsPressed(sf::RenderWindow &window) const{
    if (mouse.isButtonPressed(sf::Mouse::Left) &&
        mouse.getPosition(window).y >= playButtonSprite.getPosition().y - playButtonSprite.getLocalBounds().height / 2 &&
        mouse.getPosition(window).y <= playButtonSprite.getPosition().y + playButtonSprite.getLocalBounds().height / 2 &&
        mouse.getPosition(window).x >= playButtonSprite.getPosition().x - playButtonSprite.getLocalBounds().width / 2 &&
        mouse.getPosition(window).x <= playButtonSprite.getPosition().x + playButtonSprite.getLocalBounds().width / 2){
        std::cout << "pressed\n";
        return true;
    }
}

