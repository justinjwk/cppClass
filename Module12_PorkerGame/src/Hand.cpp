#include "Hand.h"


Hand::Hand() {

}

Hand::Hand(Deck d, PLAYER_TYPE p) {

	//	Card ca = Card("A","H");
	//	Card cb = Card("10", "H");
	//	Card cc = Card("K", "H");
	//	Card cd = Card("Q", "H");
	//	Card ce = Card("J", "H");
	//	Card temp[5];
	//	temp[0] = ca;
	//	temp[1] = cb;
	//	temp[2] = cc;
	//	temp[3] = cd;
	//	temp[4] = ce;

	Card temp[5];

	for(int i = 0; i < 5; i++) {
		temp[i] = d.dealCard();
	}

	for (int i = 0; i < 5; i++) {
		temp[i] = d.dealCard();
	}

	//findACEwithKing(temp);
	sortCards(temp);




	for(int i = 0; i < 5; i++) {
		hand.push_back(temp[i]);
	}

	playerType = p;
	handValue = unchecked;
}

Hand::Hand(PLAYER_TYPE p) {
	playerType = p;
	handValue = unchecked;
	highPair = 0;
	lowPair = 0;
}

Hand::~Hand() {

}

void Hand::sortCards(Card cardHand[5]) {

	Card temp;

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4 - i; j++) {
			if(cardHand[j].getRankValue() > cardHand[j+1].getRankValue()) {
				temp = cardHand[j];
				cardHand[j] = cardHand[j+1];
				cardHand[j+1] = temp;
			}
		}
	}
}

/**
 * When there is a King and Ace in the hand,
 * then set value of Ace to 14
 */
void Hand::findACEwithKing(Card cardHand[5]) {

	bool foundAce = false;
	bool foundKing = false;
	int indexOfAce = 0;

	// loop through hands
	for(int i = 0; i < 5; i++) {
		// find King
		if(cardHand[i].getRankValue() == 13) {
			foundKing = true;
		}
		// find Ace
		if(cardHand[i].getRankValue() == 1) {
			foundAce = true;
			indexOfAce = i;
		}
	}

	// if there is a King and Ace in the hand
	// assign its value to 14
	if(foundAce && foundKing) {
		cardHand[indexOfAce].setRankValue(14);
	}


}

vector<int> Hand::getHighest() {
	return highList;
}

int Hand::getHighPair() {
	return highPair;
}

int Hand::getLowPair() {
	return lowPair;
}

HAND_VALUE Hand::getHandValue() {
	return handValue;
}

void Hand::printHand(string str) {
	if(playerType == player) {
		cout << "Player";
	}
	else {
		cout << "Computer";
	}

	cout << "'s " << str << " Hand:\n";

	for(int i = 0; i < 5; i++) {
		cout << hand[i].printCard() << " ";
	}
	cout << endl;
}

void Hand::setHand( Card cardHand[5] )
{
	sortCards(cardHand);
	for (int i = 0; i < 5; i++)
		hand.push_back( cardHand[i] );
	setTypeOfHand();
}

/*
 * This method finds out flush cards
 */
int Hand::isFlush() {

	// if every card's suit is the same, then it's flush
	if ( (hand[0].getSuit().compare(hand[1].getSuit()) == 0)
			&& (hand[1].getSuit().compare(hand[2].getSuit()) == 0)
			&& (hand[2].getSuit().compare(hand[3].getSuit()) == 0)
			&& (hand[3].getSuit().compare(hand[4].getSuit()) == 0)) {
		return FLUSH;
	}
	else {
		return 0;
	}
}

/*
 * This method finds straight card
 */
int Hand::isStraight() {

	bool straight = true;

	// find out whether two neighbor numbers are continuous number
	// if two neigher number is not continous number, then assign isStraint to false
	for (int i = 0; i < 4; i++) {
		if (hand[i+1].getRankValue() - hand[i].getRankValue() != 1) {
			straight = false;
			break;
		}
	}

	// return STRAIGHT if it is straight card
	if(straight) {
		return STRAIGHT;
	}
	else {
		return 0;
	}
}

/**
 * This method finds Straight Flush cards
 */
int Hand::isStraightFlush() {

	// If both Flush and Straight are true, then it's Straight Flush
	if(isFlush() == FLUSH && isStraight() == STRAIGHT) {
		return STRAIGHT_FLUSH;
	}
	else {
		return 0;
	}
}

