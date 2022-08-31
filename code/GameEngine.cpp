#pragma once
#include "GameEngine.h"
#include "Settings.h"

void GameEngine::gotOnPlatform(Doodler &doodler, std::vector<Platform*> &platform, float platformQuantity, const bool ifShouldCheck){
    if (ifShouldCheck){
        for (int i = 0; i < platformQuantity; i++) {
            bool flag = collision(doodler, platform, platformQuantity, i);
            if (flag && (strcmp(platform[i]->getPlatformType(), "usualPlatform") == 0 || flag && strcmp(platform[i]->getPlatformType(), "horizontalPlatform") == 0)){
                doodler.setDoodlerSpeedY(STARTSPEEDY);
                doodler.basicJump();
            }
            if (flag && strcmp(platform[i]->getPlatformType(), "fallingPlatform") == 0) {
                if (dynamic_cast<FallingPlatform *>(platform[i])->getFallingSpeedConst() < MIDDLEFALLINGPLATFORMSPEED)
                    dynamic_cast<FallingPlatform *>(platform[i])->setPlatformFallingSpeed(MIDDLEFALLINGPLATFORMSPEED);
            }
            if (flag && strcmp(platform[i]->getPlatformType(), "disappearingPlatform") == 0){
                doodler.setDoodlerSpeedY(STARTSPEEDY);
                doodler.basicJump();
                dynamic_cast<DisappearingPlatform*>(platform[i])->setPositiveFlag();
            }
            if (flag && strcmp(platform[i]->getPlatformType(), "removablePlatform") == 0){
                doodler.setDoodlerSpeedY(STARTSPEEDY);
                doodler.basicJump();
                dynamic_cast<RemovablePlatform*>(platform[i])->setPositiveFlag();
            }
            if (flag && strcmp(platform[i]->getPlatformType(), "twitchingPlatform") == 0){
                doodler.setDoodlerSpeedY(STARTSPEEDY);
                doodler.basicJump();
                dynamic_cast<TwitchingPlatform*>(platform[i])->setPositiveFlag();
            }
        }
    }
}

bool GameEngine::collision(Doodler &doodler, std::vector<Platform*> platform, float platformQuantity, int &i){
    if (doodler.getDoodlerSprite().getPosition().y + doodler.getDoodlerHeightConst() / 2 >=
        platform[i]->getPlatformSpriteConst().getPosition().y &&
        doodler.getDoodlerSprite().getPosition().y + doodler.getDoodlerHeightConst() / 2 <=
        platform[i]->getPlatformSpriteConst().getPosition().y + platform[i]->getPlatformHeightConst() / 2 &&
        //X AXIS
        //IF MOVING TO THE RIGHT
        ((//if right part of doodler is on platform (23 == offsetNose)
                 doodler.getDoodlerSpriteConst().getPosition().x + doodler.getDoodlerWidthConst() / 2 -
                 doodler.getDoodlerRightOffsetConst() >=
                 platform[i]->getPlatformSpriteConst().getPosition().x -
                 platform[i]->getPlatformWidthConst() / 2 &&
                 doodler.getDoodlerSpriteConst().getPosition().x + doodler.getDoodlerWidthConst() / 2 -
                 doodler.getDoodlerRightOffsetConst() <= platform[i]->getPlatformSpriteConst().getPosition().x +
                                                         platform[i]->getPlatformWidthConst() / 2
         ) || (//if left part of doodler is on platform () (12 == offsetBack)
                 doodler.getDoodlerSpriteConst().getPosition().x -
                 doodler.getDoodlerWidthConst() / 2 + doodler.getDoodlerLeftOffsetConst() >=
                 platform[i]->getPlatformSpriteConst().getPosition().x -
                 platform[i]->getPlatformWidthConst() / 2 &&
                 doodler.getDoodlerSpriteConst().getPosition().x -
                 doodler.getDoodlerWidthConst() / 2 +
                 doodler.getDoodlerLeftOffsetConst() <=
                 platform[i]->getPlatformSpriteConst().getPosition().x +
                 platform[i]->getPlatformWidthConst() / 2
         )) &&
        //falling down
        doodler.getDoodlerSpeedYConst() >= 0){
        return true;
    }
}

