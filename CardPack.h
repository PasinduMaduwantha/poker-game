//
// Created by Pasindu on 10/4/2021.
//

#ifndef Q4CODE_CARDPACK_H
#define Q4CODE_CARDPACK_H

#include <iostream>
#include <stdio.h>
#include <io.h>


using namespace std;

class CardPack {
protected:
    int number, suit;   //each card has a vale
    //number and suit make as private members otherwise they will assign misleading value to the cards
public:
    CardPack();
    CardPack(int, int);
    CardPack setCard(int, int); //to input data into the card pack
    int getSuit()const;  //return the suit
    int getNumber()const;    //return the card number
    void showCard()const;    //print the card

};
//
//CardPack::CardPack() {}  //initialize default constructor as 0 in members
//CardPack::CardPack(int n, int s):number(n), suit(s) {}  //override the constructor if it pass values
//
//CardPack CardPack::setCard(int nu, int su) {
//    number = number;
//    suit = suit;
//    CardPack cd(number, suit);
//    return cd;  //return CardPack object
//
//}
//
//int CardPack::getSuit()const {
//    return suit;
//}
//
//int CardPack::getNumber()const {
//    return number;
//}
//
//void CardPack::showCard()const {
//    //print corresponding value and the suit as real cards EX: Ace of Clubs
//    if(number>1 && number<=10)
//        cout<<number;
//    else{
//        switch (number) {
//            case 11: cout<<"Jack"; break;
//            case 12: cout<<"Queen"; break;
//            case 13: cout<<"King"; break;
//            case 14: cout<<"Ace"; break;
//        }
//    }
//    switch (suit) {
//        case 1: cout<<" of Clubs"<<endl; break;
//        case 2: cout<<" of Hearts"<<endl; break;
//        case 3: cout<<" of Spades"<<endl; break;
//        case 4: cout<<" of Diamonds"<<endl; break;
//    }
//}


#endif //Q4CODE_CARDPACK_H
