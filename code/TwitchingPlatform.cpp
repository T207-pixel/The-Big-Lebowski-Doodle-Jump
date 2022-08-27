#include "TwitchingPlatform.h"

TwitchingPlatform::TwitchingPlatform(const float &layerHeight, const float &current, bool flag, const char* fileName)
        : Platform(layerHeight, current, flag, fileName), horizontalSpeed(HORIZONTALSPEED * positiveOrNegativeUnit()), distance(MAXDISTANCE), flag(false) {}

const char* TwitchingPlatform::getPlatformType() const{
    return "twitchingPlatform";
}

void TwitchingPlatform::setPositiveFlag(){
    flag = true;
}

bool TwitchingPlatform::getFlag() const{
    return flag;
}

void TwitchingPlatform::checkTwitchDirection(){
    if (platformSprite.getPosition().x < distance + platformWidth / 2 || platformSprite.getPosition().x > BACKGROUNDWIDTH - distance - platformWidth / 2){
        horizontalSpeed *= -1;
    }
}

void TwitchingPlatform::twitch(){
    if (distance > 0){
        platformSprite.move(horizontalSpeed, 0);
        float tmp = horizontalSpeed;
        if (tmp < 0)
            tmp *= -1;
        distance -= tmp;
    }
    else {
        flag = false;
        distance = MAXDISTANCE;
    }
}