void GameEngine::fallingPlatformAnimation(std::vector<Platform*> &platform){
    for (auto &i: platform){
        if (strcmp(i->getPlatformType(), "fallingPlatform") == 0){
            if (dynamic_cast<FallingPlatform *>(i)->getFallingSpeedConst() != 0){
                //third step (changing frames in new texture)
                if (dynamic_cast<FallingPlatform *>(i)->getFallingSpeedConst() <= MIDDLEFALLINGPLATFORMSPEED + (ACCELERATION * QUANTITYOFFRAMESFALLPLAT) && dynamic_cast<FallingPlatform *>(i)->getFallingSpeedConst() > MIDDLEFALLINGPLATFORMSPEED + ACCELERATION){
                    // moving frames in tileset
                    dynamic_cast<FallingPlatform *>(i)->moveFallingPlatformsFrames();
                }
                //second step (move and change texture)
                if (dynamic_cast<FallingPlatform *>(i)->getFallingSpeedConst() == MIDDLEFALLINGPLATFORMSPEED + ACCELERATION){
                    // set texture with tileset
                    dynamic_cast<FallingPlatform *>(i)->setFallingPlatformTexture();
                }
                //first step (move and increase speed)
                dynamic_cast<FallingPlatform *>(i)->getPlatformSprite().move(0, dynamic_cast<FallingPlatform *>(i)->getFallingSpeedConst());
                dynamic_cast<FallingPlatform *>(i)->setPlatformFallingSpeed(dynamic_cast<FallingPlatform *>(i)->getFallingSpeedConst() + ACCELERATION);
            }
        }
    }
}

void GameEngine::HorizontalPlatformMoving(std::vector<Platform*> &platform, const int scores){
    for (auto &i : platform){
        if (strcmp(i->getPlatformType(), "horizontalPlatform") == 0){
            dynamic_cast<HorizontalPlatform *>(i)->moveHorizontalPlatform(scores);
        }
    }
}

void GameEngine::DisappearingPlatformMechanic(std::vector<Platform*> &platform){
    for (auto &i : platform){
        if (strcmp(i->getPlatformType(), "disappearingPlatform") == 0){
            if (dynamic_cast<DisappearingPlatform *>(i)->getFlag() == true){
                dynamic_cast<DisappearingPlatform*>(i)->increaseFrames();
                if (dynamic_cast<DisappearingPlatform*>(i)->getFramesCounter() % 10 == 0 && dynamic_cast<DisappearingPlatform*>(i)->getFramesCounter() < 50){
                    dynamic_cast<DisappearingPlatform*>(i)->increaseTransparency();
                    dynamic_cast<DisappearingPlatform*>(i)->getPlatformSprite().setColor(sf::Color(255, 255, 255 , dynamic_cast<DisappearingPlatform*>(i)->getTransparency()));
                    dynamic_cast<DisappearingPlatform*>(i)->increaseComparable();
                }
                if (dynamic_cast<DisappearingPlatform*>(i)->getFramesCounter() >= dynamic_cast<DisappearingPlatform*>(i)->getComparable() && dynamic_cast<DisappearingPlatform*>(i)->getFramesCounter() == 50){
                    //std::cout << "50 stable\n";
                    dynamic_cast<DisappearingPlatform*>(i)->getPlatformSprite().move(2 * BACKGROUNDWIDTH, 0);
                    dynamic_cast<DisappearingPlatform*>(i)->resetFrames();
                    dynamic_cast<DisappearingPlatform*>(i)->resetComparable();
                    dynamic_cast<DisappearingPlatform*>(i)->resetTransparency();
                    dynamic_cast<DisappearingPlatform*>(i)->setNegativeFlag();
                    dynamic_cast<DisappearingPlatform*>(i)->getPlatformSprite().setColor(sf::Color(255, 255, 255 , dynamic_cast<DisappearingPlatform*>(i)->getTransparency()));
                }
            }
        }
    }
}

