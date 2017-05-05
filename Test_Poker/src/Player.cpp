#include <iostream>
#include <string>
#include "Card.h"
#include "Hand.h"
#include "Game.h"
using namespace std;

//BubbleSort from hand.cc
void BubbleSort( Card h[5] );

int inputValidation( bool zero )
{
	int n;
	bool pass =  false;
	while ( pass == false )
	{
		cin >> n;
		if ( zero == true )
		{
			if ( n > -1 && n < 4 ) //include zero
				pass = true;
			else
				cout << "Invalid Entry" << endl;
		}
		if ( zero == false )
		{
			if ( n > 0 && n < 6 ) //exclude zero
				pass = true;
			else
				cout << "Invalid Entry" << endl;
		}
	}

	return n;
}

void Hand::playersTurn( DeckOfCards &deck )
{
	int n, position[3] = { -1, -1, -1 };
	Card temp[5];

	cout << "\nHow many cards you would to trade?  ";
	n = inputValidation(true);
	for ( int i=0; i<n; i++ )
	{
		cout << "Please enter the card's position\n(top card is 1, bottom card is 5):  ";
		position[i] = inputValidation(false) - 1;
	}
	for ( int j=0; j<5; j++ )
	{
		//check for position
		if ( (position[0] != -1 && position[0] == j) ||
				(position[1] != -1 && position[1] == j) ||
				(position[2] != -1 && position[2] == j) )
			temp[j] = deck.dealCard();
		else
			temp[j] = hand[j];
	}
	hand.clear();
	BubbleSort( temp );
	setHand( temp );
}

void Game::playerTurn()
{
	playersHand.printHand("Original");
	playersHand.playersTurn( deck );
	playersHand.printHand("Current");
}
