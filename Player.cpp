//
// Created by Pasindu on 10/5/2021.
//

#include "Player.h"
/*
 * Function : showPlayerCards
 * Inputs   : N/A
 * Outputs  : N/A
 */
void Player::showPlayerCards() {
    for (int i = 0; i < 5; ++i) {   //show 5 card of the player within dealer
        cards[i].showCard();
    }
}
/*
 * Function : rank
 * Inputs   : N/A
 * Outputs  : int, rank
 */
int Player::rank() {
    int valueArray[15];
    int suitArray[4];
    //intialize the two arrays
    for (int i = 0; i < 4; ++i) {
        suitArray[i]=0;
    }
    for (int i = 0; i < 15; ++i) {
        valueArray[i]=0;
    }

    for (int i = 0; i < 5; ++i) {
        //suit array increase by 1 accordingly, shit start from 1
        switch (cards[i].getSuit()) {
            case 1: suitArray[0]++; break;  //if the suit is club=1, then suitArray 0 index value increase bu 1
            case 2: suitArray[1]++; break;
            case 3: suitArray[2]++; break;
            case 4: suitArray[3]++; break;
        }
        switch (cards[i].getNumber()) {
            //number array increase by 1, if similar number apar
            case 2: valueArray[2]++; break;
            case 3: valueArray[3]++; break;
            case 4: valueArray[4]++; break;
            case 5: valueArray[5]++; break;
            case 6: valueArray[6]++; break;
            case 7: valueArray[7]++; break;
            case 8: valueArray[8]++; break;
            case 9: valueArray[9]++; break;
            case 10: valueArray[10]++; break;
            case 11: valueArray[11]++; break;
            case 12: valueArray[12]++; break;
            case 13: valueArray[13]++; break;
            case 14: valueArray[1]++; valueArray[14]++; break; //Ace, some time take as 1
        }


    }
    //intialize retun values
    int highCard=0, onePair=0, twoPair=0, threeOFKind=0, straight=0, flushCol=0, fullHouse=0, fourOfKind=0, straightFlush=0;

    if ((suitArray[0]==5) || (suitArray[1]==5) || (suitArray[2]==5) ||(suitArray[3]==5) ||(suitArray[4]==5))
        straightFlush=1;    //can no decide yet, whether straight flush or not

    if ((suitArray[0]+suitArray[2])==5 ||(suitArray[1]+suitArray[3])==5 || straightFlush==1)   //flush colour when same colours appear
        flushCol=1;

    for (int i = 0; i < 15; ++i) {
        if (valueArray[i]==4)
            fourOfKind=1;
        else if (valueArray[i]==3)
            threeOFKind=1;
        else if (valueArray[i]==2)
            onePair++;  //two one pairs means 2 of pairs
    }
    //checking for straight
    for (int i = 1; i <11 ; ++i) {
        if ((valueArray[i]==1) && (valueArray[i+1]==1) && (valueArray[i+2]==1) && (valueArray[i+3]==1) && (valueArray[i+4]==1))
            straight=1;
    }

    if (straightFlush==1 && straight==1)
        return 9;
    else if(fourOfKind==1)
        return 8;
    else if(threeOFKind==1 && onePair==1)
        return 7;
    else if(flushCol==1)
        return 6;
    else if (straight==1)
        return 5;
    else if (threeOFKind==1)
        return 4;
    else if(onePair==2)
        return 3;
    else if(onePair==1)
        return 2;
    else
        return  0;
}

Player::Player() {}
//set player name
Player::Player(string name) :playerName(name){}
//return player name
string Player::getName() {
    return playerName;
}
//set player name
void Player::setName(string name) {
    playerName=name;
}
//set marks
void Player::setMarks(int ma) {
    marks=ma;
}
//rerturn mark
int Player::getMarks() {
    return marks;
}
//set condition withdraw or not
void Player::setCondition(int cnd) {
    condition=cnd;
}
//get condition
int Player::getCondition() {
    return condition;
}
//set rank
void Player::setRank(int rnk) {
    this->rankNO=rnk;
}
//get the rank
int Player::getRank() {
    return rankNO;
}

