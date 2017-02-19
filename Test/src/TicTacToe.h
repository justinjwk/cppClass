/*
 * TicTackToe.h
 *
 *  Created on: Feb 12, 2017
 *      Author: Justin
 */

class TicTacToe
{
public:
	explicit TicTacTo();


private:
	unsigned char board[3][3];
	unsigned char player;
	unsigned int turnNum;
};
