#include "Scores.h"

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

//make private
void Scores::organisePlatformsQuantity(Map &map, Map &newMap){   // test version
    if (map.getPlatformQuantityConst() > formulaPlatformQuantity(scores)){
        map.setPlatformQuantity(formulaPlatformQuantity(scores));
        newMap.setPlatformQuantity(formulaPlatformQuantity(scores));
    }
}

void Scores::printScores(){
    std::cout << "Current score: " << scores << "\n";
}
