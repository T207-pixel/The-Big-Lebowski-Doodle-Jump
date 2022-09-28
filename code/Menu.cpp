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
            flag = 1;
            buttonAnimation(window);
            //doodler animation
            menuAnimation(window);
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

void Menu::buttonAnimation(sf::RenderWindow &window){
    float frames = 50.0;
    int transparency = 255;
    while (frames != 0){
        if (static_cast<int>(frames) % 10 == 0){
            transparency -= 50;
            playButtonSprite.setColor(sf::Color(255, 255, 255, transparency));
        }
        frames--;
        drawMenu(window);
    }
    transparency = 0;
    while (frames < 50){
        if (static_cast<int>(frames) % 10 == 0){
            transparency += 50;
            playButtonSprite.setColor(sf::Color(255, 255, 255, transparency));
        }
        frames++;
        drawMenu(window);
    }
}

void Menu::menuAnimation(sf::RenderWindow &window){
    for (int j = 0; j < 6; j++){
        for (int i = 0; i < 9; i++){
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            menuSprite.move(-1 * (BACKGROUNDWIDTH), 0);
            drawMenu(window);
            if (i == 8)
                menuSprite.move(BACKGROUNDWIDTH * 10, -1 * BACKGROUNDHEIGHT);
        }
    }
    menuSprite.setOrigin(BACKGROUNDWIDTH / 2, BACKGROUNDHEIGHT / 2);
    menuSprite.setPosition(menuSprite.getOrigin());
}
