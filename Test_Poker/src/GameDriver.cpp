#include <stdlib.h> //srand()
#include <time.h>
#include "Game.h"
#include "Hand.h"
#include "Card.h"

int main() {
  srand(time(NULL));
  Game b;
  b.playerTurn();
  b.dealerTurn();
  b.whoIsWinner();

  return 0;
}
