#ifndef CARD_H_
#define CARD_H_

#include <string>
#include <vector>
using namespace std;

class Card {



public:
	Card();
	Card(string r, string s);
	Card(const Card &Source);
	Card& operator= (const Card &Source);
	friend bool operator== (Card &c1, Card &c2);
	friend bool operator!= (Card &c1, Card &c2 );
	string getSuit();
	string getValue();
	string printCard();

private:
	string rank;
	string suit;

};



#endif
