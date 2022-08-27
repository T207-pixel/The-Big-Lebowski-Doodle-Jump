#include "FallingPlatform.h"

FallingPlatform::FallingPlatform(const float &layerHeight, const float &current, bool flag, const char* fileName)
    : Platform(layerHeight, current, flag, fileName), fallingSpeed(STARTFALLINGPLATFORMSPEED) {}

void FallingPlatform::setPlatformFallingSpeed(const float &speed){
    fallingSpeed = speed;
}

void FallingPlatform::setFallingPlatformTexture(const char* fileName){
    platformTexture.loadFromFile(fileName);
    platformSprite.setTexture(platformTexture);
    platformSprite.setOrigin(platformSprite.getOrigin().x, platformSprite.getOrigin().y);
    //std::cout << "Start Origin X: " << platformSprite.getOrigin().x << "\n";
    //std::cout << "Start Origin y: " << platformSprite.getOrigin().y << "\n";
    platformSprite.setTextureRect(sf::IntRect(0, 0, DISTANCETONEXTPLATFORMX, DISTANCETONEXTPLATFORMY));
}

void FallingPlatform::moveFallingPlatformsFrames(){
    if (platformSprite.getOrigin().x < QUANTITYOFFRAMESFALLPLAT * DISTANCETONEXTPLATFORMX - DISTANCETONEXTPLATFORMX / 2){
        platformSprite.move(DISTANCETONEXTPLATFORMX, 0);
        platformSprite.setOrigin(platformSprite.getOrigin().x + DISTANCETONEXTPLATFORMX, platformSprite.getOrigin().y);
        platformSprite.setTextureRect(sf::IntRect(platformSprite.getOrigin().x - XPLATFORMSTARTPOSITION, platformSprite.getOrigin().y - YPLATFORMSTARTPOSITION, DISTANCETONEXTPLATFORMX, DISTANCETONEXTPLATFORMY));
    }
    //std::cout << "Origin x: " << platformSprite.getOrigin().x << "\nOrigin y: " << platformSprite.getOrigin().y << "\n";
}

const float &FallingPlatform::getFallingSpeedConst() const{
    return fallingSpeed;
}

const char* FallingPlatform::getPlatformType() const{
    return "fallingPlatform";
}


