//============================================================================
// Name        : Poker.cpp
// Author      : Justin Kim
// Description : This program is a Poker game
//				 The user and computer will have 5 cards which are selected
//				 randomly. This program compares two players cards and find
//				 who winner is. This program has functions that can find
//				 Straight flush, Four of a kind, Full house, Flush, Straight,
//				 Three of a kind, Two pair, One pair, and High card
//============================================================================

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include "time.h"
#include "Poker.h"
using namespace std;

/**
 * Default constructor
 */
Poker::Poker() {

}


/**
 * This method create a deck of 52 cards
 */
void Poker::createDeck() {
	for(int i = 0; i < NUMBER_OF_CARDS; i ++) {
		deck[i] = i;
	}
}


/**
 * This method shuffles a deck of 52 cards
 */
void Poker::shuffleDeck() {
	srand(time(0));
	random_shuffle(&deck[0], &deck[52]);
}

/**
 * This method prints a deck
 */
void Poker::printDeck() {
	for(int i = 0; i < NUMBER_OF_CARDS; i++) {
		int rankNum = deck[i] % 13; 		// 0 ~ 12
		int suitNum = deck[i] / 13; 		// 0 ~ 3
		cout << rank[rankNum] << suit[suitNum] << " ";
	}
	cout << endl;
}

/**
 * This method converts player's card string array to int array
 */
void Poker::convertPlayerArrayToSortedIntArray(string rankIn[5]) {

	// A will be treated differently if there is a K in hand
	bool hasK = false;

	// loop through to find existence of K card in the hand
	for(int i = 0; i < NUMBER_OF_HAND; i++) {
		if (rankIn[i].compare("K") == 0) {
			hasK = true;
		}
	}

	// loop rank array to convert string to integer
	for(int i = 0; i < NUMBER_OF_HAND; i++) {
		// J to 11
		if (rankIn[i].compare("J") == 0) {
			sortedPlayerRank[i] = 11;
		}
		// Q to 12
		else if (rankIn[i].compare("Q") == 0) {
			sortedPlayerRank[i] = 12;
		}
		// K to 13
		else if (rankIn[i].compare("K") == 0) {
			sortedPlayerRank[i] = 13;
		}
		// for A
		else if (rankIn[i].compare("A") == 0) {
			// If there is a K in the hand, then A is 14
			if(hasK) {
				sortedPlayerRank[i] = 14;
			}
			// If there is not a K in the hand, then A is 1
			else {
				sortedPlayerRank[i] = 1;
			}
		}
		// other cases
		else {
			// convert string to integer
			sortedPlayerRank[i] = atoi(rankIn[i].c_str());
		}
	}

	// sort int array for easy comparison
	sort(&sortedPlayerRank[0], &sortedPlayerRank[5]);

}

/*
 * This method converts computer's card string array to int array
 */
void Poker::convertComputerArrayToSortedIntArray(string rankIn[5]) {

	// A will be treated differently if there is a K in hand
	bool hasK = false;

	// loop through to find existence of K card in the hand
	for(int i = 0; i < NUMBER_OF_HAND; i++) {
		if (rankIn[i].compare("K") == 0) {
			hasK = true;
		}
	}

	// loop rank array to convert string to integer
	for(int i = 0; i < NUMBER_OF_HAND; i++) {
		// J to 11
		if (rankIn[i].compare("J") == 0) {
			sortedComputerRank[i] = 11;
		}
		// Q to 12
		else if (rankIn[i].compare("Q") == 0) {
			sortedComputerRank[i] = 12;
		}
		// K to 13
		else if (rankIn[i].compare("K") == 0) {
			sortedComputerRank[i] = 13;
		}
		// for A
		else if (rankIn[i].compare("A") == 0) {
			// If there is a K in the hand, then A is 14
			if(hasK) {
				sortedComputerRank[i] = 14;
			}
			// If there is not a K in the hand, then A is 1
			else {
				sortedComputerRank[i] = 1;
			}
		}
		// other cases
		else {
			// convert string to integer
			sortedComputerRank[i] = atoi(rankIn[i].c_str());
		}
	}

	// sort int array for easy comparison
	sort(&sortedComputerRank[0], &sortedComputerRank[5]);

}

/**
 * This method deals 5 cards to player and computer
 */
