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
#include "Hand.h"
#include "Game.h"

using namespace std;


int main() {

	srand(time(NULL));
	Game b;
	b.playerTurn();
	b.dealerTurn();
	b.whoIsWinner();

	return 0;

}
