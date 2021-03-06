/*
 * Game.h
 *
 *  Created on: May 4, 2017
 *      Author: Justin
 */

#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Card.h"
#include "Hand.h"
#include "Deck.h"


using namespace std;

class Game {

public:
	Game();
	void whoIsWinner();
	void dealerTurn();
	void playerTurn();

private:

	Deck deck;
	Hand playersHand;
	Hand computersHand;
};



#endif /* GAME_H_ */
