#pragma once
#include "Camera.h"
#include <iostream>

Camera::Camera(){
    position = CAMERALEVEL;
    newPosition = CAMERALEVEL;
}

sf::View &Camera::getView(){
    return view;
}

const sf::View &Camera::getViewConst(){
    return view;
}

const float &Camera::getPositionConst() const{
    return position;
}

void Camera::setPosition(const float &currentPosition){
    position = currentPosition;
}

void Camera::setNewPosition(const Doodler &doodler){
    newPosition = doodler.getDoodlerSpriteConst().getPosition().y;
}

float Camera::getNewPosition() const{
    return newPosition;
}

float Camera::getPosition() const{
    return position;
}

void Camera::ifUpperThanCamLvl(const Doodler &doodler){
    if (doodler.getDoodlerSpeedYConst() == STARTSPEEDY + ACCELERATION &&
            doodler.getDoodlerSpriteConst().getPosition().y < position){
        setNewPosition(doodler);
    }
}

void Camera::moveCamera(Doodler& doodler, sf::Sprite &mapSprite, Scores &scores){
    if (newPosition < position && doodler.getDoodlerSpeedYConst() < 0){
        view.move(0, doodler.getDoodlerSpeedYConst());
        mapSprite.move(0, doodler.getDoodlerSpeedYConst());
        scores.setScores(scores.getScoresConst() + doodler.getDoodlerSpeedYConst() * SCORECOEF);
        setPosition(position + doodler.getDoodlerSpeedYConst());
    }
    if (newPosition == position)
        newPosition = position;
}

void Camera::putDown(Map &map, Map &nextMap, Doodler &doodler, Scores &scores, PlatformAppearanceProbability &appearanceProbability){
    if (map.getMapSpriteConst().getPosition().y <= (-1) * BACKGROUNDHEIGHT / 2 ){
        //moving "map" to the first level
        map.setPlatformQuantity(nextMap.getPlatformQuantityConst());//debug
        doodler.getDoodlerSprite().move(0, BACKGROUNDHEIGHT);
        view.move(0, BACKGROUNDHEIGHT);
        map.getMapSprite().move(0, BACKGROUNDHEIGHT);
        position += BACKGROUNDHEIGHT;
        newPosition += BACKGROUNDHEIGHT;
        //relocating platforms on the map when "map" has same coordinates as "newMap"
        relocatingLowerMapPlatforms(map, nextMap, scores);
        //reorganise upper map ("nextMap")
        MapNextLvlProcessing(nextMap, map, scores, appearanceProbability);
    }
}

void Camera::relocatingLowerMapPlatforms(Map &map, Map &nextMap, Scores &scores){
    map.deletePlatforms();
    for (int i = 0; i < nextMap.getPlatformQuantityConst(); i++){
        const char* platformType = nextMap.getPlatformVector()[i]->getPlatformType();
        if (strcmp(platformType, "usualPlatform") == 0){
            auto* newPlatform = new Platform(nextMap.getPlatformVector()[i]);
            map.getPlatformVector().emplace_back(newPlatform);
        }
        else if (strcmp(platformType, "fallingPlatform") == 0){
            auto* newPlatform = new FallingPlatform(nextMap.getPlatformVector()[i]);
            map.getPlatformVector().emplace_back(newPlatform);
        }
        else if (strcmp(platformType, "horizontalPlatform") == 0){
            auto* newPlatform = new HorizontalPlatform(nextMap.getPlatformVector()[i]);
            map.getPlatformVector().emplace_back(newPlatform);
        }
        else if (strcmp(platformType, "disappearingPlatform") == 0){
            auto* newPlatform = new DisappearingPlatform(nextMap.getPlatformVector()[i]);
            map.getPlatformVector().emplace_back(newPlatform);
        }
        else if (strcmp(platformType, "removablePlatform") == 0){
            auto* newPlatform = new RemovablePlatform(nextMap.getPlatformVector()[i]);
            map.getPlatformVector().emplace_back(newPlatform);
        }
        else if (strcmp(platformType, "twitchingPlatform") == 0){
            auto* newPlatform = new TwitchingPlatform(nextMap.getPlatformVector()[i]);
            map.getPlatformVector().emplace_back(newPlatform);
        }
    }
}

void Camera::randomisePositionForNewMapPlatforms(Map &nextMap){
    float layerHeight = BACKGROUNDHEIGHT / nextMap.getPlatformQuantityConst();
    for (int i = 0; i < nextMap.getPlatformQuantityConst(); i++){
        nextMap.getPlatformVector()[i]->setPlatformRandomPosition(layerHeight, i, false);
    }
}

void Camera::MapNextLvlProcessing(Map &nextMap, Map &map, Scores &scores, PlatformAppearanceProbability &appearanceProbability){
    int previousQuantity = nextMap.getPlatformQuantityConst();
    scores.organisePlatformsQuantity(map, nextMap);
    nextMap.deletePlatforms();
    nextMap.generatePlatforms(false, scores.getScoresConst(), appearanceProbability);
    map.setPlatformQuantity(previousQuantity);
}

