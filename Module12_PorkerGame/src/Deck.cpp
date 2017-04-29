/**
 *
 */
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;


const int NUMBER_OF_CARDS = 52;
const int NUMBER_OF_RANK = 13;
const int NUMBER_OF_SUIT = 4;

string rankList[NUMBER_OF_RANK] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
string suitList[NUMBER_OF_SUIT] = {"S", "H", "D", "C"};

class Deck {

private:


	Card *deck;

	srand (time(nullptr));

public:

	Deck() {
		deck = new Card[NUMBER_OF_CARDS];

		for(int i = 0; i < NUMBER_OF_CARDS; i++) {
			deck[i] = Card(rankList[i % 13], suitList[i / 13]);
		}
	}

	void fisherYatesShuffle() {

	}

	void printDeck() {

		for(int i = 0; i < NUMBER_OF_CARDS; i++) {
			cout << deck[i].printCard() << " ";
		}
	}

};