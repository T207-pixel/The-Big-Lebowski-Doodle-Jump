#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Doodler.h"
#include "Map.h"
#include "Platform.h"
#include "FallingPlatform.h"
#include "HorizontalPlatform.h"

class GameEngine{
public:
    void gotOnPlatform(Doodler &doodler, std::vector<Platform*> &platform, float platformQuantity, bool ifShouldCheck);
    bool collision(Doodler &doodler, std::vector<Platform*> platform, float platformQuantity, int &i);
    void fallingPlatformAnimation(std::vector<Platform*> &platform);
    void HorizontalPlatformMoving(std::vector<Platform*> &platform, int scores);
    void DisappearingPlatformMechanic(std::vector<Platform*> &platform);
    bool removablePlatformMechanic(std::vector<Platform*> &platform, int flagTmp = 0);
    bool twitchingPlatformMechanic(std::vector<Platform*> &platform, bool flagTmp = false);
    bool fall(float currentCenter, float doodlerPositionY, float doodlerHalf);
    bool gameOver(float currentCenter, float doodlerPositionY, float doodlerHalf);
};