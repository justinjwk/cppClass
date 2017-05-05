#include <iostream>
#include <string>
#include <stdlib.h> //srand()
#include "Card.h"
#include "Hand.h"
#include "Game.h"
using namespace std;

//including BubbleSort from hand.cc
void BubbleSort( Card h[5] );

//Additional memeber functions of Hand for the purposes of game.cc
//Additional constructor
Hand::Hand( PLAYER_TYPE o )
{
	playerType = o;
	handValue = unchecked;
	highPair = 0;
	lowPair = 0;
}
//Additional setter
void Hand::setHand( Card arr[5] )
{
	BubbleSort( arr );
	for ( int i=0; i<5; i++ )
		hand.push_back( arr[i] );
	setTypeOfHand();
}

Game::Game() : playersHand(player), computersHand(computer)
{
	cout << "\033[2J\033[1;1H";
	deck.Shuffle();
	Card pCards[5], cCards[5];

	for ( int i=0; i<5; i++ )
	{
		pCards[i] = deck.dealCard();
		cCards[i] = deck.dealCard();
	}
	playersHand.setHand( pCards );
	computersHand.setHand( cCards );
}

void Game::whoIsWinner()
{
	int p = playersHand.getHandValue();
	int c = computersHand.getHandValue();
	string arr[8] = { "unchecked", "high card", "pair", "two pair",
			"three of a kind", "straight", "flush", "four of a kind" };

	cout << "\nplayer: " << arr[p] << "\ncomputer: " << arr[c] << endl;

	if ( p > c )
		cout << "player wins\n" << endl;

	else if ( p < c )
		cout << "computer wins\n" << endl;

	else if ( p == c )
	{
		vector<int> pHigh = playersHand.getHighest();
		vector<int> cHigh = computersHand.getHighest();
		cout << "same hand" << endl;

		//straights, flushes
		if ( p == 5 || p == 6 )
		{
			if ( pHigh[0] > cHigh[0] )
				cout << "player wins!" << endl << endl;
			else
				cout << "computer wins!" << endl << endl;
		}

		//four and three of a kind, and pair
		else if ( p != 5 && p != 6 )
		{
			//determines winner by high card if pair(s) are equal
			if ( playersHand.getHighPair() == computersHand.getHighPair() &&
					playersHand.getLowPair() == playersHand.getLowPair() )
			{
				while ( pHigh.back() == cHigh.back() )
				{
					pHigh.pop_back();
					cHigh.pop_back();
				}
				if ( pHigh.back() > cHigh.back() )
					cout << "player wins, high card" << endl << endl;
				else
					cout << "computer wins, high card" << endl << endl;
			}
			//determines winner by high pair
			else if ( playersHand.getHighPair() > computersHand.getHighPair() )
				cout << "player wins, higher pair (" << playersHand.getHighPair() << " over " << computersHand.getHighPair() << ")" << endl << endl;
			else if ( playersHand.getHighPair() < computersHand.getHighPair() )
				cout << "computer wins, higher pair (" << computersHand.getHighPair() << " over " << playersHand.getHighPair() << ")" << endl << endl;
			//determines winner by low pair if high pairs are equal
			else if ( playersHand.getLowPair() > computersHand.getLowPair() )
				cout << "player wins, highest 2nd pair (" << playersHand.getLowPair() << " over " << computersHand.getLowPair() << ")" << endl << endl;
			else if ( playersHand.getLowPair() < computersHand.getLowPair() )
				cout << "computer wins, highest 2nd pair (" << computersHand.getLowPair() << " over " << playersHand.getLowPair() << ")" << endl << endl;
		}
	}
}
