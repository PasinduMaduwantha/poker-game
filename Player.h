//
// Created by Pasindu on 10/5/2021.
//

#ifndef ASS2_PLAYER_H
#define ASS2_PLAYER_H
#include "CardPack.h"
#include "string"
class Player {
private:
    string playerName;
    int marks=0;
    int condition;
    int rankNO;
public:
    Player();
    Player(string);
    CardPack cards[5];  //each player (include) dealer have 5 cards, dealer can access those card array
    void showPlayerCards();
    int rank();
    void setName(string);
    string getName();
    void setMarks(int);
    int getMarks();
    void setCondition(int);
    int getCondition();
    void setRank(int);
    int getRank();
};


#endif //ASS2_PLAYER_H
