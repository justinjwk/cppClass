#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Card {

private:

	string rank;
	string suit;
	int rankValue;

public:

	Card() {

	}

	Card (string r, string s) {
		rank = r;
		suit = s;
		setRankValue(r);
	}

	string printCard() {
		return rank + suit;
	}

	string getRank() {
		return rank;
	}

	string getSuit() {
		return suit;
	}

	int getRankValue() {
		return rankValue;
	}

	void setRankValue(string r) {
//		if (r.compare("A") == 0) {
//			rankValue = 1;
//		}
//		else {
//			rankValue = atoi(r);
//		}
	}



};
