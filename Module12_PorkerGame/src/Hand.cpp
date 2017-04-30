#include "Hand.h"

Hand::Hand() {

}

Hand::Hand(Deck d, PLAYER_TYPE p) {

	Card temp[5];

	for(int i = 0; i < 5; i++) {
		temp[i] = d.dealCard();
	}

	sortCards(temp);

	for(int i = 0; i < 5; i++) {
		hand.push_back(temp[i]);
	}

	playerType = p;
	handValue = unchecked;
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
		cout << "\nPlayer";
	}
	else {
		cout << "\nComputer";
	}

	cout << "'s " << str << " Hand:\n";

	for(int i = 0; i < 5; i++) {
		cout << hand[i].printCard() << endl;
	}
}
