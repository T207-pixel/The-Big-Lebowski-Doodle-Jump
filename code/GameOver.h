#pragma once
#include "Settings.h"
#include "Scores.h"

class GameOver{
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Texture playButtonTexture;
    sf::Sprite playButtonSprite;
    sf::Texture menuButtonTexture;
    sf::Sprite menuButtonSprite;
    sf::Mouse mouse;
    sf::View camera;
    void drawGameOverMenu(sf::RenderWindow &window, Scores &currentScore, Scores &bestScore) const;
    bool ifPlayButtonIsPressed(sf::RenderWindow &window) const;
    bool ifMenuButtonIsPressed(sf::RenderWindow &window) const;
    void buttonAnimation(sf::RenderWindow &window, const char *string, Scores &currentScore, Scores &bestScore);
public:
    GameOver();
    void gameOverMechanic(sf::RenderWindow &window, int &flag, Scores &currentScore, Scores &bestScore);
};