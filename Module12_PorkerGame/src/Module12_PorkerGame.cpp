//============================================================================
// Name        : Module12_PorkerGame.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Card {

	static const int NUMBER_OF_RANK = 13;
	static const int NUMBER_OF_SUIT = 4;

	string rankList[NUMBER_OF_RANK] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	string suitList[NUMBER_OF_SUIT] = {"S", "H", "D", "C"};

	int rankInt;
	int suitInt;
	string rank;
	string suit;

public:

	Card() {

	}

	Card (int r, int s) {
		rankInt = r;
		suitInt = s;
	}

	int getRankInt() {
		return rankInt;
	}

	int getSuitInt() {
		return suitInt;
	}

	string getRank() {
		return rankList[rankInt - 1];
	}

	string getSuit() {
		return suitList[suitInt - 1];
	}

	string getCardValue() {
		return getRank() + getSuit();
	}

};

class Deck {

	static const int NUMBER_OF_CARDS = 52;



public:

	/*Card::Card deck[NUMBER_OF_CARDS];

	void initialDeck() {

		for(int i = 0; i < NUMBER_OF_CARDS; i++) {
			deck[i] = Card(i % 13, i / 13);
		}
	}

	void displayDeck() {
		for(int i = 0; i < NUMBER_OF_CARDS; i++) {
			cout << deck[i].getCardValue() << " " << endl;
		}
	}*/

};












/*
int main() {

//	Card c1("2","S");
//	cout << c1.displayCard();

	Deck d;
	d.displayDeck();

	return 0;
}*/