void Poker::dealCards() {

	int playerCardCounter = 0;
	int computerCardCounter = 0;

	// take first 10 cards from the deck to deal
	for(int i = 0; i < 10; i++) {
		int rankNum = deck[i] % 13;
		int suitNum = deck[i] / 13;

		// if odd number of turn, deal the card to user
		if ((i % 2) == 0) {
			playerRank[playerCardCounter] = rank[rankNum];
			playerSuit[playerCardCounter] = suit[suitNum];
			playerCardCounter++;

		}
		// if even number of turn, deal the card to computer
		else {
			computerRank[computerCardCounter] = rank[rankNum];
			computerSuit[computerCardCounter] = suit[suitNum];
			computerCardCounter++;
		}
	}

	// convert string array to int array for easy comparison
	convertPlayerArrayToSortedIntArray(playerRank);
	convertComputerArrayToSortedIntArray(computerRank);
}

/**
 * This method prints Player's cards
 */
void Poker::printPlayerHand() {

	cout << "Player's hand : " ;
	for(int i = 0; i < NUMBER_OF_HAND; i++) {
		cout << playerRank[i] << playerSuit[i] << " ";
	}
	cout << endl;
}

/**
 * This method prints Computer's cards
 */
void Poker::printComputerHand() {

	cout << "Computer's hand : ";
	for(int i = 0; i < NUMBER_OF_HAND; i++) {
		cout << computerRank[i] << computerSuit[i] << " ";
	}
	cout << endl;
}

/**
 * This method finds out flush cards
 */
int Poker::flush(string suitIn[NUMBER_OF_HAND]) {

	// if every card's suit is the same, then it's flush
	if ((suitIn[0].compare(suitIn[1]) == 0)
			&& (suitIn[1].compare(suitIn[2]) == 0)
			&& (suitIn[2].compare(suitIn[3]) == 0)
			&& (suitIn[3].compare(suitIn[4]) == 0)) {
		return FLUSH;
	}
	else {
		return 0;
	}
}

/*
 * This method finds straight card
 */
int Poker::straight(int rankIn[NUMBER_OF_HAND]) {

	bool isStraight = true;

	// find out whether two neighbor numbers are continuous number
	// if two neigher number is not continous number, then assign isStraint to false
	for(int i = 0; i < 4; i++) {
		if(rankIn[i+1] - rankIn[i] != 1) {
			isStraight = false;
			break;
		}
	}

	// return STRAIGHT if it is straight card
	if(isStraight) {
		return STRAIGHT;
	}
	else {
		return 0;
	}
}

/**
 * This method finds Straight Flush cards
 */
int Poker::straightFlush(int rankIn[NUMBER_OF_HAND], string suitIn[NUMBER_OF_HAND]) {

	// If both Flush and Straight are true, then it's Straight Flush
	if(flush(suitIn) && straight(rankIn)) {
		return STRAIGHT_FLUSH;
	}
	else {
		return 0;
	}
}

/**
 * This method counts how many pairs in hand
 * If there are 4 same rank cards, it returns FOUR_OF_A_KIND
 * If there are 3 same rank cards with one pair, it returns FULL_HOUSE
 * If there are only 3 same rank cards, it returns THREE_OF_A_KIND
 * If there are more than one one-pair, it returns TWO_PAIR
 * If there are only one one-pair, it returns ONE_PAIR
 */
