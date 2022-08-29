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
        //std::cout << "Current score: " << scores.getScoresConst() << "\n";
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
    /*for (int i = 0; i < nextMap.getPlatformQuantityConst(); i++){
        // if type disappearing platform and flag == true use copy constructor or copy needed fields
        map.getPlatformVector()[i]->setPlatformPositionY(nextMap.getPlatformVector()[i]->getPlatformSpriteConst().getPosition().y + BACKGROUNDHEIGHT); // set new position for new platforms
        map.getPlatformVector()[i]->setPlatformPositionX(nextMap.getPlatformVector()[i]->getPlatformSpriteConst().getPosition().x);
        if (strcmp(nextMap.getPlatformVector()[i]->getPlatformType(), "disappearingPlatform") == 0){
            if (dynamic_cast<DisappearingPlatform*>(nextMap.getPlatformVector()[i])->getFlag() == true){
                *dynamic_cast<DisappearingPlatform*>(map.getPlatformVector()[i]) = *dynamic_cast<DisappearingPlatform*>(nextMap.getPlatformVector()[i]);
            }
        }
        if (strcmp(nextMap.getPlatformVector()[i]->getPlatformType(), "horizontalPlatform") == 0){
            dynamic_cast<HorizontalPlatform *>(nextMap.getPlatformVector()[i])->speedDependencyRealocate(scores.getScoresConst());
            *dynamic_cast<HorizontalPlatform*>(map.getPlatformVector()[i]) = *dynamic_cast<HorizontalPlatform*>(nextMap.getPlatformVector()[i]);
        }
        if (strcmp(nextMap.getPlatformVector()[i]->getPlatformType(), "removablePlatform") == 0 && dynamic_cast<RemovablePlatform*>(nextMap.getPlatformVector()[i])->getFlag() == true){
            for (int j = 0; j < nextMap.getPlatformQuantityConst(); j++)
                *dynamic_cast<RemovablePlatform*>(map.getPlatformVector()[j]) = *dynamic_cast<RemovablePlatform*>(nextMap.getPlatformVector()[j]);
        }
    }*/
    ///remake///
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
    int currentQuantity = nextMap.getPlatformQuantityConst();
    if (previousQuantity > currentQuantity){
        nextMap.deletePlatforms();
        nextMap.generatePlatforms(false, scores.getScoresConst(), appearanceProbability);
    }
    else {
        nextMap.deletePlatforms();
        nextMap.generatePlatforms(false, scores.getScoresConst(), appearanceProbability);
    }
    map.setPlatformQuantity(previousQuantity);
}