void Hand::findHighCard()
{
	//error checking
	if ( handValue == 0 )
	{
		cout << "Hand value is not checked yet" << endl;
		return;
	}

	//straight and flushes
	else if ( handValue == 5 || handValue == 6 )
	{
		//checks for straight with Ace as low card
		if ( handValue == 5 && hand[4].getRankValue() == 14 )
			highList.push_back( hand[3].getRankValue());
		else
			highList.push_back( hand[4].getRankValue());
	}
	//pair, two pair, three of a kind, four of a kind
	else if ( handValue < 5 || handValue == 7 )
	{
		for ( int i=0; i<5; i++ )
		{
			//pushes non-used card into the vector first
			if ( hand[i].getRankValue() != highPair && hand[i].getRankValue() != lowPair )
				highList.push_back( hand[i].getRankValue() );
		}
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
int Hand::pairCounter() {

	// to see how many pairs are in hand and where they are
	int counter[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	// loop card hand to count how many the same ranks are in a hand
	for(int i = 0; i < 4; i++) {

		int num;

		num = hand[i].getRankValue();
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
			highPair = i + 1;
		}
		// if there are 3 same cards
		if (counter[i] == 3) {
			threeOfKind += 1;
			highPair = i + 1;
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

bool Hand::isOnePair() {
	for (int i = 0; i < 5; i++) {
		for (int j=0; j<5; j++ ) {
			if (i != j ) {
				if (hand[i].getRankValue() == hand[j].getRankValue()) {
					highPair = hand[i].getRankValue();
					return true;
				}
			}
		}
	}
	return false;
}

bool Hand::isTwoPair() {
	Card firstCard;
	Card secondCard; //stores first pair (obviously two cards)

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if ( i != j ) {
				if ( hand[i].getRankValue() == hand[j].getRankValue()) {
					firstCard = hand[i];
					secondCard = hand[j];
				}
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i != j) {
				if ( hand[i].getRankValue() == hand[j].getRankValue() ) {
					if ( hand[i] != firstCard && hand[j] != firstCard &&
							hand[i] != secondCard && hand[j] != secondCard ) {
						if ( hand[i].getRankValue() > firstCard.getRankValue() ) {
							highPair = hand[i].getRankValue();
							lowPair = firstCard.getRankValue();
						}
						else {
							highPair = firstCard.getRankValue();
							lowPair = hand[i].getRankValue();
						}
						return true;
					}
				}
			}
		}
	}
	return false;
}

/*
 * This methods returns what combination the hand is
 */
void Hand::setTypeOfHand() {

	// return scores based on their combination
	// 0 - high, 9 - low
	if(isStraightFlush() == STRAIGHT_FLUSH) {
		handValue = straightFlush;
	}
	else if(pairCounter() == FOUR_OF_A_KIND) {
		handValue = fourOfKind;
	}
	else if(pairCounter() == FULL_HOUSE) {
		handValue = fullHouse;
	}
	else if(isFlush() == FLUSH){
		handValue = flushCard;
	}
	else if(isStraight() == STRAIGHT) {
		handValue = straight;
	}
	else if(pairCounter() == THREE_OF_A_KIND) {
		handValue = threeOfKind;
	}
	else if(pairCounter() == TWO_PAIR) {
		handValue = twoPair;
	}
	else if(pairCounter() == ONE_PAIR) {
		handValue = onePair;
	}
	else {
		handValue = highCard;
	}

}


/**
 * This method prints what kind of card winner has
 */
void Hand::displayResult(int rankScore) {

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

int Hand::inputValidation( bool zero ) {
	int n;
	bool pass =  false;

	while ( pass == false ) {

		cin >> n;

		if ( zero == true ) {
			if ( n > -1 && n < 4 ) { //include zero
				pass = true;
			}
			else {
				cout << "Invalid Entry" << endl;
			}
		}
		if ( zero == false ) {
			if ( n > 0 && n < 6 ) { //exclude zero
				pass = true;
			}
			else {
				cout << "Invalid Entry" << endl;
			}
		}
	}

	return n;
}

void Hand::playersTurn(Deck &deck) {

	int n;
	int position[3] = { -1, -1, -1 };
	Card temp[5];

	cout << "\nHow many cards you would to trade?  ";

	n = inputValidation(true);

	cout << "Please enter card position (left end is 1, right end is 5):  ";

	for (int i = 0; i < n; i++ ) {
		position[i] = inputValidation(false) - 1;
	}
	for (int j = 0; j < 5; j++) {
		//check for position
		if ( (position[0] != -1 && position[0] == j) ||
				(position[1] != -1 && position[1] == j) ||
				(position[2] != -1 && position[2] == j) ) {
			temp[j] = deck.dealCard();
		}
		else
			temp[j] = hand[j];
	}

	hand.clear();
	sortCards(temp);
	setHand(temp);
}

void Hand::tradeCard( Deck &deck, int n ) {
	Card temp[5];

	for (int i = 0; i < 5; i++) {
		//draws the new card to replace the old one
		if ( hand[i].getRankValue() == n ) {
			temp[i] = deck.dealCard();
		}
		else {
			temp[i] = hand[i];
		}
	}
	sortCards( temp );
	hand.clear();
	setHand( temp );
}

