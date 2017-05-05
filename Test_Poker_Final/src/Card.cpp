
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
		rankValue = 14;
	}
	else if (r.compare("J") == 0) {
		rankValue = 11;
	}
	else if (r.compare("Q") == 0) {
		rankValue = 12;
	}
	else if (r.compare("K") == 0) {
		rankValue = 13;
	}
	else {
		stringstream ss(r);
		ss >> rankValue;
		//			rankValue = atoi(r.c_str());
	}
}

void Card::setRankValue(int value) {
	if(value > 0 && value < 15 ) {
		rankValue = value;
	}
	else {
		rankValue = 0;
	}

}

//assignment operator
Card& Card::operator= (const Card &c ) {
	suit = c.suit;
	rank = c.rank;
	setRankValue(c.rank);

	return *this;
}

bool operator== (Card &c1, Card &c2) {
	return ((c1.getRankValue() == c2.rankValue) &&
			(c1.getSuit().compare(c2.getSuit())));
}

bool operator!= (Card &c1, Card &c2) {
	return !( c1 == c2 );
				}