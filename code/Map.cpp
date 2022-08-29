#pragma once
#include "Map.h"
#include "Settings.h"

Map::Map(float p_platformQuantity, bool flag, const int score, PlatformAppearanceProbability &appearanceProbability){
    platformQuantity = p_platformQuantity;
    if (flag){
        mapTexture.loadFromFile(FILENAMEBACKGROUND);
        mapSprite.setTexture(mapTexture);
        mapSprite.setOrigin(BACKGROUNDWIDTH / 2, BACKGROUNDHEIGHT / 2);
        mapSprite.setPosition(mapSprite.getOrigin());
        generatePlatforms(flag, score, appearanceProbability);
    }
    else {
        mapSprite.setOrigin(BACKGROUNDWIDTH / 2,  BACKGROUNDHEIGHT / 2);    // why not (-1)
        mapSprite.setPosition(BACKGROUNDWIDTH / 2, (-1) * BACKGROUNDHEIGHT / 2);
        generatePlatforms(flag, score, appearanceProbability);
    }
}

void Map::deletePlatforms(){
    platformVector.erase(platformVector.begin(), platformVector.end());
}

const sf::Sprite &Map::getMapSpriteConst() const{
    return mapSprite;
}

void Map::generatePlatforms(bool flag, const int score, PlatformAppearanceProbability &appearanceProbability){
    float layerHeight = BACKGROUNDHEIGHT / getPlatformQuantityConst();
    for (int i = 1; i <= platformQuantity; i++){
        Platform* newPlatform = generatorMechanic(layerHeight, i, flag, score, appearanceProbability);
        platformVector.emplace_back(newPlatform);
    }
}

