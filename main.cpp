/*
* DATE       : 28-09-2021
* COURSE     : PROGRAMMING QUEST (CO2210)
* TITLE      : QUEST 04- POKER CARD GAME
* AUTHOR     : MADHUWANTHA A.P.
* INDEX NO   : 19/ENG/121
*/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include <string>
#include <random>
#include <time.h>
#include <fstream>
#include <sstream>
#include "CardPack.h"
#include "Dealer.h"
#include "Player.h"
using namespace std;

int previousMarks[50];  //set previous marks in array
float totalOFALL=0;
/*
 * Function : updateLogFile [update the log file]
 * Inputs   : players array, round
 * Outputs  : N/A
 */
void updateLogFile(Player players[], int round)
{
    int totalMarks=0;
    float winPercent=0;
    ofstream logFile("logFile.txt", fstream::app);
    logFile<<"\nNew Round : "<<round+1<<endl;
    logFile<<"Name\t | Rank\t | Marks | Previous Marks| Total Marks |\n";
    logFile<<"_____________________________________________________________\n";
    for (int i = 0; i < 5; ++i) {
        cout<<endl;
        if (round==0){
            totalMarks=players[i].getMarks();
//            winPercent= abs((totalMarks+/totalOFALL)*100;
            logFile << players[i].getName() << "\t | " << players[i].getRank() << "\t | " << players[i].getMarks()<<"\t | "<< "0\t\t\t | " << totalMarks<<endl;
        }
        else {
            
            totalMarks = players[i].getMarks() + previousMarks[(round - 1) * 5 + i];
//            winPercent= abs(totalMarks/totalOFALL)*100;
            previousMarks[round*5+i]=totalMarks;    //update previous marks for future useage
            logFile << players[i].getName() << "\t | " << players[i].getRank() << "\t | " << players[i].getMarks()<<"\t | "<< previousMarks[(round - 1) * 5 + i]
            << "\t\t\t | " << totalMarks<< endl;
        }

    }
    logFile<<"_____________________________________________________________\n";
    logFile.close();
}
/*
 * Function : main
 * Inputs   : N/A
 * Outputs  : N/A
 */
int main() {
    //assume there are 4 players include user and 10 rounds for a game
    Player player1, player2, player3, player4,player5;
    Player playersA[5]={player1, player2, player2, player4, player5}; //make a players array
    cout<<"Select the Character from Players.....\n";
    cout<<"1. Jack\n2. Fred\n3. Nick\n4. Babara\n\n";

    remove("logFile.txt");  //remove the file when strat the program

    int playerNo;
    do {
        cin>>playerNo;
            playerNo=1;     //for testing

    }while(!(playerNo>0 && playerNo<=4));
    playerNo -= 1; //for indexing


    for (int round = 0; round < 10; ++round) { //one game have ten round
        cout<<"\n___________ Round  "<<round+1<<" ___________" << endl;
        vector<CardPack> cardPack;  //make a card pack
        Dealer dealer;  //make a dealer
        cardPack=dealer.newCardPack();  //generate a new card pack
        dealer.shuffle(cardPack);  //shuffle the card pack
        cout << ".....................Shuffle Completed.....................\n\n";
        Sleep(2000);  //output of the shuffled card pack will dissaper within 2 seconds
        system("cls"); // clear console

        cout << "\n\nCards Are Distributing...\n";
        playersA[0] = dealer.distribute(0);    //dealer starts to distribute the cards
        playersA[1] = dealer.distribute(1);
        playersA[2] = dealer.distribute(2);
        playersA[3] = dealer.distribute(3);
        playersA[4] = dealer.distribute(4);
        //programmer can change the name of the player
        playersA[0].setName("Jack");
        playersA[1].setName("Fred");
        playersA[2].setName("Nick");
        playersA[3].setName("Babara");
        playersA[4].setName("Dealer");

        cout << "\nShow Cards of the Player ->";
        cout << playersA[playerNo].getName() << "\n";
        playersA[playerNo].showPlayerCards();

        cout << "\nShow Cards of the Dealer ->\n";
        playersA[4].showPlayerCards();   //inherited method from player

         for (int i = 0; i < 5; ++i) {  //set rank fro all players
             playersA[i].setRank(playersA[i].rank());
         }

        cout << "\nDo you want to withdraw? [y/n]\n";   //ask for withdraw
        char condition;
        cin>>condition;
        //condition = 'y';  //for testing

        //automate other players decision
        int cnd=0;
        srand(time(0));
        for (int i = 0; i < 4; ++i) {
            if (playersA[i].getRank()>playersA[4].getRank())
                cnd=1;  //if rank is higher than dealer do not withdraw
            else if (playersA[i].getRank()==playersA[4].getRank() &&  dealer.higherRank(playersA, i, 4)==i)
                cnd=1;  //if rank is same as dealer then check for highest card available in player
            else
                cnd=0;
            playersA[i].setCondition(1);
            if (i != playerNo && cnd == 0)
                cout << playersA[i].getName() << " Withdraw tha hand..!!!\n";
        }

        if (condition == tolower('y'))   //if the player decide to withdraw
        {
            playersA[playerNo].setCondition(0); //zero for who decide to withdraw
            cout << playersA[playerNo].getName() << " (You) Withdraw tha hand..!!!\n";
        } else
            playersA[playerNo].setCondition(1);

        playersA[4].setCondition(0);    //dealer marks does not change


        int nameIndex = 0;    //winner is the max rank person
        int maxHand = playersA[0].getRank();
        for (int i = 0; i < 5; ++i) {

            if (maxHand < playersA[i].getRank()) {
                maxHand = playersA[i].getRank();
                nameIndex = i;
            } else if (maxHand == playersA[i].getRank()) {
                nameIndex = dealer.higherRank(playersA, nameIndex, i);
                maxHand = playersA[i].getRank();
            }
        }

        //print the ranks of the players
        cout << "The Winner!!..";
        switch (nameIndex) {
            case 0:
                cout << playersA[0].getName() << "\n";
                break;
            case 1:
                cout << playersA[1].getName() << "\n";
                break;
            case 2:
                cout << playersA[2].getName() << "\n";
                break;
            case 3:
                cout << playersA[3].getName() << "\n";
                break;
            case 4:
                cout << playersA[4].getName() << "\n";
                break;
        }

        cout << "............Score Card............\n";
        for (int i = 0; i < 5; ++i) {   //dealer does not change the marks
            playersA[i].setMarks(-1);   //set default mark as -1
            if (i == nameIndex)
                playersA[i].setMarks(10);   //winner
            if (!playersA[i].getCondition())    //No points will be reduced from the player who withdraw
                playersA[i].setMarks(0);
            totalOFALL += playersA[i].getMarks()+2;
            //take current total marks for winning probability
            previousMarks[round*5+i]=playersA[i].getMarks();
            cout << playersA[i].getName() << "\t| " << playersA[i].getRank() << "\t| " << playersA[i].getMarks() << endl;
            cout << "_____________________________\n";

        }

        updateLogFile(playersA, round);
        Sleep(3000);
        system("cls");
    }
     //show final marks
     cout<<"\n...............Final Marks...............\n";
    cout<<"Name\t| Rank\t| Marks\t\n";
    cout << "_____________________________\n";
    for (int i = 0; i < 5; ++i) {
        cout << playersA[i].getName() << "\t| " << playersA[i].getRank() << "\t| " << playersA[i].getMarks() << endl;
        cout << "_____________________________\n";
    }
    return 0;
}
