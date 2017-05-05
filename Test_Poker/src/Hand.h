#ifndef HAND_H_
#define HAND_H_

#include <string>
#include "Card.h"
#include "DeckOfCards.h"

using namespace std;

enum PLAYER_TYPE { player, computer };
enum HAND_VALUE { unchecked, high_card, one_pair, two_pair,
  	  three_kind, a_straight, a_flush, four_kind };

class Hand
{
private:
  vector<Card> hand;
  PLAYER_TYPE playerType;
  HAND_VALUE handValue;
  //additional functionality used by game.cc
  vector<int> highList;
  int highPair;
  int lowPair;
public:
  Hand();
  Hand( DeckOfCards a, PLAYER_TYPE o );
  Hand( DeckOfCards a );
  Hand( string test_hand ); //for testing in test_hand.cc
  Hand( PLAYER_TYPE o ); //in game.cc
  HAND_VALUE getHandValue();
  vector<int> getHighest();
  int getHighPair();
  int getLowPair();
  void setHand( Card arr[5] ); //in game.cc
  void printHand( string s );
  void findHighCard(); //in hand.cc for game.cc
  void setTypeOfHand();
  bool isOnePair();
  bool isTwoPair();
  bool three_kind_check();
  bool four_kind_check();
  bool flush_check();
  bool straight_check();
  void tradeCard( DeckOfCards &, int ); //in dealer.cc
  void playersTurn( DeckOfCards & ); //in player.cc
};

#endif
