//
// Created by Pasindu on 10/5/2021.
//

#ifndef ASS2_DEALER_H
#define ASS2_DEALER_H

#include "CardPack.h"
#include "vector"
#include "random"
#include "time.h"
#include "Player.h"
class Dealer :public Player{
private:
    vector<CardPack> cardPack;  //card pack
    vector<CardPack> shuffledCardPack;      //after shuffle card pack
    CardPack card;
public:

    Dealer();
    Dealer(Player player);
    vector<CardPack> newCardPack(); //make a new card pack
    vector<CardPack> shuffle(vector<CardPack>); //shuffle card pack
    void showNewPack(vector<CardPack>); //show newly created card pack
    Player distribute(int);
    int higherRank(Player[], int, int); //will return index of the highest rank
};


#endif //ASS2_DEALER_H
