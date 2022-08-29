#pragma once
#include "Platform.h"
#include <iostream>
#include <utility>

float getRandomNumber(float min, float max){
    static const double number = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    int tailI = rand();
    tailI = tailI % 100;
    float tailF = static_cast<float>(tailI);
    tailF = tailF * 0.01;
    return (rand() * number * (max - min) + min + tailF);
}

int positiveOrNegativeUnit(){
    int number = rand();
    if (number % 2 == 0)
        return 1;
    else
        return -1;
}

Platform::Platform(const float &layerHeight, const float &current, bool flag, const char* fileName){
    platformTexture.loadFromFile(fileName);
    platformSprite.setTexture(platformTexture);
    platformWidth = platformSprite.getLocalBounds().width;
    platformHeight = platformSprite.getLocalBounds().height;
    platformSprite.setOrigin(platformWidth / 2, platformHeight / 2);//puts center
    setPlatformRandomPosition(layerHeight, current, flag);
}

Platform::Platform(const Platform* otherPlatform, const char* fileMame) : platformTexture(otherPlatform->platformTexture),
    platformSprite(otherPlatform->platformSprite), platformWidth(otherPlatform->platformWidth), platformHeight(otherPlatform->platformHeight){
    //platformSprite.setTexture(platformTexture);
    platformSprite.move(0, BACKGROUNDHEIGHT);
}

void Platform::setPlatformRandomPosition(const float &layerHeight, const float &current, bool flag){
    float xPlatformLeftBound = platformWidth / 2;
    float xPlatformRightBound = BACKGROUNDWIDTH - platformWidth / 2;
    float xRandomCoordinate = getRandomNumber(xPlatformLeftBound, xPlatformRightBound);
    if (flag)
        setLowerMapPlatforms(xRandomCoordinate, layerHeight, current);
    else {
        setUpperMapPlatforms(xRandomCoordinate, layerHeight, current);
    }
}

void Platform::setLowerMapPlatforms(const float &xRandomCoordinate, const float &layerHeight, const float &current){
    float yHigherBound = (BACKGROUNDHEIGHT - current * layerHeight) + platformHeight / 2;
    float yLowerBound = (BACKGROUNDHEIGHT - (current - 1) * layerHeight) - platformHeight / 2;
    float yRandomCoordinate = getRandomNumber(yHigherBound, yLowerBound);
    platformSprite.setPosition(xRandomCoordinate, yRandomCoordinate);
}

void Platform::setUpperMapPlatforms(const float &xRandomCoordinate, const float &layerHeight, const float &current){
    float yHigherBound = ((-1) * BACKGROUNDHEIGHT + (current - 1) * layerHeight) + platformHeight / 2;
    float yLowerBound = ((-1) * BACKGROUNDHEIGHT + current * layerHeight) - platformHeight / 2;
    float yRandomCoordinate = getRandomNumber(yHigherBound, yLowerBound);
    platformSprite.setPosition(xRandomCoordinate, yRandomCoordinate);
}

const sf::Sprite &Platform::getPlatformSpriteConst() const{
    return platformSprite;
}

sf::Sprite &Platform::getPlatformSprite(){
    return platformSprite;
}

void Platform::setPlatformPositionY(const float &positionY){
    platformSprite.setPosition(platformSprite.getPosition().x, positionY);
}

void Platform::setPlatformPositionX(const float &positionX){
    platformSprite.setPosition(positionX, platformSprite.getPosition().y);
}

const float &Platform::getPlatformHeightConst() const{
    return platformHeight;
}

const float &Platform::getPlatformWidthConst() const{
    return platformWidth;
}

const char* Platform::getPlatformType() const{
    return "usualPlatform";
}