bool GameEngine::removablePlatformMechanic(std::vector<Platform*> &platform, int flagTmp){
    for (auto i : platform){
        if (strcmp(i->getPlatformType(), "removablePlatform") == 0){
            if (flagTmp == 2)
                return false;
            if (dynamic_cast<RemovablePlatform*>(i)->getFlag() == true || flagTmp  == 1){
                //std::cout << "Frames quantity: " << dynamic_cast<RemovablePlatform*>(i)->getFrames() << " Stroka: " << stroka << "\n";
                dynamic_cast<RemovablePlatform*>(i)->increaseFrames();
                if (dynamic_cast<RemovablePlatform*>(i)->getFrames() % 10 == 0 && dynamic_cast<RemovablePlatform*>(i)->getFrames() < 60 && dynamic_cast<RemovablePlatform*>(i)->getTransparency() > 0){
                    for (auto j : platform){
                        if (strcmp(j->getPlatformType(), "removablePlatform") == 0){
                            dynamic_cast<RemovablePlatform*>(j)->increaseTransparency();
                            dynamic_cast<RemovablePlatform*>(j)->getPlatformSprite().setColor(sf::Color(255, 255, 255 , dynamic_cast<RemovablePlatform*>(j)->getTransparency()));
                        }
                    }
                }
                if (dynamic_cast<RemovablePlatform*>(i)->getFrames() % 10 == 0 && dynamic_cast<RemovablePlatform*>(i)->getFrames() == 60){
                    for (auto j : platform){
                        if (strcmp(j->getPlatformType(), "removablePlatform") == 0)
                            dynamic_cast<RemovablePlatform*>(j)->setRandomPosition();
                    }
                }
                if (dynamic_cast<RemovablePlatform*>(i)->getFrames() % 10 == 0 && dynamic_cast<RemovablePlatform*>(i)->getFrames() < 120 && dynamic_cast<RemovablePlatform*>(i)->getFrames() > 60){
                    for (auto j : platform){
                        if (strcmp(j->getPlatformType(), "removablePlatform") == 0){
                            dynamic_cast<RemovablePlatform*>(j)->decreaseTransparency();
                            dynamic_cast<RemovablePlatform*>(j)->getPlatformSprite().setColor(sf::Color(255, 255, 255 , dynamic_cast<RemovablePlatform*>(j)->getTransparency()));
                        }
                    }
                }
                if (dynamic_cast<RemovablePlatform*>(i)->getFrames() % 10 == 0 && dynamic_cast<RemovablePlatform*>(i)->getFrames() == 120){
                    for (auto j : platform){
                        if (strcmp(j->getPlatformType(), "removablePlatform") == 0){
                            dynamic_cast<RemovablePlatform*>(j)->resetTransparency();
                            dynamic_cast<RemovablePlatform*>(j)->resetFrames();
                            dynamic_cast<RemovablePlatform*>(j)->setNegativeFlag();
                            dynamic_cast<RemovablePlatform*>(j)->getPlatformSprite().setColor(sf::Color(255, 255, 255 , dynamic_cast<RemovablePlatform*>(j)->getTransparency()));
                        }
                    }
                }
            return true;
            }
        }
    }
}

bool GameEngine::twitchingPlatformMechanic(std::vector<Platform*> &platform, bool flagTmp){
    for (auto i : platform){
        if (strcmp(i->getPlatformType(), "twitchingPlatform") == 0 && dynamic_cast<TwitchingPlatform*>(i)->getFlag() || flagTmp){
            for (auto j : platform){
                if (strcmp(j->getPlatformType(), "twitchingPlatform") == 0){
                    dynamic_cast<TwitchingPlatform*>(j)->checkTwitchDirection();
                    dynamic_cast<TwitchingPlatform*>(j)->twitch();
                }
            }
            return true;
        }
    }
}

bool GameEngine::fall(const float currentCenter, const float doodlerPositionY, const float doodlerHalf){
    if (doodlerPositionY > currentCenter + BACKGROUNDHEIGHT / 2 - doodlerHalf)
        return false;
}

bool GameEngine::gameOver(const float currentCenter, const float doodlerPositionY, const float doodlerHalf){
    if (doodlerPositionY > currentCenter + BACKGROUNDHEIGHT / 2 + doodlerHalf)
        return true;
}


