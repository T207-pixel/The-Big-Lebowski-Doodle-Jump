#include "DisappearingPlatform.h"

DisappearingPlatform::DisappearingPlatform(const float &layerHeight, const float &current, bool flag, const char* fileName)
        : Platform(layerHeight, current, flag, fileName), frames(0), flag(false), comparable(0), transparency(255) {}

DisappearingPlatform::DisappearingPlatform(Platform* otherPlatform, const char* fileName) : Platform(otherPlatform, fileName),
    frames(dynamic_cast<DisappearingPlatform*>(otherPlatform)->frames), comparable(dynamic_cast<DisappearingPlatform*>(otherPlatform)->comparable),
    transparency(dynamic_cast<DisappearingPlatform*>(otherPlatform)->transparency), flag(dynamic_cast<DisappearingPlatform*>(otherPlatform)->flag) {}

const char* DisappearingPlatform::getPlatformType() const{
    return "disappearingPlatform";
}

int DisappearingPlatform::getFramesCounter() const{
    return frames;
}

bool DisappearingPlatform::getFlag() const{
    return flag;
}

void DisappearingPlatform::setPositiveFlag(){
    flag = true;
}

void DisappearingPlatform::setNegativeFlag(){
    flag = false;
}

void DisappearingPlatform::increaseFrames(){
    frames++;
}

void DisappearingPlatform::resetFrames(){
    frames = 0;
}

void DisappearingPlatform::increaseComparable(){
    comparable += 10;   // change comparable every 10 frames
}

int DisappearingPlatform::getComparable() const{
    return comparable;
}

void DisappearingPlatform::resetComparable(){
    comparable = 0;
}

void DisappearingPlatform::increaseTransparency(){  // method is called increase because it becomes more transparent with lower transparency
    transparency -= 50;     // level of transparency through every 10 frames
}

int DisappearingPlatform::getTransparency() const{
    return transparency;
}

void DisappearingPlatform::resetTransparency(){
    transparency = 255;
}

void DisappearingPlatform::setFrames(const int _frames){
    frames = _frames;
}

void DisappearingPlatform::setFlag(const bool _flag){
    flag = _flag;
}

void DisappearingPlatform::setComparable(const int _comparable){
    comparable = _comparable;
}

void DisappearingPlatform::setTransparency(const int _transparency){
    transparency = _transparency;
}

void DisappearingPlatform::copyFields(DisappearingPlatform* right){
    frames = right->frames;
    flag  = right->flag;
    comparable = right->comparable;
    transparency = right->transparency;
    platformSprite.setColor(sf::Color(255, 255, 255, transparency));
}

void DisappearingPlatform::operator=(const DisappearingPlatform &right){
    frames = right.frames;
    flag = right.flag;
    comparable = right.comparable;
    transparency = right.transparency;
    platformSprite.setColor(sf::Color(255, 255, 255, transparency));
}
