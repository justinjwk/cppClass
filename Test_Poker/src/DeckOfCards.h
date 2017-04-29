/*
 * DeckOfCards.h
 *
 *  Created on: Apr 29, 2017
 *      Author: Justin
 */

#ifndef DECKOFCARDS_H_
#define DECKOFCARDS_H_

#include <string>
#include <vector>
#include <stdlib.h>
#include "Card.h"

using namespace std;

class DeckOfCards {

public:
	DeckOfCards();
	void Shuffle();
	Card dealCard();
	bool moreCards();

private:
	vector<Card> deck;
	int currentCard;


};




#endif /* DECKOFCARDS_H_ */
