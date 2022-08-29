#pragma once
#include "Settings.h"

class PlatformAppearanceProbability{
private:
    int usualPlatformProbability;
    int fallingPlatformProbability;
    int horizontalPlatformProbability;
    int disappearingPlatformProbability;
    int removablePlatformProbability;
    int twitchingPlatformProbability;
public:
    PlatformAppearanceProbability();
    int getUsualPlatProbability() const;
    void setUsualPLProbability(int probability);
    int getFallingPlProbability() const;
    void setFallingPlProbability(int probability);
    int getHorizontalPlProbability() const;
    void setHorizontalPlProbability(int probability);
    int getDisappearingPlProbability() const;
    void setDisappearingPlProbability(int probability);
    int getRemovablePlProbability() const;
    void setRemovablePlProbability(int probability);
    int getTwitchingPlProbability() const;
    void setTwitchingPlProbability(int probability);
};