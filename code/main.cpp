#include "Settings.h"
#include "ActualGame.h"
#include "Menu.h"
#include "GameOver.h"

int main() {
    Scores currentScore;
    Scores bestScore;
    bestScore.loadFromFile();
    int flag = 0;
    Menu menu;
    ActualGame actualGame;
    GameOver gameOver;
    sf::RenderWindow window(sf::VideoMode(BACKGROUNDWIDTH, BACKGROUNDHEIGHT), "Doodle jump");
    window.setFramerateLimit(FRAMELIMIT);
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        menu.menuMechanic(window, flag);
        actualGame.actualGamePlay(window, flag, currentScore);
        gameOver.gameOverMechanic(window, flag, currentScore, bestScore);
    }
    return 0;
}
