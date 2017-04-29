#include <iostream>
#include <string>
#include <stdlib.h> //rand and srand
#include <time.h> // time()
#include <sstream> // stringstream
#include <vector>
#include "Card.h"
using namespace std;


//default constructor
Card::Card(){

}

//constructor
Card::Card(string r, string s) {

	rank = r;
	suit = s;

	if ( s == 0 )
		suit_name = "Hearts";
	else if ( s == 1 )
		suit_name = "Diamonds";
	else if ( s == 2 )
		suit_name = "Spades";
	else if ( s == 3 )
		suit_name = "Clubs";

	if ( v < 11 && v > 1 )
	{
		stringstream mystream;
		mystream << v;
		face_name = mystream.str();
	}
	else if ( v == 11 )
		face_name = "Jack";
	else if ( v == 12 )
		face_name = "Queen";
	else if ( v == 13 )
		face_name = "King";
	else if ( v == 1 )
		face_name = "Ace";

	if ( v == 1 ) //makes Aces high cards, Ace are only low in straights
		value = 14;
}

//copy constructor
Card::Card( const Card &Source )
{
	suit = Source.suit;
	value = Source.value;
	suit_name = Source.suit_name;
	face_name = Source.face_name;
}

//assignment operator
Card& Card::operator= ( const Card &Source )
{
	suit = Source.suit;
	value = Source.value;
	suit_name = Source.suit_name;
	face_name = Source.face_name;

	return *this;
}

bool operator== ( Card &C1, Card &C2 )
		{
	return ( C1.value ==  C2.value &&
			C1.suit == C2.suit );
		}

bool operator!= ( Card &C1, Card &C2 )
		{
	return !( C1 == C2 );
		}

int Card::getSuit() { return suit; }

int Card::getValue() { return value; }

string Card::toString() { return face_name + " of " + suit_name; }


