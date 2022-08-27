#pragma once
#include "Map.h"
#include "Settings.h"
#include "Scores.h"

Map::Map(float p_platformQuantity, bool flag, const int score){
    platformQuantity = p_platformQuantity;
    if (flag){
        mapTexture.loadFromFile(FILENAMEBACKGROUND);
        mapSprite.setTexture(mapTexture);
        mapSprite.setOrigin(BACKGROUNDWIDTH / 2, BACKGROUNDHEIGHT / 2);
        mapSprite.setPosition(mapSprite.getOrigin());
        generatePlatforms(flag, score);
    }
    else {
        mapSprite.setOrigin(BACKGROUNDWIDTH / 2,  BACKGROUNDHEIGHT / 2);    // why not (-1)
        mapSprite.setPosition(BACKGROUNDWIDTH / 2, (-1) * BACKGROUNDHEIGHT / 2);
        generatePlatforms(flag, score);
    }
}

void Map::deletePlatforms(){
    platformVector.erase(platformVector.begin(), platformVector.end());
}

const sf::Sprite &Map::getMapSpriteConst() const{
    return mapSprite;
}

void Map::generatePlatforms(bool flag, const int score){     //should remake for new type of platforms
    float layerHeight = BACKGROUNDHEIGHT / getPlatformQuantityConst();
    for (int i = 1; i <= platformQuantity; i++){        // make rand choice function // 1 <=
        //Platform* newPlatform = new Platform(layerHeight, i, flag);
        //Platform* newPlatform = new FallingPlatform(layerHeight, i, flag);
        //Platform* newPlatform = new HorizontalPlatform(layerHeight, i, flag, score);
        Platform* newPlatform = new DisappearingPlatform(layerHeight, i, flag);
        //Platform* newPlatform = new RemovablePlatform(layerHeight, i, flag);
        //Platform* newPlatform = new TwitchingPlatform(layerHeight, i, flag);
        platformVector.emplace_back(newPlatform);
    }
}

sf::Sprite &Map::getMapSprite(){
    return mapSprite;
}

const std::vector<Platform*> &Map::getPlatformVectorConst() const{
    return platformVector;
}

std::vector<Platform*> &Map::getPlatformVector(){
    return platformVector;
}

const float &Map::getPlatformQuantityConst() const{
    return platformQuantity;
}

float &Map::getPlatformQuantity(){
    return platformQuantity;
}

void Map::setPlatformPosition(const float &positionY, int i) {
    platformVector[i]->getPlatformSprite().setPosition(BACKGROUNDWIDTH / 2, positionY);
}

void Map::setPlatformQuantity(const float &number){
    platformQuantity = number;
}

void Map::drawBackground(sf::RenderWindow &window) const{
    window.draw(mapSprite);
}

void Map::drawPlatforms(sf::RenderWindow &window) const{
    for (int i = 0; i < platformQuantity; i++)
        window.draw(platformVector[i]->getPlatformSpriteConst());
}

/*
void  Map::debugOutput(){
    for (int i = 0; i < platformQuantity; i++){
        std::cout << "y position: " << platformVector[i]->getPlatformSprite().getPosition().y << "\n";
    }
}*/
