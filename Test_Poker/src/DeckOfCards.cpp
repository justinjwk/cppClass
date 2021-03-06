#include <iostream>

#include <stdlib.h> //rand and srand
//#include <time.h> // time()



#include "DeckOfCards.h"


DeckOfCards::DeckOfCards()
{
	int i, j=1, k=0;
	for ( i=0; i<52; i++ )
	{
		deck.push_back( Card(k,j) );
		j++;
		if ( j == 14 ) //checks for 13 created cards of 1 suit
		{
			j = 1;
			k++;
		}
	}

	currentCard = 0; //sets the "next card to be dealt" to vector position 0
}

void DeckOfCards::Shuffle()
{
	int i, j, Ran;
	Card temp;

	for ( j=0; j<2; j++ ) //iterates the deck twice to ensure good shuffle
	{
		for ( i=0; i<52; i++ )
		{
			//generates random numbers between 0 to 51
			Ran = rand() % 52;

			//swaps the two cards picked by the random number and i
			temp = deck[i];
			deck[i] = deck[Ran];
			deck[Ran] = temp;
		}
	}
}

Card DeckOfCards::dealCard() {
	return deck[currentCard++];
}

bool DeckOfCards::moreCards() {
	return ( currentCard < 52 ) ? true : false;
}
