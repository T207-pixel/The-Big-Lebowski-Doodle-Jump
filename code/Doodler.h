#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"

class Doodler{
private:
    sf::Texture doodlerTexture;
    sf::Sprite doodlerSprite;
    float doodlerWidth;
    float doodlerHeight;
    float doodlerSpeedY;
    float doodlerSpeedX;
public:
    Doodler();
    const sf::Sprite &getDoodlerSpriteConst() const;
    sf::Sprite &getDoodlerSprite();
    const float &getDoodlerSpeedYConst() const;
    float &getDoodlerSpeedY();
    const float &getDoodlerSpeedXConst() const;
    float &getDoodlerSpeedX();
    const float &getDoodlerWidthConst() const;
    const float &getDoodlerHeightConst() const;
    const float &getDoodlerLeftOffsetConst() const;
    const float &getDoodlerRightOffsetConst() const;
    void setTextureLeft();
    void setTextureRight();
    void setTextureBentLegsLeft();
    void setTextureBentLegsRight();
    void setDoodlerSpeedY(const float &speed);
    void animation();
    void drawDoodler(sf::RenderWindow &window);
    void basicJump();
    void movementSides();
};