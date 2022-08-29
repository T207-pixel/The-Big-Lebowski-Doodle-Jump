#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Platform.h"
#include "FallingPlatform.h"
#include "HorizontalPlatform.h"
#include "DisappearingPlatform.h"
#include "RemovablePlatform.h"
#include "TwitchingPlatform.h"
#include "PlatformAppearanceProbability.h"

class Map{
private:
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
    std::vector<Platform*> platformVector;
    float platformQuantity;
public:
    Map(float p_platformQuantity, bool flag, const int score, PlatformAppearanceProbability &appearanceProbability);
    void deletePlatforms();
    const sf::Sprite &getMapSpriteConst() const;
    sf::Sprite &getMapSprite();
    const std::vector<Platform*> &getPlatformVectorConst() const;
    std::vector<Platform*> &getPlatformVector();
    const float &getPlatformQuantityConst() const;
    float &getPlatformQuantity();
    void setPlatformPosition(const float &positionY, int i);
    void setPlatformQuantity(const float &number);
    void generatePlatforms(bool flag, const int score, PlatformAppearanceProbability &appearanceProbability);
    Platform* generatorMechanic(float layerHeight, float iterator, bool flag, const int score, PlatformAppearanceProbability &appearanceProbability);
    void drawBackground(sf::RenderWindow &window) const;
    void drawPlatforms(sf::RenderWindow &window) const;
    /*void  debugOutput();*/
};