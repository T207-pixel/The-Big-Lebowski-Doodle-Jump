#include "Scores.h"

template <typename T>
std::string toString(T val){
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

template<typename T>
T fromString(const std::string& s){
    std::istringstream iss(s);
    T res;
    iss >> res;
    return res;
}

int formulaPlatformQuantity(const float &score){
    int platformQuantity = ((STARTPLATFORMQUANTITY - ENDPLATFORMQUANTITY) / pow(M_E, 0.03 * sqrt(score)) ) + ENDPLATFORMQUANTITY;   // find right parameter 0.03
    return platformQuantity;
}

Scores::Scores(){
    scores = STARTSCORES;
}

const float &Scores::getScoresConst() const{
    return scores;
}

float &Scores::getScores(){
    return scores;
}

void Scores::setScores(const float &currentScore){  // also, should draw scores on screen
    scores = currentScore;
}

void Scores::organisePlatformsQuantity(Map &map, Map &newMap) const{   // test version
    if (map.getPlatformQuantityConst() > formulaPlatformQuantity(scores)){
        map.setPlatformQuantity(formulaPlatformQuantity(scores));
        newMap.setPlatformQuantity(formulaPlatformQuantity(scores));
    }
}

void Scores::printScores(){
    std::cout << "Current score: " << scores << "\n";
}

void Scores::drawScores(const float centerCoordinate, sf::Text text, std::string scoresStr, sf::RenderWindow &window) const{
    scoresStr = toString(int(scores));
    text.setString(scoresStr);
    text.setPosition(25, centerCoordinate - BACKGROUNDHEIGHT / 2);
    window.draw(text);
}

void Scores::drawGameOverScore(float x, float y, unsigned size, sf::Text text, std::string scoresStr, sf::RenderWindow &window){
    scoresStr = toString(int(scores));
    text.setString(scoresStr);
    text.setPosition(x, y);
    text.setCharacterSize(size);
    window.draw(text);
}

void Scores::loadFromFile(){
    std::string bestScoreStr;
    std::ifstream in("../../scores/bestScore.txt");
    getline(in, bestScoreStr);
    in.close();
    scores = fromString<int>(bestScoreStr);
}

void Scores::storeInFile(float currentScore){
    std::ofstream out;
    out.open("../../scores/bestScore.txt");
    out << currentScore;
}
