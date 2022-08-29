#include "PlatformAppearanceProbability.h"

PlatformAppearanceProbability::PlatformAppearanceProbability() : usualPlatformProbability(0), fallingPlatformProbability(0),
    horizontalPlatformProbability(0), disappearingPlatformProbability(0), removablePlatformProbability(0), twitchingPlatformProbability(0) {}

int PlatformAppearanceProbability::getUsualPlatProbability() const{
    return usualPlatformProbability;
}

int PlatformAppearanceProbability::getFallingPlProbability() const{
    return fallingPlatformProbability;
}

int PlatformAppearanceProbability::getHorizontalPlProbability() const{
    return horizontalPlatformProbability;
}

int PlatformAppearanceProbability::getDisappearingPlProbability() const{
    return disappearingPlatformProbability;
}

int PlatformAppearanceProbability::getRemovablePlProbability() const{
    return removablePlatformProbability;
}

int PlatformAppearanceProbability::getTwitchingPlProbability() const{
    return twitchingPlatformProbability;
}

void PlatformAppearanceProbability::setUsualPLProbability(const int probability){
    usualPlatformProbability = probability;
}

void PlatformAppearanceProbability::setFallingPlProbability(const int probability){
    fallingPlatformProbability = probability;
}

void PlatformAppearanceProbability::setHorizontalPlProbability(const int probability){
    horizontalPlatformProbability = probability;
}

void PlatformAppearanceProbability::setDisappearingPlProbability(const int probability){
    disappearingPlatformProbability = probability;
}

void PlatformAppearanceProbability::setRemovablePlProbability(const int probability){
    removablePlatformProbability = probability;
}

void PlatformAppearanceProbability::setTwitchingPlProbability(const int probability){
    twitchingPlatformProbability = probability;
}