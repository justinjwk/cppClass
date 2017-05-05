/*
 * Card.h
 *
 *  Created on: Apr 29, 2017
 *      Author: Justin
 */

#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

class Card {

public:

	Card();
	Card(string, string);
	~Card();

	string printCard();
	string getRank();
	string getSuit();
	int getRankValue();
	void setRankValue(string);
	void setRankValue(int);
	Card& operator= (const Card &c );
	friend bool operator== (Card &c1, Card &c2 );
	friend bool operator!= (Card &c1, Card &c2 );

private:
	string rank;
	string suit;
	int rankValue;

};



#endif /* CARD_H_ */