Platform* Map::generatorMechanic(float layerHeight, float iterator, bool flag, const int score, PlatformAppearanceProbability &appearanceProbability){
    int randomProbability = rand() % 100;
    if (score < 500){
        appearanceProbability.setUsualPLProbability(100);
        if (randomProbability < appearanceProbability.getUsualPlatProbability()){
            auto* newPlatform = new Platform(layerHeight, iterator, flag);
            return newPlatform;
        }
    }
    else if (score >= 500 && score < 1000){
        appearanceProbability.setUsualPLProbability(80);
        appearanceProbability.setFallingPlProbability(20);
        if (randomProbability < appearanceProbability.getUsualPlatProbability()){
            auto* newPlatform = new Platform(layerHeight, iterator, flag);
            return newPlatform;
        }
        else if (randomProbability >= appearanceProbability.getUsualPlatProbability() && randomProbability <= appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability()){
            auto* newPlatform = new FallingPlatform(layerHeight, iterator, flag);
            return newPlatform;
        }
    }
    else if (score >= 1000 && score < 2500){
        appearanceProbability.setUsualPLProbability(50);
        appearanceProbability.setFallingPlProbability(20);
        appearanceProbability.setHorizontalPlProbability(30);
        if (randomProbability < appearanceProbability.getUsualPlatProbability()){
            auto* newPlatform = new Platform(layerHeight, iterator, flag);
            return newPlatform;
        }
        else if (randomProbability >= appearanceProbability.getUsualPlatProbability() && randomProbability < appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability()){
            auto* newPlatform = new FallingPlatform(layerHeight, iterator, flag);
            return newPlatform;
        }
        else if (randomProbability >= appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() && randomProbability <= appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability()){
            auto* newPlatform = new HorizontalPlatform(layerHeight, iterator, flag, score);
            return newPlatform;
        }
    }
    else if (score >= 2500 && score < 5000){
        appearanceProbability.setUsualPLProbability(30);
        appearanceProbability.setFallingPlProbability(20);
        appearanceProbability.setHorizontalPlProbability(15);
        appearanceProbability.setDisappearingPlProbability(15);
        appearanceProbability.setRemovablePlProbability(20);
        if (randomProbability < appearanceProbability.getUsualPlatProbability()){
            auto* newPlatform = new Platform(layerHeight, iterator, flag);
            return newPlatform;
        }
        else if (randomProbability >= appearanceProbability.getUsualPlatProbability() && randomProbability < appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability()){
            auto* newPlatform = new FallingPlatform(layerHeight, iterator, flag);
            return newPlatform;
        }
        else if (randomProbability >= appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() && randomProbability < appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability()){
            auto* newPlatform = new HorizontalPlatform(layerHeight, iterator, flag, score);
            return newPlatform;
        }
        else if (randomProbability >= appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability() && randomProbability < appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability() + appearanceProbability.getDisappearingPlProbability()){
            auto* newPlatform = new DisappearingPlatform(layerHeight, iterator, flag);
            return newPlatform;
        }
        else if (randomProbability >= appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability() + appearanceProbability.getDisappearingPlProbability() && randomProbability <= appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability() + appearanceProbability.getDisappearingPlProbability() + appearanceProbability.getRemovablePlProbability()){
            auto* newPlatform = new RemovablePlatform(layerHeight, iterator, flag);
            return newPlatform;
        }
    }
    else if (score >= 5000 && score < 10000){
        appearanceProbability.setUsualPLProbability(10);
        appearanceProbability.setFallingPlProbability(10);
        appearanceProbability.setHorizontalPlProbability(10);
        appearanceProbability.setDisappearingPlProbability(30);
        appearanceProbability.setRemovablePlProbability(20);
        appearanceProbability.setTwitchingPlProbability(20);
        if (randomProbability < appearanceProbability.getUsualPlatProbability()){
            auto* newPlatform = new Platform(layerHeight, iterator, flag);
            return newPlatform;
        }
        else if (randomProbability >= appearanceProbability.getUsualPlatProbability() && randomProbability < appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability()){
            auto* newPlatform = new FallingPlatform(layerHeight, iterator, flag);
            return newPlatform;
        }
        else if (randomProbability >= appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() && randomProbability < appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability()){
            auto* newPlatform = new HorizontalPlatform(layerHeight, iterator, flag, score);
            return newPlatform;
        }
        else if (randomProbability >= appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability() && randomProbability < appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability() + appearanceProbability.getDisappearingPlProbability()){
            auto* newPlatform = new DisappearingPlatform(layerHeight, iterator, flag);
            return newPlatform;
        }
        else if (randomProbability >= appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability() + appearanceProbability.getDisappearingPlProbability() && randomProbability < appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability() + appearanceProbability.getDisappearingPlProbability() + appearanceProbability.getRemovablePlProbability()){
            auto* newPlatform = new RemovablePlatform(layerHeight, iterator, flag);
            return newPlatform;
        }
        else if (randomProbability >= appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability() + appearanceProbability.getDisappearingPlProbability() + appearanceProbability.getRemovablePlProbability() && randomProbability <= appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability() + appearanceProbability.getDisappearingPlProbability() + appearanceProbability.getRemovablePlProbability() + appearanceProbability.getTwitchingPlProbability()){
            auto* newPlatform = new TwitchingPlatform(layerHeight, iterator, flag);
            return newPlatform;
        }
    }
    else if (score > 10000) {
        appearanceProbability.setUsualPLProbability(0);
        appearanceProbability.setFallingPlProbability(0);
        appearanceProbability.setHorizontalPlProbability(20);
        appearanceProbability.setDisappearingPlProbability(30);
        appearanceProbability.setRemovablePlProbability(30);
        appearanceProbability.setTwitchingPlProbability(20);
        if (randomProbability < appearanceProbability.getUsualPlatProbability()){
            auto* newPlatform = new Platform(layerHeight, iterator, flag);
            return newPlatform;
        }
        else if (randomProbability >= appearanceProbability.getUsualPlatProbability() && randomProbability < appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability()){
            auto* newPlatform = new FallingPlatform(layerHeight, iterator, flag);
            return newPlatform;
        }
        else if (randomProbability >= appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() && randomProbability < appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability()){
            auto* newPlatform = new HorizontalPlatform(layerHeight, iterator, flag, score);
            return newPlatform;
        }
        else if (randomProbability >= appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability() && randomProbability < appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability() + appearanceProbability.getDisappearingPlProbability()){
            auto* newPlatform = new DisappearingPlatform(layerHeight, iterator, flag);
            return newPlatform;
        }
        else if (randomProbability >= appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability() + appearanceProbability.getDisappearingPlProbability() && randomProbability < appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability() + appearanceProbability.getDisappearingPlProbability() + appearanceProbability.getRemovablePlProbability()){
            auto* newPlatform = new RemovablePlatform(layerHeight, iterator, flag);
            return newPlatform;
        }
        else if (randomProbability >= appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability() + appearanceProbability.getDisappearingPlProbability() + appearanceProbability.getRemovablePlProbability() && randomProbability <= appearanceProbability.getUsualPlatProbability() + appearanceProbability.getFallingPlProbability() + appearanceProbability.getHorizontalPlProbability() + appearanceProbability.getDisappearingPlProbability() + appearanceProbability.getRemovablePlProbability() + appearanceProbability.getTwitchingPlProbability()){
            auto* newPlatform = new TwitchingPlatform(layerHeight, iterator, flag);
            return newPlatform;
        }
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
