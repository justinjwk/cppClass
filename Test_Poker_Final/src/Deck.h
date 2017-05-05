/*
 * Deck.h
 *
 *  Created on: Apr 30, 2017
 *      Author: Justin
 */

#ifndef DECK_H_
#define DECK_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Card.h"

using namespace std;

class Deck {

public:

	Deck();
	~Deck();
	void fisherYatesShuffle();
	void printDeck();
	Card dealCard();
	bool moreCard();

private:

	vector<Card> deck;
	int currentCardIndex;



};

#endif /* DECK_H_ */
