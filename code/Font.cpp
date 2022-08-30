#include "Font.h"

Font::Font(const char* fileName) : text("", font){
    font.loadFromFile(fileName);
    text.setCharacterSize(40);
}

sf::Text Font::getText() const{
    return text;
}
