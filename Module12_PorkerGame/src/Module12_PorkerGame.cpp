//============================================================================
// Name        : Module12_PorkerGame.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include "Card.h"
#include "Deck.h"

using namespace std;


int main() {

//	Card c = new Card("3", "H");

	Card c = Card("A","H");


	cout << c.printCard() << endl;

	cout << c.getRankValue() << endl;

//	Deck d = new Deck();

//	d.printDeck();

	Deck d = Deck();

	d.printDeck();
	cout << endl;

	d.fisherYatesShuffle();
	cout << endl;
	d.printDeck();


	return 0;
}
