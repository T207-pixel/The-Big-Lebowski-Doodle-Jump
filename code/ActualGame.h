#pragma once
#include "Settings.h"
#include "Map.h"
#include "Doodler.h"
#include "GameEngine.h"
#include "Camera.h"
#include "Scores.h"
#include "Font.h"
#include <iostream>

class ActualGame{
public:
    ActualGame();
    int actualGamePlay(sf::RenderWindow &window, int &flag, Scores &scores);
};