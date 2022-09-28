#include "GameOver.h"

GameOver::GameOver(){
    backgroundTexture.loadFromFile(FILENAMEGAMEOVER);
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setOrigin(BACKGROUNDWIDTH / 2, BACKGROUNDHEIGHT / 2);
    backgroundSprite.setPosition(BACKGROUNDWIDTH / 2, BACKGROUNDHEIGHT / 2);

    playButtonTexture.loadFromFile(FILENAMEPLAYAGAINBUTTON);
    playButtonSprite.setTexture(playButtonTexture);
    playButtonSprite.setOrigin(playButtonSprite.getLocalBounds().width / 2, playButtonSprite.getLocalBounds().height / 2);
    playButtonSprite.setPosition(135, 910);

    menuButtonTexture.loadFromFile(FILENAMEMENUBUTTON);
    menuButtonSprite.setTexture(menuButtonTexture);
    menuButtonSprite.setOrigin(menuButtonSprite.getLocalBounds().width / 2, menuButtonSprite.getLocalBounds().height / 2);
menuButtonSprite.setPosition(470, 905);
}

void GameOver::gameOverMechanic(sf::RenderWindow &window, int &flag, Scores &currentScore, Scores &bestScore){
    if (flag == 2){
        if (currentScore.getScores() > bestScore.getScores()){
            bestScore.setScores(currentScore.getScores());
            bestScore.storeInFile(currentScore.getScores());
        }
        drawGameOverMenu(window, currentScore, bestScore);
        if (ifPlayButtonIsPressed(window)){
            flag = 1;
            buttonAnimation(window, "playButton", currentScore, bestScore);
            currentScore.setScores(0);
        }
        else if (ifMenuButtonIsPressed(window)){
            flag = 0;
            buttonAnimation(window, "menuButton", currentScore, bestScore);
            currentScore.setScores(0);
        }
        playButtonSprite.setColor(sf::Color(255, 255, 255, 255));
        menuButtonSprite.setColor(sf::Color(255, 255, 255, 255));
    }
}

void GameOver::drawGameOverMenu(sf::RenderWindow &window, Scores &currentScore, Scores &bestScore) const{
    Font font;
    std::string scoresString;
    window.draw(backgroundSprite);
    window.draw(playButtonSprite);
    window.draw(menuButtonSprite);
    currentScore.drawGameOverScore(170, 270, 37, font.getText(), scoresString, window);
    bestScore.drawGameOverScore(255, 216, 37, font.getText(), scoresString, window);
    window.display();
}

bool GameOver::ifPlayButtonIsPressed(sf::RenderWindow &window) const{
    if (mouse.isButtonPressed(sf::Mouse::Left) &&
        mouse.getPosition(window).x >= playButtonSprite.getPosition().x - playButtonSprite.getLocalBounds().width / 2 &&
        mouse.getPosition(window).x <= playButtonSprite.getPosition().x + playButtonSprite.getLocalBounds().width / 2 &&
        mouse.getPosition(window).y >= playButtonSprite.getPosition().y - playButtonSprite.getLocalBounds().height / 2 &&
        mouse.getPosition(window).y <= playButtonSprite.getPosition().y + playButtonSprite.getLocalBounds().height / 2){
        //debug mes
        std::cout << "pressed play\n";
        return true;
    }
    return false;
}

bool GameOver::ifMenuButtonIsPressed(sf::RenderWindow &window) const{
    if (mouse.isButtonPressed(sf::Mouse::Left) &&
        mouse.getPosition(window).x >= menuButtonSprite.getPosition().x - menuButtonSprite.getLocalBounds().width / 2 &&
        mouse.getPosition(window).x <= menuButtonSprite.getPosition().x + menuButtonSprite.getLocalBounds().width / 2 &&
        mouse.getPosition(window).y >= menuButtonSprite.getPosition().y - menuButtonSprite.getLocalBounds().height / 2 &&
        mouse.getPosition(window).y <= menuButtonSprite.getPosition().y + menuButtonSprite.getLocalBounds().height / 2){
        //debug mes
        std::cout << "pressed menu\n";
        return true;
    }
    return false;
}

void GameOver::buttonAnimation(sf::RenderWindow &window, const char *string, Scores &currentScore, Scores &bestScore){
    float frames = 50.0;
    int transparency = 255;
    while (frames != 0){
        if (static_cast<int>(frames) % 10 == 0){
            transparency -= 50;
            if (strcmp(string, "menuButton") == 0)
                menuButtonSprite.setColor(sf::Color(255, 255, 255, transparency));
            else if (strcmp(string, "playButton") == 0)
                playButtonSprite.setColor(sf::Color(255, 255, 255, transparency));
        }
        frames--;
        drawGameOverMenu(window, currentScore, bestScore);
    }
}