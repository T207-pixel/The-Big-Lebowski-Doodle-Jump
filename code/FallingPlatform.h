#pragma once
#include "Settings.h"
#include "Platform.h"

class FallingPlatform final : public Platform{
private:
    float fallingSpeed;
public:
    FallingPlatform(const float &layerHeight, const float &current, bool flag, const char* fileName = FILENAMEBREAKINGPLATFORM);
    FallingPlatform(Platform* otherPlatform, const char* fileName = FILENAMEBREAKINGPLATFORM);
    void setPlatformFallingSpeed(const float &speed);
    virtual const char* getPlatformType() const override;
    const float &getFallingSpeedConst() const;
    void setFallingPlatformTexture(const char* fileName = FILENAMEBREAKINGPLATFORMSET);
    void moveFallingPlatformsFrames();
};