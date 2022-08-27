#include "RemovablePlatform.h"

RemovablePlatform::RemovablePlatform(const float &layerHeight, const float &current, bool flag, const char* fileName)
    : Platform(layerHeight, current, flag, fileName), frames(0), flagRem(false), transparency(255){}

int RemovablePlatform::getFrames() const{
    return  frames;
}

bool RemovablePlatform::getFlag() const{
    return flagRem;
}

int RemovablePlatform::getTransparency() const{
    return transparency;
}

const char* RemovablePlatform::getPlatformType() const{
    return "removablePlatform";
}

void RemovablePlatform::setPositiveFlag(){
    flagRem = true;
}

void RemovablePlatform::increaseFrames(){
    frames++;
}

void RemovablePlatform::increaseTransparency(){
    transparency -= 50;
}

void RemovablePlatform::decreaseTransparency(){
    transparency += 50;
}

void RemovablePlatform::setRandomPosition(){
    float xPlatformLeftBound = platformWidth / 2;
    float xPlatformRightBound = BACKGROUNDWIDTH - platformWidth / 2;
    float xRandomCoordinate = getRandomNumber(xPlatformLeftBound, xPlatformRightBound);
    platformSprite.setPosition(xRandomCoordinate, platformSprite.getPosition().y);
}

void RemovablePlatform::resetFrames(){
    frames = 0;
}

void RemovablePlatform::resetTransparency(){
    transparency = 255;
}

void RemovablePlatform::setNegativeFlag(){
    flagRem = 0;
}

void RemovablePlatform::operator=(const RemovablePlatform &right){
    frames = right.frames;
    flagRem = right.flagRem;
    transparency = right.transparency;
    platformSprite.setColor(sf::Color(255, 255, 255, transparency));
}