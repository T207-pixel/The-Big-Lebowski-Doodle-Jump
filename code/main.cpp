#include "Settings.h"
#include "Map.h"
#include "Doodler.h"
#include "GameEngine.h"
#include "Camera.h"
#include "Scores.h"
#include <iostream>
//#include <ctime>

std::string outputBanana(){     // 50% probability
    std::cout << "BANANA\n";
}

std::string outputApple(){      // 50% probability
    std::cout << "Apple\n";
}

int main() {
    /*srand(static_cast<unsigned int>(time(0)));
    int apllleNum = rand() % 100;   //11
    int banana = rand() % 100;  //98
    if (apllleNum > 0 && apllleNum <= 50)
        outputBanana();
    else
        outputApple();
    return 0;*/
    srand(static_cast<unsigned int>(time(0)));
    sf::RenderWindow window(sf::VideoMode(BACKGROUNDWIDTH, BACKGROUNDHEIGHT), "Doodle jump");
    window.setFramerateLimit(FRAMELIMIT);

    Scores scores;
    Map map(STARTPLATFORMQUANTITY, true, scores.getScoresConst());
    Map nextMap(STARTPLATFORMQUANTITY, false, scores.getScoresConst());
    Doodler doodler;
    Camera camera;
    GameEngine gameEngine;


    camera.getView().setCenter(BACKGROUNDWIDTH / 2, BACKGROUNDHEIGHT / 2);
    camera.getView().reset(sf::FloatRect(0, 0, BACKGROUNDWIDTH, BACKGROUNDHEIGHT));
    while (window.isOpen()){
        //clock_t t1 = clock();
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.setView(camera.getViewConst());
        window.clear();
        map.drawBackground(window);
        map.drawPlatforms(window);
        nextMap.drawPlatforms(window);
        doodler.drawDoodler(window);
        doodler.movementSides();
        doodler.animation();
        doodler.basicJump();

        gameEngine.gotOnPlatform(doodler, map.getPlatformVector(), map.getPlatformQuantityConst());
        gameEngine.gotOnPlatform(doodler, nextMap.getPlatformVector(), nextMap.getPlatformQuantityConst());

        camera.ifUpperThanCamLvl(doodler);
        camera.moveCamera(doodler, map.getMapSprite(), scores);
        camera.putDown(map, nextMap, doodler, scores);
///////////////////////////////////////////////////////////////////////////////////////////////////////////
        gameEngine.fallingPlatformAnimation(map.getPlatformVector());
        gameEngine.fallingPlatformAnimation(nextMap.getPlatformVector());

        gameEngine.HorizontalPlatformMoving(map.getPlatformVector(), scores.getScoresConst());
        gameEngine.HorizontalPlatformMoving(nextMap.getPlatformVector(), scores.getScoresConst());

        gameEngine.DisappearingPlatformMechanic(map.getPlatformVector());
        gameEngine.DisappearingPlatformMechanic(nextMap.getPlatformVector());

        bool checkFlag1 = gameEngine.removablePlatformMechanic(map.getPlatformVector(), 0);
        gameEngine.removablePlatformMechanic(nextMap.getPlatformVector(), checkFlag1 ? 1 : 2);

        bool checkFlag2 = gameEngine.twitchingPlatformMechanic(map.getPlatformVector());
        gameEngine.twitchingPlatformMechanic(nextMap.getPlatformVector(), checkFlag2);
////////////////////////////////////////////////////////////////////////////////////////////////////////////
        scores.printScores();

        window.display();
        //std::cout << "FPS: " << CLOCKS_PER_SEC / static_cast<double>((clock() - t1) * 10) << "\n";
    }
    return 0;
}
