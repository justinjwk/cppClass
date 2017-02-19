/*
 * TicTacToe.h
 *
 *  Created on: Feb 12, 2017
 *      Author: Justin
 */

#pragma once
#include<iostream>
#include<stdlib.h>

class TicTacToe {
public:

	TicTacToe() : player('X'), turn(0) {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				board[i][j] = ' ';
			}
		}

	}

	/*
	 * This method displays a welcome message
	 */
	void displayWelcomeMsg() const;

	/*
	 * This method initialize/reset the board with empty character
	 * and reset turn to 0
	 */
	void initializeBoard() const {
		turn = 0;
		for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					board[i][j] = ' ';
				}
			}
	}

	/*
	 * This method display the board
	 */
	void drawBoard() const;

	/*
	 *  This method checks a user selection of the location is already taken
	 *  If the location is already taken, then return true.
	 *  If the location is available, then return false;
	 */
	bool cellIsTaken(int raw, int col) {
		if (board[raw - 1][col - 1] == ' ') {
			return false;
		}
		else {
			return true;
		}
	}




private:
	char board[3][3];
	char player = 'X';
	int turn = 0;
};
