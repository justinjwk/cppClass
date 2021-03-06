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
  DeckOfCards game_deck;
  Hand players_hand;
  Hand computers_hand;
public:
  Game();
  void determine_winner();
  void simulateTurn(); //in dealer.cc
  void performTurn(); //in player.cc
};

#endif
