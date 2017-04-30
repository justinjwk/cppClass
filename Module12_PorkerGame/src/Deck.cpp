/**
 *
 */

#include "Deck.h"

static const int NUMBER_OF_CARDS = 52;
static const int NUMBER_OF_RANK = 13;
static const int NUMBER_OF_SUIT = 4;

static const string rankList[NUMBER_OF_RANK] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
static const string suitList[NUMBER_OF_SUIT] = {"S", "H", "D", "C"};


Deck::Deck() {

	for(int i = 0; i < NUMBER_OF_CARDS; i++) {
		deck.push_back(Card(rankList[i % 13], suitList[i / 13]));
	}

	currentCardIndex = 0; 	// current card index
}

Deck::~Deck() {

}

void Deck::fisherYatesShuffle() {

	int randomNum = 0;
	int randIndex = 52;

	Card temp;

	for(int i = NUMBER_OF_CARDS-1; i > -1; i--) {

		randomNum = rand() % randIndex--;

		temp = deck[i];
		deck[i] = deck[randomNum];
		deck[randomNum] = temp;
	}
}

void Deck::printDeck() {

	for(int i = 0; i < NUMBER_OF_CARDS; i++) {
		cout << deck[i].printCard() << " ";
	}
}

Card Deck::dealCard() {
	return deck[currentCardIndex++];
}

bool Deck::moreCard() {
	return (currentCardIndex < 52) ? true : false;
}

