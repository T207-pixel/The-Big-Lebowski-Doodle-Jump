#pragma once
#include "Settings.h"

class Font{
private:
    sf::Font font;
    sf::Text text;
public:
    Font(const char* fileName = FILENAMEFONT);
    sf::Text getText() const;
};