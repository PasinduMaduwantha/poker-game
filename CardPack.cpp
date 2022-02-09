////
//// Created by Pasindu on 10/4/2021.
////
//

#include "CardPack.h"
/*
 * Function : CardPack
 * Inputs   : N/A
 * Outputs  : N/A
 */
CardPack::CardPack():number(0), suit(0) {}  //initialize default constructor as 0 in members
CardPack::CardPack(int n, int s):number(n), suit(s) {}  //override the constructor if it pass values
/*
 * Function : setCard
 * Inputs   : int, int
 * Outputs  : card
 */
CardPack CardPack::setCard(int nu, int su) {
    this->number = nu;
    this->suit = suit;
    CardPack cd(number, su);
    return cd;  //return CardPack object

}
/*
 * Function : getSuit
 * Inputs   : N/A
 * Outputs  : int, number
 */
int CardPack::getSuit()const {
    return this->suit;
}
/*
 * Function : getNumber
 * Inputs   : N/A
 * Outputs  : int, number
 */
int CardPack::getNumber()const {
    return this->number;
}
/*
 * Function : showCard
 * Inputs   : N/A
 * Outputs  : N/A
 */
void CardPack::showCard()const {
//    _setmode(_fileno(stdout), 0x00020000);  //For print _O_U16TEXT
    //print corresponding value and the suit as real cards EX: Ace of Clubs
    if(number>1 && number<=10)
        cout<<number;
    else{
        switch (number) {
            case 11: cout<<"J"; break;
            case 12: cout<<"Q"; break;
            case 13: cout<<"K"; break;
            case 14: cout<<"A"; break;
        }
    }

    switch (suit) {

//        case 1: wprintf(L"\u2663"); break;
//        case 2: wprintf(L"\u2665"); break;
//        case 3: wprintf(L"\u2660"); break;
//        case 4: wprintf(L"\u2666"); break;
        case 1: cout<<" of Clubs"<<endl; break;
        case 2: cout<<" of Hearts"<<endl; break;
        case 3: cout<<" of Spades"<<endl; break;
        case 4: cout<<" of Diamonds"<<endl; break;
    }
}
