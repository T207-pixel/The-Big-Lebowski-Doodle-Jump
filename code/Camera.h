#pragma once
#include "Settings.h"
#include "Doodler.h"
#include "Map.h"
#include "Platform.h"
#include "Scores.h"

class Camera{
private:
    sf::View view;
    float position;
    float newPosition;
public:
    Camera();
    sf::View& getView();
    const float &getPositionConst() const;
    const sf::View &getViewConst();
    void setPosition(const float &currentPosition);
    void setNewPosition(const Doodler &doodler);
    void ifUpperThanCamLvl(const Doodler &doodler);
    void moveCamera(Doodler& doodler, sf::Sprite &mapSprite, Scores &scores);
    void putDown(Map &map, Map &nextMap, Doodler &doodler, Scores &scores, PlatformAppearanceProbability &appearanceProbability);
    static void relocatingLowerMapPlatforms(Map &map, Map &nextMap, Scores &scores);
    static void randomisePositionForNewMapPlatforms(Map &nextMap);
    static void MapNextLvlProcessing(Map &nextMap, Map &map, Scores &scores, PlatformAppearanceProbability &appearanceProbability);
};