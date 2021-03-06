//============================================================================
// Name        : Module3_TicTacToe.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include "TicTacToe.h"
using namespace std;



TicTacToe::TicTacToe(): player('X'), turnNum(0)
{

}

/*
 * This method displays a welcome message
 */
void displayWelcomeMsg() {
	cout << "===============================================\n";
	cout << "         Welcome to Tic Tac Toe Game! \n";
	cout << " Please, enter raw/column numbers for your move \n";
	cout << "===============================================\n";

}

/*
 * This method resets the turnNum to 0
 */
void TicTacToe::resetTurn() {
	turnNum = 0;
}

/*
 * This method increases turnNum by 1
 */
void TicTacToe::addTurn() {
	turnNum++;
}

/*
 * This method returns turnNum
 */
int getTurn() {
	return turnNum;
}

/*
 * This method returns player
 */
char getPlayer() {
	return player;
}

/*
 * This method sets player
 */
void setPlayer(char playerIn) {
	player = playerIn;
}

/*
 * This method reset the board with empty string
 */
void resetBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}

/*
 * This method initialize the game by resetting turn and board
 * and reset turn to 0
 */
void initializeGame() {
	resetTurn();
	resetBoard();
}

/*
 * This method display the board
 */
void drawBoard() {

	// display column head
	cout << "                  1   2   3 \n";

	// loop through the board
	for (int i = 0; i < 3; i++) {

		cout << "                 -----------\n";
		// display row head
		cout << "              " << i + 1 << " | ";

		// display cells
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << " | ";
		}
		cout << endl;
	}
	cout << "                 -----------\n";
}

/*
 * Error Checking
 * This method checks user input.
 * If user inputs number between 1 and 3, then return true.
 * If user inputs number less than 1 or greater than 3, then print an error message and return false.
 */
bool isValidNum(int numIn) {
	if (numIn < 1 || numIn > 3) {
		cout << "Error: You can only input between 1 and 3!\n";
		return false;
	}
	else {
		return true;
	}
}

/*
 *  Error Checking
 *  This method checks a user selection of the location is already taken.
 *  If the location is already taken, then return true.
 *  If the location is available, then return false.
 */
bool isCellTaken(int raw, int col) {
	// if the cell is empty, then the cell is not taken yet
	if (board[raw - 1][col - 1] == ' ') {
		return false;
	}
	else {
		return true;
	}
}

/*
 * This method ask user to select raw and column
 * and assign symbol to the location
 */
void userTurn() {

	int row = 0;
	int col = 0;

	do {
		do {
			//ask a user to input raw number
			cout << "Please input raw number: ";
			cin >> row;
		} while (!isValidNum(row)); // loop until user inputs valid row number

		do {
			// ask a user to input column number
			cout << "Please input column number: ";
			cin >> col;
		} while (!isValidNum(row)); // loop until user inputs valid column number

		// when user inputs already taken cell, then display an error message
		if(isCellTaken(row, col)) {
			cout << "The cell you selected is taken. Please select different cell!\n";
		}

	} while(isCellTaken(row, col)); // loop until user select not taken cell

	// assign a user symbol(X) to the board
	board[row - 1][col - 1] = player;
}

/*
 * This method change player alternatively
 */
void changePlayer() {

	// if current player is a user, then change player to a computer
	if(getPlayer() == 'X') {
		setPlayer('O');
	}

	// if current player is a computer, then change player to a user
	else {
		setPlayer('X');
	}
}

/*
 * This method generates a random number from 0 to 2
 */
int generateRandomNum() {
	return rand() % 3;
}

/*
 * This method is for the computer to select cells  using random selection
 */
void computerTurn() {

	int raw = 0;
	int col = 0;

	do {
		// raw selection by calling generateRandomNum() function
		raw = generateRandomNum() + 1;
		// column selection by calling generateRandomNum() function
		col = generateRandomNum() + 1;
	} while (isCellTaken(raw, col)); // loop until computer select not taken cell

	// assign a computer symbol(O) to the board
	board[raw - 1][col - 1] = player;
}

/*
 * This method finds who is winner by compare each cells
 * If user wins, then return 'X'
 * If computer wins, then return 'O'
 * If no one wins yet, then return 'T'
 */
char whoIsWin() {

	// First raw comparison
	// If the first rows are equal
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
		// If the first cell is not empty cell, then check who is the cell
		if(board[0][0] != ' ') {
			// If the player in the cell, then return 'X'
			if (board[0][0] == 'X') {
				return 'X';
			}
			// If the computer in the cell, then return 'O'
			else {
				return 'O';
			}
		}
	}
	// Second raw comparison
	if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
		if(board[1][0] != ' ') {
			if (board[0][0] == 'X') {
				return 'X';
			}
			else {
				return 'O';
			}
		}
	}
	// Third raw comparison
	if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
		if(board[2][0] != ' ') {
			if (board[0][0] == 'X') {
				return 'X';
			}
			else {
				return 'O';
			}
		}
	}
	// First column comparison
	if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
		if(board[0][0] != ' ') {
			if (board[0][0] == 'X') {
				return 'X';
			}
			else {
				return 'O';
			}
		}
	}
	// Second column comparison
	if (board[0][1] == board[1][1] && board[1][1] == board[2][1]) {
		if(board[0][1] != ' ') {
			if (board[0][0] == 'X') {
				return 'X';
			}
			else {
				return 'O';
			}
		}
	}
	// Third column comparison
	if (board[0][2] == board[1][2] && board[1][2] == board[2][2]) {
		if(board[0][2] != ' ') {
			if (board[0][0] == 'X') {
				return 'X';
			}
			else {
				return 'O';
			}
		}
	}
	// Left-top diagonal comparison
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		if(board[0][0] != ' ') {
			if (board[0][0] == 'X') {
				return 'X';
			}
			else {
				return 'O';
			}
		}
	}
	// Right-top diagonal comparison
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		if(board[0][2] != ' ') {
			if (board[0][0] == 'X') {
				return 'X';
			}
			else {
				return 'O';
			}
		}
	}
	// nothing is matched(no one is win yet), then return 'T' (Tied)
	return 'T';
}

int main() {

	// initialized board by calling initializeBoard();
	initializeGame();

	displayWelcomeMsg();

	do {
		// draw a board by calling drawBoard();
		drawBoard();

		// if the number of turn less than 9, then user keeps playing a game
		if (turnNum < 9) {
			// increase turn
			addTurn();
			// user selects a cell
			userTurn();
			// if user wins
			if (whoIsWin() == 'X') {
				// draw the board and print a winning message
				drawBoard();
				cout << "=== You are a winner! ===\n";
				// then ends the game
				break;
			}

			// change a player by calling changePlayer();
			changePlayer();
		}

		// if the number of turn less than 9, then computer keeps playing a game
		if (turnNum < 9) {
			// increase turn
			addTurn();
			// computer selects a cell
			computerTurn();
			// if computer wins
			if (whoIsWin() == 'O') {
				// draw the board and print a winning message
				drawBoard();
				cout << "=== Computer is a winner! ===\n";
				// then ends the game
				break;
			}

			// change a player by calling changePlayer();
			changePlayer();
		}

	} while(turnNum < 9); // loop until turn number is less than 9

	// if the game is tied, then print a tie message
	if (whoIsWin() == 'T') {
		// draw the board and print a tie message
		drawBoard();
		cout << "===== Tie! =====" << endl;
	}
}
