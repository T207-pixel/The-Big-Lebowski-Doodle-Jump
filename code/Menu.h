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
    void buttonAnimation(sf::RenderWindow &window); //animation of button should go in parallel with lebowski in the beginning
public:
    Menu();
    void menuMechanic(sf::RenderWindow &window, int &flag);
};