#include "Settings.h"

class Menu{
private:
    sf::Texture menuTexture;
    sf::Sprite menuSprite;
    sf::Texture playButtonTexture;
    sf::Sprite playButtonSprite;
    sf::Mouse mouse;
    void drawMenu(sf::RenderWindow &window) const;
    bool ifButtonIsPressed(sf::RenderWindow &window) const;
    void menuAnimation(); //haven't done yet
public:
    Menu();
    void menuMechanic(sf::RenderWindow &window, int &flag);
};