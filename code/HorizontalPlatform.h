#pragma once
#include "Settings.h"
#include "Platform.h"

class HorizontalPlatform final : public Platform{
private:
    float horizontalSpeed;
public:
    HorizontalPlatform(const float &layerHeight, const float &current, bool flag,const int score, const char* fileName = FILENAMEHORIZONTALPLATFORM);
    HorizontalPlatform(Platform* otherPlatform, const char* fileName = FILENAMEHORIZONTALPLATFORM);
    virtual const char* getPlatformType () const override;
    const float &getPlatformSpeedConst() const;
    void moveHorizontalPlatform(const int scores);
    virtual sf::Sprite &getPlatformSprite() override;
    virtual const float &getPlatformWidthConst() const;
    void speedDependencyOnPointsInit(const int scores);
    void operator=(HorizontalPlatform &right);
    void speedDependencyRealocate(const int scores);
};