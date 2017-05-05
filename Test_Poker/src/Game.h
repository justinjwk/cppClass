#ifndef GAME_H_
#define GAME_H_

#include <string>
#include "Card.h"
#include "DeckOfCards.h"
#include "Hand.h"
#include "Game.h"


class Game
{
private:
  DeckOfCards deck;
  Hand playersHand;
  Hand computersHand;
public:
  Game();
  void whoIsWinner();
  void dealerTurn(); //in dealer.cc
  void playerTurn(); //in player.cc
};

#endif
