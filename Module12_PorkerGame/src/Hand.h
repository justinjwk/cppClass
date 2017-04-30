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
enum HAND_VALUE {unchecked, highCard, onePair, threeOfKind, straight, flush, fullHouse, fourOfKind, straightFlush};

class Hand {

public:

	Hand();
	Hand(Deck d, PLAYER_TYPE p);
	~Hand();
	void sortCards(Card cardHand[5]);
	vector<int> getHighest();
	int getHighPair();
	int getLowPair();
	HAND_VALUE getHandValue();
	void printHand(string str);

private:

	vector<Card> hand;
	PLAYER_TYPE playerType;
	HAND_VALUE handValue;
	vector<int> highList;
	int highPair;
	int lowPair;

};



#endif /* HAND_H_ */
