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

using namespace std;


int main() {

//	Card c = new Card("3", "H");

	Card c = Card("3","H");


	cout << c.printCard() << endl;

	cout << c.getRankValue() << endl;


	return 0;
}