int Poker::pairCounter(int rankIn[NUMBER_OF_HAND]) {

	// to see how many pairs are in hand and where they are
	int counter[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	// loop rank array to count how many the same ranks are in a hand
	for(int i = 0; i < NUMBER_OF_HAND; i++) {

		int num;

		num = rankIn[i];
		counter[num - 1] = counter[num - 1] + 1;
	}

	int fourOfKind = 0;
	int threeOfKind = 0;
	int pair = 0;

	// loop through counter array
	for(int i = 0; i < 13; i++) {
		// if there are 4 same cards
		if (counter[i] == 4) {
			fourOfKind += 1;
		}
		// if there are 3 same cards
		if (counter[i] == 3) {
			threeOfKind += 1;
		}
		// if there are 2 same cards
		if (counter[i] == 2) {
			pair += 1;
		}
	}

	// If there are 4 same cards, return FOUR_OF_A_KIND
	if (fourOfKind == 1) {
		return FOUR_OF_A_KIND;
	}
	// If there are 3 same cards
	else if (threeOfKind == 1) {
		// and there is a pair, return FULL_HOUSE;
		if(pair > 0) {
			return FULL_HOUSE;
		}
		// if there is no additional pair, return THREE_OF_A_KIND;
		else {
			return THREE_OF_A_KIND;
		}
	}
	// If there are two of one pair, return TWO_PAIR
	else if (pair == 2) {
		return TWO_PAIR;
	}
	// IF there is only one one pair, return ONE_PAIR
	else if (pair == 1) {
		return ONE_PAIR;
	}
	// Otherwise, return HIGH_CARD
	else {
		return HIGH_CARD;
	}
}

/*
 * This methods returns what combination the hand is
 */
int Poker::getRank(int rankIn[5], string suitIn[5]) {

	// return scores based on their combination
	// 0 - high, 9 - low
	if(straightFlush(rankIn, suitIn) == STRAIGHT_FLUSH) {
		return STRAIGHT_FLUSH;
	}
	else if(pairCounter(rankIn) == FOUR_OF_A_KIND) {
		return FOUR_OF_A_KIND;
	}
	else if(pairCounter(rankIn) == FULL_HOUSE) {
		return FULL_HOUSE;
	}
	else if(flush(suitIn) == FLUSH){
		return FLUSH;
	}
	else if(straight(rankIn) == STRAIGHT) {
		return STRAIGHT;
	}
	else if(pairCounter(rankIn) == THREE_OF_A_KIND) {
		return THREE_OF_A_KIND;
	}
	else if(pairCounter(rankIn) == TWO_PAIR) {
		return TWO_PAIR;
	}
	else if(pairCounter(rankIn) == ONE_PAIR) {
		return ONE_PAIR;
	}
	else {
		return HIGH_CARD;
	}

}

/**
 * This method prints what kind of card winner has
 */
void Poker::displayResult(int rankScore) {

	switch(rankScore) {
	case 1 : cout << "Straight Flush!" << endl;
			 break;
	case 2 : cout << "Four of a Kind!" << endl;
			 break;
	case 3 : cout << "Full House!" << endl;
			 break;
	case 4 : cout << "Flush!" << endl;
			 break;
	case 5 : cout << "Straight!" << endl;
			 break;
	case 6 : cout << "Three of a Kind!" << endl;
			 break;
	case 7 : cout << "Two Pair!" << endl;
			 break;
	case 8 : cout << "One Pair!" << endl;
			 break;
	case 9 : cout << "High Card!" << endl;
			 break;
	default : break;
	}
}

/**
 * This method plays game and determine who winner is
 */
void Poker::playGame() {

	int playerScore;
	int computerScore;
	int playerCounter[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int computerCounter[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	playerScore = getRank(sortedPlayerRank, playerSuit);

	computerScore = getRank(sortedComputerRank, computerSuit);

	// if player has better combination
	if(playerScore < computerScore) {
		cout << "Player Win! - ";
		displayResult(playerScore);
	}
	// if computer has better combination
	else if (playerScore > computerScore) {
		cout << "Computer Win! - ";
		displayResult(computerScore);
	}
	// if both have the same combination, then compare details
	else {
		// STRAIGHT FLUSH AND STRAIGHT
		if (playerScore == STRAIGHT_FLUSH || playerScore == STRAIGHT) {
			// compare the highest number
			// if player has higher number, then player wins
			if(sortedPlayerRank[4] > sortedComputerRank[4]) {
				cout << "Player Win! - ";
				displayResult(playerScore);
			}
			// if computer has higher number, then computer wins
			else if (sortedPlayerRank[4] < sortedComputerRank[4]) {
				cout << "Computer Win! - ";
				displayResult(playerScore);
			}
			// tie
			else {
				cout << "Tie! - ";
				displayResult(playerScore);
			}
		}

		// FOUR OF A KIND
		else if (playerScore == FOUR_OF_A_KIND ) {
			// loop rank array to count how many the same ranks are in a hand
			for(int i = 0; i < NUMBER_OF_HAND; i++) {
				int numPlayer;
				int numComputer;
				numPlayer = sortedPlayerRank[i];
				numComputer = sortedComputerRank[i];
				playerCounter[numPlayer - 1] = playerCounter[numPlayer - 1] + 1;
				computerCounter[numComputer - 1] = computerCounter[numComputer - 1] + 1;
			}

			// container for the card in four kind and remaining card of player
			int fourKindPlayer = 0;
			int remainderPlayerCard = 0;

			// container for the card in four kind and remaining card of computer
			int fourKindComputer = 0;
			int remainderComputerCard = 0;

			// find out where four kind card and remaining card
			for(int i = 0; i < 13; i++) {
				if(playerCounter[i] == 4 ) {
					fourKindPlayer = i + 1;
				}
				if(playerCounter[i] == 1) {
					remainderPlayerCard = i + 1;
				}
				if(computerCounter[i] == 4) {
					fourKindComputer = i + 1;
				}
				if(computerCounter[i] == 1) {
					remainderComputerCard = i + 1;
				}
			}

			// compare four of a kind cards
			if(fourKindPlayer > fourKindComputer) {
				cout << "Player Win! - ";
				displayResult(playerScore);
			}
			else if (fourKindPlayer < fourKindComputer) {
				cout << "Computer Win! - ";
				displayResult(playerScore);
			}
			// if four of a kind cards are the same, compare remaining cards
			else {
				if(remainderPlayerCard > remainderComputerCard) {
					cout << "Player Win! - ";
					displayResult(playerScore);
				}
				else if (remainderPlayerCard < remainderComputerCard) {
					cout << "Computer Win! - ";
					displayResult(playerScore);
				}
				else {
					cout << "Tie! - ";
					displayResult(playerScore);
				}
			}
		}

		// FULL HOUSE
		else if (playerScore == FULL_HOUSE) {
			// loop rank array to count how many the same ranks are in a hand
			for(int i = 0; i < NUMBER_OF_HAND; i++) {
				int numPlayer;
				int numComputer;
				numPlayer = sortedPlayerRank[i];
				numComputer = sortedComputerRank[i];
				playerCounter[numPlayer - 1] = playerCounter[numPlayer - 1] + 1;
				computerCounter[numComputer - 1] = computerCounter[numComputer - 1] + 1;
			}

			// container for the card in three kind and remaining card of player
			int threeKindPlayer = 0;
			int remainderPlayerCard = 0;

			// container for the card in three kind and remaining card of player
			int threeKindComputer = 0;
			int remainderComputerCard = 0;

			// find out where three kind cards and remaining cards
			for(int i = 0; i < 13; i++) {
				if(playerCounter[i] == 3 ) {
					threeKindPlayer = i + 1;
				}
				if(playerCounter[i] == 2) {
					remainderPlayerCard = i + 1;
				}
				if(computerCounter[i] == 3) {
					threeKindComputer = i + 1;
				}
				if(computerCounter[i] == 2) {
					remainderComputerCard = i + 1;
				}
			}

			// compare three of a kind cards
			if(threeKindPlayer > threeKindComputer) {
				cout << "Player Win! - ";
				displayResult(playerScore);
			}
			else if (threeKindPlayer < threeKindComputer) {
				cout << "Computer Win! - ";
				displayResult(playerScore);
			}
			// if three of a kind cards are the same, compare remaining cards
			else {
				if(remainderPlayerCard > remainderComputerCard) {
					cout << "Player Win! - ";
					displayResult(playerScore);
				}
				else if (remainderPlayerCard < remainderComputerCard) {
					cout << "Computer Win! - ";
					displayResult(playerScore);
				}
				else {
					cout << "Tie! - ";
					displayResult(playerScore);
				}
			}
		}
		// FLUSH
		else if (playerScore == FLUSH) {
			// tie indicator
			bool tied = true;

			// loop through hands and compare
			for (int i = 4; i >=0; i--) {
				// if player card is higher, then player wins and assign tied to false
				if(sortedPlayerRank[i] > sortedComputerRank[i]) {
					cout << "Player Win! - ";
					displayResult(playerScore);
					tied = false;
					break;
				}
				// if computer card is higher, then computer wins and assign tied to false
				else if (sortedPlayerRank[i] < sortedComputerRank[i]) {
					cout << "Computer Win! - ";
					displayResult(playerScore);
					tied = false;
					break;
				}
				// if no one wins, then continue to loop
				else {
					continue;
				}
			}

			// if tied still true after loop, then the game is tied
			if (tied) {
				cout << "Tie! - ";
				displayResult(playerScore);
			}
		}

		// THREE OF A KIND
		else if (playerScore == THREE_OF_A_KIND) {
			// loop rank array to count how many the same ranks are in a hand
			for(int i = 0; i < NUMBER_OF_HAND; i++) {
				int numPlayer;
				int numComputer;
				numPlayer = sortedPlayerRank[i];
				numComputer = sortedComputerRank[i];
				playerCounter[numPlayer - 1] = playerCounter[numPlayer - 1] + 1;
				computerCounter[numComputer - 1] = computerCounter[numComputer - 1] + 1;
			}

			// container for the card in three kind and remaining cards of player
			int threeKindPlayer = 0;
			int remainderPlayer[2];
			int counterP = 0;

			// container for the card in three kind and remaining cards of computer
			int threeKindComputer = 0;
			int remainderComputer[2];
			int counterC = 0;

			// find out where three kind cards and remaining cards
			for(int i = 0; i < 13; i++) {
				if(playerCounter[i] == 3 ) {
					threeKindPlayer = i + 1;
				}
				if(playerCounter[i] == 1) {
					remainderPlayer[counterP] = i + 1;
					counterP++;
				}
				if(computerCounter[i] == 3) {
					threeKindComputer = i + 1;
				}
				if(computerCounter[i] == 1) {
					remainderComputer[counterC] = i + 1;
					counterC++;
				}
			}

			// sort remaining cards for easy comparison
			sort(&remainderPlayer[0], &remainderPlayer[2]);
			sort(&remainderComputer[0], &remainderComputer[2]);

			// Compare three of a kind cards
			if (threeKindPlayer > threeKindComputer) {
				cout << "Player Win! - ";
				displayResult(playerScore);
			}
			else if (threeKindPlayer < threeKindComputer) {
				cout << "Computer Win! - ";
				displayResult(playerScore);
			}
			// if three of a kind cards are the same, compare remaining cards
			else {
				if (remainderPlayer[1] > remainderComputer[1]) {
					cout << "Player Win! - ";
					displayResult(playerScore);
				}
				else if (remainderPlayer[1] < remainderComputer[1]) {
					cout << "Computer Win! - ";
					displayResult(playerScore);
				}
				// if second numbers are the same, compare remainder
				else {
					if (remainderPlayer[0] > remainderComputer[0]) {
						cout << "Player Win! - ";
						displayResult(playerScore);
					}
					else if (remainderPlayer[0] < remainderComputer[0]) {
						cout << "Computer Win! - ";
						displayResult(playerScore);
					}
					else {
						cout << "Tie! - ";
						displayResult(playerScore);
					}
				}
			}
		}

		// TWO PAIR
		else if (playerScore == TWO_PAIR) {

				// loop rank array to count how many the same ranks are in a hand
				for(int i = 0; i < NUMBER_OF_HAND; i++) {
					int numPlayer;
					int numComputer;
					numPlayer = sortedPlayerRank[i];
					numComputer = sortedComputerRank[i];
					playerCounter[numPlayer - 1] = playerCounter[numPlayer - 1] + 1;
					computerCounter[numComputer - 1] = computerCounter[numComputer - 1] + 1;
				}

				// container for the card in two pair and remaining cards of player
				int twopairPlayer[2];
				int remainderPlayer = 0;
				int counterP = 0;

				// container for the card in two pair and remaining cards of computer
				int twopairComputer[2];
				int remainderComputer = 0;
				int counterC = 0;

				// find out where two pairs are and remaining cards
				for(int i = 0; i < 13; i++) {
					if(playerCounter[i] == 2 ) {
						twopairPlayer[counterP] = i + 1;
						counterP++;
					}
					if(playerCounter[i] == 1) {
						remainderPlayer = i + 1;
					}
					if(computerCounter[i] == 2) {
						twopairComputer[counterC] = i + 1;
						counterC++;
					}
					if(computerCounter[i] == 1) {
						remainderComputer = i + 1;
					}
				}

				// sort remaining cards for easy comparison
				sort(&twopairPlayer[0], &twopairPlayer[2]);
				sort(&twopairComputer[0], &twopairComputer[2]);

				// Compare bigger numbers of each pair
				if (twopairPlayer[1] > twopairComputer[1]) {
					cout << "Player Win! - ";
					displayResult(playerScore);
				}
				else if (twopairPlayer[1] < twopairComputer[1]) {
					cout << "Computer Win! - ";
					displayResult(playerScore);
				}
				// if bigger numbers of each pair are the same, compare second pair number
				else {
					if (twopairPlayer[0] > twopairComputer[0]) {
						cout << "Player Win! - ";
						displayResult(playerScore);
					}
					else if (twopairPlayer[0] < twopairComputer[0]) {
						cout << "Computer Win! - ";
						displayResult(playerScore);
					}
					// if second pair numbers are the same, compare remainder
					else {
						if (remainderPlayer > remainderComputer) {
							cout << "Player Win! - ";
							displayResult(playerScore);
						}
						else if (remainderPlayer < remainderComputer) {
							cout << "Computer Win! - ";
							displayResult(playerScore);
						}
						else {
							cout << "Tie! - ";
							displayResult(playerScore);
						}
					}
				}
		}
		// ONE PAIR
		else if (playerScore == ONE_PAIR) {

			// loop rank array to count how many the same ranks are in a hand
			for(int i = 0; i < NUMBER_OF_HAND; i++) {
				int numPlayer;
				int numComputer;
				numPlayer = sortedPlayerRank[i];
				numComputer = sortedComputerRank[i];
				playerCounter[numPlayer - 1] = playerCounter[numPlayer - 1] + 1;
				computerCounter[numComputer - 1] = computerCounter[numComputer - 1] + 1;
			}

			// container for the card in one pair and remaining cards of player
			int onepairPlayer = 0;
			int remainderPlayer[3];
			int counterP = 0;

			// container for the card in one pair and remaining cards of computer
			int onepairComputer = 0;
			int remainderComputer[3];
			int counterC = 0;

			// find out where two pairs are and remaining cards
			for(int i = 0; i < 13; i++) {
				if(playerCounter[i] == 2 ) {
					onepairPlayer = i + 1;
				}
				if(playerCounter[i] == 1) {
					remainderPlayer[counterP] = i + 1;
					counterP++;
				}
				if(computerCounter[i] == 2) {
					onepairComputer = i + 1;
				}
				if(computerCounter[i] == 1) {
					remainderComputer[counterC] = i + 1;
					counterC++;
				}
			}

			// sort remaining cards for easy comparison
			sort(&remainderPlayer[0], &remainderPlayer[3]);
			sort(&remainderComputer[0], &remainderComputer[3]);

			// Compare bigger numbers of each pair
			if (onepairPlayer > onepairComputer) {
				cout << "Player Win! - ";
				displayResult(playerScore);
			}
			else if (onepairPlayer < onepairComputer) {
				cout << "Computer Win! - ";
				displayResult(playerScore);
			}
			// if numbers of each pair are the same, compare next pair number
			else {
				if (remainderPlayer[2] > remainderComputer[2]) {
					cout << "Player Win! - ";
					displayResult(playerScore);
				}
				else if (remainderPlayer[2] < remainderComputer[2]) {
					cout << "Computer Win! - ";
					displayResult(playerScore);
				}
				// if numbers of each pair are the same, compare next pair number
				else {
					if (remainderPlayer[1] > remainderComputer[1]) {
						cout << "Player Win! - ";
						displayResult(playerScore);
					}
					else if (remainderPlayer[1] < remainderComputer[1]) {
						cout << "Computer Win! - ";
						displayResult(playerScore);
					}
					// if numbers of each pair are the same, compare remaining numbers
					else {
						if (remainderPlayer[0] > remainderComputer[0]) {
							cout << "Player Win! - ";
							displayResult(playerScore);
						}
						else if (remainderPlayer[0] < remainderComputer[0]) {
							cout << "Computer Win! - ";
							displayResult(playerScore);
						}
						else {
							cout << "Tie! - ";
							displayResult(playerScore);
						}
					}
				}
			}
		}

		// High card
		else {

			// tie indicator
			bool tied = true;

			// loop through hands and compare
			for (int i = 4; i >=0; i--) {
				// if player card is higher, then player wins and assign tied to false
				if(sortedPlayerRank[i] > sortedComputerRank[i]) {
					cout << "Player Win! - ";
					displayResult(playerScore);
					tied = false;
					break;
				}
				// if computer card is higher, then computer wins and assign tied to false
				else if (sortedPlayerRank[i] < sortedComputerRank[i]) {
					cout << "Computer Win! - ";
					displayResult(playerScore);
					tied = false;
					break;
				}
				// if no one wins, then continue to loop
				else {
					continue;
				}
			}

			// if tied still true after loop, then the game is tied
			if (tied) {
				cout << "Tie! - ";
				displayResult(playerScore);
			}
		}
	}
}


int main() {

	Poker game;

	game.createDeck();
	game.shuffleDeck();
	game.dealCards();

	game.printPlayerHand();
	game.printComputerHand();

	game.playGame();

	return 0;
}
