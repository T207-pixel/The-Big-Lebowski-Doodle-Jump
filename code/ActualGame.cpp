#include "ActualGame.h"

ActualGame::ActualGame() {}

int ActualGame::actualGamePlay(sf::RenderWindow &window, int &flag, Scores &scores){
    if (flag == 1){
        PlatformAppearanceProbability appearanceProbability;
        Map map(STARTPLATFORMQUANTITY, true, scores.getScoresConst(), appearanceProbability);
        Map nextMap(STARTPLATFORMQUANTITY, false, scores.getScoresConst(), appearanceProbability);
        Doodler doodler;
        Camera camera;
        GameEngine gameEngine;
        Font font;
        std::string scoresString;
        bool ifShouldCheckFlag = true;
        bool gameOverFlag = false;
        srand(static_cast<unsigned int>(time(nullptr)));

        camera.getView().setCenter(BACKGROUNDWIDTH / 2, BACKGROUNDHEIGHT / 2);
        camera.getView().reset(sf::FloatRect(0, 0, BACKGROUNDWIDTH, BACKGROUNDHEIGHT));

        while (gameOverFlag != true){
            window.setView(camera.getViewConst());
            window.clear();
            map.drawBackground(window);
            map.drawPlatforms(window);
            nextMap.drawPlatforms(window);
            doodler.drawDoodler(window);
            doodler.movementSides();
            doodler.animation();
            doodler.basicJump();

            gameEngine.gotOnPlatform(doodler, map.getPlatformVector(), map.getPlatformQuantityConst(), ifShouldCheckFlag);
            gameEngine.gotOnPlatform(doodler, nextMap.getPlatformVector(), nextMap.getPlatformQuantityConst(), ifShouldCheckFlag);

            camera.ifUpperThanCamLvl(doodler);
            camera.moveCamera(doodler, map.getMapSprite(), scores);
            camera.putDown(map, nextMap, doodler, scores, appearanceProbability);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            ifShouldCheckFlag = gameEngine.fall(camera.getView().getCenter().y, doodler.getDoodlerSprite().getPosition().y, doodler.getDoodlerHeightConst() / 2);
            gameOverFlag = gameEngine.gameOver(camera.getView().getCenter().y, doodler.getDoodlerSprite().getPosition().y, doodler.getDoodlerHeightConst() / 2);
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
            scores.drawScores(map.getMapSprite().getPosition().y, font.getText(), scoresString, window);
            window.display();
        }
        camera.resetCameraPosition();
        window.setView(camera.getViewConst());
        flag = 2;
    }
}