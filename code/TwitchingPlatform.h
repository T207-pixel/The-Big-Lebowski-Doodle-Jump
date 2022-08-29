#pragma once
#include "Settings.h"
#include "Platform.h"

class TwitchingPlatform final : public Platform{
private:
    float horizontalSpeed;
    float distance;
    bool flag;
public:
    TwitchingPlatform(const float &layerHeight, const float &current, bool flag, const char* fileName = FILEMAMETWITCHINGPLATFORM);
    TwitchingPlatform(Platform* otherPlatform, const char* fileName = FILEMAMETWITCHINGPLATFORM);
    virtual const char* getPlatformType() const;
    void setPositiveFlag();
    bool getFlag() const;
    void checkTwitchDirection();
    void twitch();
};