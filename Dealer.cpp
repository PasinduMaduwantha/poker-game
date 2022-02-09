//
// Created by Pasindu on 10/5/2021.
//

#include <windows.h>
#include "Dealer.h"
/*
 * Function : newCardPack
 * Inputs   : N/A
 * Outputs  : new card pack vector
 */
vector<CardPack> Dealer::newCardPack() {
    for (int number = 2; number < 15; ++number)
        for (int suit = 1; suit <5 ; ++suit)
            cardPack.push_back(card.setCard(number,suit));  //make a new card pack

    return vector<CardPack>(cardPack);  //return the card pack vector
}
/*
 * Function : showNewPack
 * Inputs   : cardpack vector
 * Outputs  : N/A
 */
void Dealer::showNewPack(vector<CardPack> cardPack) {
    for (int i = 0; i < cardPack.size(); ++i)
        cardPack[i].showCard();     //show the created card pack
}
/*
 * Function : shuffle
 * Inputs   : vector, card pack
 * Outputs  : vector, card pack
 */
vector<CardPack> Dealer::shuffle(vector<CardPack> cardPack) {

    int index;
    int tempAr[52];
    for (int i = 0; i < 52; ++i) {
        tempAr[i]=1;    //checking same random number generate
    }
    srand(time(0)); //generate different random integer when compile again and again
    for (int i = 0; i < 52; ++i) {
        do {
            index = rand() % 52;    //generate random integers up to 25
        }while(tempAr[index]==0);   //generate random number which not already generated up to 52
        tempAr[index] = 0;  //generatd nuber put in to this array so we can check that number is taken or not

        //swap those cards
        shuffledCardPack.push_back(cardPack[index]);

        //show simulation of the shuffeling
        cout<<"Shuffling ||||......\n";
        cardPack[index].showCard();
        cout<<"\b\bswap with ||||...";
        cardPack[i].showCard();
        cout<<endl;
        Sleep(250);   //sleep 1 second
    }
    return vector<CardPack>(shuffledCardPack);
}
/*
 * Function : distribute
 * Inputs   : player
 * Outputs  : player
 */
Player Dealer::distribute(int playerIndex) {
    Player p;
    for (int cardNo = 0; cardNo < 5; ++cardNo) {    //first 2 cards not distributed
        p.cards[cardNo]=shuffledCardPack[playerIndex+2];  //one player gives card such aay that card0, card5, card10, card15...likewise
        playerIndex += 5;
    }
    return  p;
}
/*
 * Function : higherRank
 * Inputs   : player array, int, int
 * Outputs  : int, higher index
 */
int Dealer::higherRank(Player playerA[5], int i, int j) {
    int index=i;
    for (int k = 0; k < 5; ++k) {
        if (playerA[i].cards[k].getNumber()<playerA[j].cards[k].getNumber())
            index=j;    //when there are sme rank people, highest rank who has highest valued card
    }
    return index;
}
/*
 * Function
 * Inputs
 * Outputs
 */
Dealer::Dealer(Player player) {

}
/*
 * Function
 * Inputs
 * Outputs
 */
Dealer::Dealer() {

}


