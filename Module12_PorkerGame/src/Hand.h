/*
 * Hand.h
 *
 *  Created on: Apr 30, 2017
 *      Author: Justin
 */

#ifndef HAND_H_
#define HAND_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Card.h"
#include "Deck.h"

using namespace std;

enum PLAYER_TYPE {player, computer};
enum HAND_VALUE {unchecked, highCard, onePair, twoPair, threeOfKind, straight, flushCard, fullHouse, fourOfKind, straightFlush};

class Hand {

public:

	// hand-ranks
	static const int STRAIGHT_FLUSH = 1;
	static const int FOUR_OF_A_KIND = 2;
	static const int FULL_HOUSE = 3;
	static const int FLUSH = 4;
	static const int STRAIGHT = 5;
	static const int THREE_OF_A_KIND = 6;
	static const int TWO_PAIR = 7;
	static const int ONE_PAIR = 8;
	static const int HIGH_CARD = 9;

	Hand();
	Hand(Deck d, PLAYER_TYPE p);
	Hand(PLAYER_TYPE p);
	~Hand();
	void sortCards(Card cardHand[5]);
	vector<int> getHighest();
	void findACEwithKing(Card cardHand[5]);
	int getHighPair();
	int getLowPair();
	HAND_VALUE getHandValue();
	void printHand(string str);
	void setHand(Card cardHand[5]);

	int isFlush();
	int isStraight();
	int isStraightFlush();
	void findHighCard();
	int pairCounter();
	bool isOnePair();
	bool isTwoPair();
	void setTypeOfHand();
	void displayResult(int rankScore);

	int inputValidation(bool zero);
	void playersTurn(Deck &deck);
	void tradeCard(Deck &deck, int n);

private:

	vector<Card> hand;
	PLAYER_TYPE playerType;
	HAND_VALUE handValue;
	vector<int> highList;
	int highPair;
	int lowPair;

};



#endif /* HAND_H_ */
