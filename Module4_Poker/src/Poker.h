//===================================================================================
// Name        : Poker.h
// Author      : Justin Kim
// Description : This file is a definition of class Poker that
// 				 play a Poker game.
//				 Member functions are defined in Poker.cpp
//===================================================================================

class Poker {

public:
	Poker();

	// constant for card numbers
	static const int NUMBER_OF_CARDS = 52;
	static const int NUMBER_OF_RANK = 13;
	static const int NUMBER_OF_SUIT = 4;
	static const int NUMBER_OF_HAND = 5;

	// hand-ranks
	static 	const int STRAIGHT_FLUSH = 9;
	static const int FOUR_OF_A_KIND = 8;
	static const int FULL_HOUSE = 7;
	static const int FLUSH = 6;
	static const int STRAIGHT = 5;
	static const int THREE_OF_A_KIND = 4;
	static const int TWO_PAIR = 3;
	static const int ONE_PAIR = 2;
	static const int HIGH_CARD = 1;

	int deck[NUMBER_OF_CARDS];

	std::string rank[NUMBER_OF_RANK] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	std::string suit[NUMBER_OF_SUIT] = {"S", "H", "D", "C"};

	// player's hand
	std::string playerRank[NUMBER_OF_HAND];
	std::string playerSuit[NUMBER_OF_HAND];
	int sortedPlayerRank[NUMBER_OF_HAND];

	// computer's hand
	std::string computerRank[NUMBER_OF_HAND];
	std::string computerSuit[NUMBER_OF_HAND];
	int sortedComputerRank[NUMBER_OF_HAND];

	void createDeck();
	void shuffleDeck();
	void printDeck();
	void dealCards();
	void printPlayerHand();
	void printComputerHand();
	int flush(std::string suitIn[NUMBER_OF_HAND]);
	int straight(int rankIn[NUMBER_OF_HAND]);
	int straightFlush(int rankIn[NUMBER_OF_HAND], std::string suitIn[NUMBER_OF_HAND]);
	int pairCounter(int rankIn[NUMBER_OF_HAND]);
	int getTypeOfHand(int rankIn[5], std::string suitIn[5]);
	void displayResult(int rankScore);
	void playGame();

private:
	void convertPlayerArrayToSortedIntArray(std::string rankIn[5]);		// helper method
	void convertComputerArrayToSortedIntArray(std::string rankIn[5]);	// helper method
};
