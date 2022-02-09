# poker-game

Poker Card Game

A poker game take place with all 52 cards in the card pack. Every card has a Value (2 to 10, Jack, Queen, King, and Aces) and Shape (Spade, Diamond, Heart, and Club). Dealer shuffles the cards, removes the first two cards in the pack, and distributes five cards for each player including
himself. The players’ hands are not visible but the dealer cards are visible. In gambling arena, players are gambling based on their hands (five cards they received). We do not consider gambling in this quest. Each hand get a score based on the combination it can form as listed below with the ascending
order of the scores. 1. High card: None of the following combinations and highest card value is considered (2-2, 3-3, …, 10-10, Jack-11, Queen-12, King-13, Aces-14)
2. One pair: two cards with the same value. 3. Two pairs: two times two cards of same value. 4. Three of a kind: Three cards with same value. 5. Straight: five cards with values in sequence (Ace can also be seen as one, but we must
choose:

The values "Ace-2-3-4-5" form a sequence, like the values "10 - Jack - Queen - King - Ace ", but, for example, values" King - Ace -2 - 3 - 4 "are not a sequence). 6. Flush(color): Five cards with same color. 7. Full house: three of a kind and one pair. (combination 2 and combination 3)
8. Four of a kind: four cards with same value. 9. Straight Flush: Straight in which the cards have the same suite. If there is a tie situation, the one with the highest score card wins the game

Examples:
Consider there are two players and the dealer and all of them have High Card combination. Then the one with highest score card wins the game. Consider there is a player and the dealer, where both of them have Full-House: Dealer has 2-S, 2-C, 10-D, 10-S, 10-C and player has 4-H,4-C, Q-C, Q-D, Q-S). The one with the highest score
cards win the game. If (A, K, Q, J, 10) and (8,7,6,5,4) with same suite is received. Then the hand with A wins the
game. There is no value difference on suites (Heart, Spade, Diamond, and Clubs).

Use object oriented programming concepts in the quest
You can define the number of players join the game and how many rounds the Poker game is
played. Simulate the card shuffling by the dealer
Simulate the card distribution by the dealer

Indicate the player who has the best combination (winner). The winner receives 10 points. The losers get -1 point. The dealer does not receive or loose any points. Simulate a score card where the game watchers can view. The score card should indicate the
probability of winning the game. Once the cards are distributed and dealer cards are visible to the user, players are given a
chance to withdraw from that game round if they wish. The score card should be updated if a
player withdraw from the round accordingly. The dealer never withdraw from the game. The
programme user can decide whether the player stays or withdraw from the round. No points
will be reduced from the player who withdraw. At the end of the game, the score card indicate the points of each player. Log all the activities to a log file for future analysis
