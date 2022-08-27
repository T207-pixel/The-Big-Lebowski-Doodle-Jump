#pragma once
#include "Doodler.h"
#include <iostream>

Doodler::Doodler(){
    doodlerTexture.loadFromFile(FILENAMEDOODLERRIGHT);
    doodlerSprite.setTexture(doodlerTexture);
    doodlerWidth = doodlerSprite.getLocalBounds().width;
    doodlerHeight = doodlerSprite.getLocalBounds().height;
    doodlerSpeedY = STARTSPEEDY;
    doodlerSpeedX = 0;
    doodlerSprite.setOrigin(doodlerWidth/2, doodlerHeight/2);
    doodlerSprite.setPosition(BACKGROUNDWIDTH/2,  BACKGROUNDHEIGHT - doodlerSprite.getOrigin().y);
}

const sf::Sprite &Doodler::getDoodlerSpriteConst() const{
    return doodlerSprite;
}

sf::Sprite &Doodler::getDoodlerSprite(){
    return doodlerSprite;
}

const float &Doodler::getDoodlerSpeedYConst() const{
    return doodlerSpeedY;
}

float &Doodler::getDoodlerSpeedY(){
    return doodlerSpeedY;
}

const float &Doodler::getDoodlerSpeedXConst() const{
    return doodlerSpeedX;
}

float &Doodler::getDoodlerSpeedX(){
    return doodlerSpeedX;
}

const float &Doodler::getDoodlerHeightConst() const{
    return doodlerHeight;
}

const float &Doodler::getDoodlerWidthConst() const{
    return doodlerWidth;
}

const float &Doodler::getDoodlerLeftOffsetConst() const{
    if (doodlerSpeedX > 0)
        return OFFSETBACK;
    if (doodlerSpeedX < 0)
        return OFFSETNOSE;
}

const float &Doodler::getDoodlerRightOffsetConst() const{
    if (doodlerSpeedX > 0)
        return OFFSETNOSE;
    if (doodlerSpeedX < 0)
        return OFFSETBACK;
}

void Doodler::setTextureLeft(){
    doodlerTexture.loadFromFile(FILEMAMEDOODLERLEFT);
    doodlerSprite.setTexture(doodlerTexture);
}

void Doodler::setTextureRight(){
    doodlerTexture.loadFromFile(FILENAMEDOODLERRIGHT);
    doodlerSprite.setTexture(doodlerTexture);
}

void Doodler::setTextureBentLegsLeft(){
    doodlerTexture.loadFromFile(FILENAMEDOODLERBENTLEGSLEFT);
    doodlerSprite.setTexture(doodlerTexture);
}

void Doodler::setTextureBentLegsRight(){
    doodlerTexture.loadFromFile(FILENAMEDOODLERBENTLEGSRIGHT);
    doodlerSprite.setTexture(doodlerTexture);
}

void Doodler::setDoodlerSpeedY(const float &speed){
    doodlerSpeedY = speed;
}

void Doodler::basicJump(){
    float speed = getDoodlerSpeedYConst();
    doodlerSprite.move(0, speed);
    speed += ACCELERATION;
    setDoodlerSpeedY(speed);
    if (doodlerSprite.getPosition().y >= BACKGROUNDHEIGHT - doodlerSprite.getLocalBounds().height / 2) //tmp floor
        setDoodlerSpeedY(STARTSPEEDY);
}

void Doodler::movementSides(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        doodlerSprite.move((-1) * SIDESPEED, 0);
        doodlerSpeedX = (-1) *SIDESPEED;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        doodlerSprite.move(SIDESPEED, 0);
        doodlerSpeedX = SIDESPEED;
    }
    //LEFT TELEPORTATION
    if (doodlerSprite.getPosition().x < 0){
        doodlerSprite.setPosition(BACKGROUNDWIDTH, doodlerSprite.getPosition().y);
    }
    //RIGHT TELEPORTATION
    if (doodlerSprite.getPosition().x > BACKGROUNDWIDTH){
        doodlerSprite.setPosition(0, doodlerSprite.getPosition().y);
    }
}

void Doodler::animation(){
    if (getDoodlerSpeedYConst() >= STARTSPEEDY && getDoodlerSpeedYConst() < STARTSPEEDY - STARTSPEEDY / 4) {
        if (getDoodlerSpeedXConst() < 0)
            setTextureBentLegsLeft();
        if (getDoodlerSpeedXConst() > 0)
            setTextureBentLegsRight();
    }
    if (getDoodlerSpeedYConst() >= STARTSPEEDY - STARTSPEEDY / 4 && getDoodlerSpeedYConst() < 0 || getDoodlerSpeedYConst() > 0){
        if (getDoodlerSpeedXConst() < 0)
            setTextureLeft();
        if (getDoodlerSpeedXConst() > 0)
            setTextureRight();
    }
}

void Doodler::drawDoodler(sf::RenderWindow &window){
    window.draw(doodlerSprite);
}
