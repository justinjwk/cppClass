#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include "Card.h"

using namespace std;


	Card::Card() {

	}

	Card::~Card() {

	}

	Card::Card (string r, string s) {
		rank = r;
		suit = s;
		setRankValue(r);
	}

	string Card::printCard() {
		return rank + suit;
	}

	string Card::getRank() {
		return rank;
	}

	string Card::getSuit() {
		return suit;
	}

	int Card::getRankValue() {
		return rankValue;
	}

	void Card::setRankValue(string r) {
		if (r.compare("A") == 0) {
			rankValue = 1;
		}
		else {
			stringstream ss(r);
			ss >> rankValue;
//			rankValue = atoi(r.c_str());
		}
	}


