#pragma once
#include "Settings.h"
#include "Map.h"
#include <iostream>

int formulaPlatformQuantity(const float &score);

class Scores{
private:
    float scores;
public:
    Scores();
    const float &getScoresConst() const;
    float &getScores();
    void setScores(const float &currentScore);
    void organisePlatformsQuantity(Map &map, Map &newMap) const;
    void printScores();
    void drawScores(float centerCoordinate, sf::Text text, std::string scoresStr, sf::RenderWindow &window) const;
};