#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include <cstdlib>
#include <ctime>

float getRandomNumber(float min, float max);
int positiveOrNegativeUnit();

class Platform{
protected:
    sf::Texture platformTexture;
    sf::Sprite platformSprite;
    float platformWidth;
    float platformHeight;
public:
    Platform(const float &layerHeight, const float &current, bool flag, const char* fileName = FILENAMEPLATFORM);
    Platform(const Platform* otherPlatform, const char* fileMame = FILENAMEPLATFORM);
    void setPlatformRandomPosition(const float &layerHeight, const float &current, bool flag);
    void setLowerMapPlatforms(const float &xRandomCoordinate, const float &layerHeight, const float &current);
    void setUpperMapPlatforms(const float &xRandomCoordinate, const float &layerHeight, const float &current);
    const sf::Sprite &getPlatformSpriteConst() const;
    virtual sf::Sprite &getPlatformSprite();//virtual is new
    const float &getPlatformHeightConst() const;
    virtual const float &getPlatformWidthConst() const;//virtual is new
    void setPlatformPositionY(const float &positionY);
    void setPlatformPositionX(const float &positionX);
    virtual const char* getPlatformType() const;
};