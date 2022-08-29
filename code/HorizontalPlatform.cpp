#include "HorizontalPlatform.h"

HorizontalPlatform::HorizontalPlatform(const float &layerHeight, const float &current, bool flag, const int score, const char* fileName)
        : Platform(layerHeight, current, flag, fileName){
    speedDependencyOnPointsInit(score);
}

HorizontalPlatform::HorizontalPlatform(Platform* otherPlatform, const char* fileName) : Platform(otherPlatform, fileName),
    horizontalSpeed(dynamic_cast<HorizontalPlatform*>(otherPlatform)->horizontalSpeed) {}

const char* HorizontalPlatform::getPlatformType() const{
    return "horizontalPlatform";
}

const float &HorizontalPlatform::getPlatformSpeedConst() const{
    return horizontalSpeed;
}

const float &HorizontalPlatform::getPlatformWidthConst() const{
    return platformWidth;
}

void HorizontalPlatform::moveHorizontalPlatform(const int scores){
    if (getPlatformSprite().getPosition().x < getPlatformWidthConst() / 2.0 || getPlatformSprite().getPosition().x > BACKGROUNDWIDTH - getPlatformWidthConst() / 2.0){
        horizontalSpeed *= -1;
    }
    platformSprite.move(horizontalSpeed, 0);
}

sf::Sprite &HorizontalPlatform::getPlatformSprite(){
    return platformSprite;
}

// add limit of speed and change DINAMICCOEF
void HorizontalPlatform::speedDependencyOnPointsInit(const int scores){
    if (scores <= 50000)
        horizontalSpeed =  (DINAMICCOEF * scores + STARTHORIZONTALPLATFORMSPEED) * positiveOrNegativeUnit(); // [(0, 0.3), (50 000, 1)]
    else
        horizontalSpeed = MAXHORIZONTALSPEED * positiveOrNegativeUnit();
    std::cout << "Platform speed: " << horizontalSpeed << "\n";
}

void HorizontalPlatform::operator=(HorizontalPlatform &right){
    horizontalSpeed = right.horizontalSpeed;
}

void HorizontalPlatform::speedDependencyRealocate(const int scores){
    if (horizontalSpeed > 0){
        if (scores <= 50000)
            horizontalSpeed = DINAMICCOEF * scores + STARTHORIZONTALPLATFORMSPEED; // [(0, 0.3), (50 000, 1)]
        else
            horizontalSpeed = MAXHORIZONTALSPEED;
        std::cout << "Platform speed: " << horizontalSpeed << "\n";
    }
    else {
        if (scores <= 50000)
            horizontalSpeed = (DINAMICCOEF * scores + STARTHORIZONTALPLATFORMSPEED) * (-1); // [(0, 0.3), (50 000, 1)]
        else
            horizontalSpeed = MAXHORIZONTALSPEED * (-1);
        std::cout << "Platform speed: " << horizontalSpeed << "\n";
    }
}




