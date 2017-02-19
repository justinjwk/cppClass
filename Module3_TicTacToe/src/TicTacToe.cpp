//============================================================================
// Name        : Module3_TicTacToe.cpp
// Author      : Justin Kim
// Description : This program is a TicTacToe game
// 				 The user always plays first as ¡°X¡± and selects the location
//               by the row and col and the computer plays by placing an ¡°O¡±
//               in a cell. Player will win the game if they have 3 matches
//               in vertically, horizontally, or diagonally.
//               If the board is filled without a winner, then it's tie.
//============================================================================

#include <iostream>
#include <stdlib.h>
#include "TicTacToe.h"
using namespace std;

/**
 * Constructor
 * Assign a player 'X', turnNum to 0
 * Initialize a game and display a welcome message
 */
TicTacToe::TicTacToe() : player('X'), turnNum(0) {
	initializeGame();
	displayWelcomeMsg();
}

/**
 * This method displays a welcome message
 */
void TicTacToe::displayWelcomeMsg() {
	cout << "===============================================\n";
	cout << "         Welcome to Tic Tac Toe Game! \n";
	cout << " Please, enter row/column numbers for your move \n";
	cout << "===============================================\n";

}

/**
 * This method resets the turnNum to 0
 */
void TicTacToe::resetTurn() {
	turnNum = 0;
}

/**
 * This method increases turnNum by 1
 */
void TicTacToe::addTurn() {
	turnNum++;
}

/**
 * This method returns turnNum
 */
int TicTacToe::getTurn() {
	return turnNum;
}

/**
 * This method returns player
 */
char TicTacToe::getPlayer() {
	return player;
}

/**
 * This method sets player
 */
void TicTacToe::setPlayer(char playerIn) {
	player = playerIn;
}

/**
 * This method reset the board with empty string
 */
void TicTacToe::resetBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}

/**
 * This method initialize the game by resetting turn and board
 * and reset turn to 0
 */
void TicTacToe::initializeGame() {
	resetTurn();
	resetBoard();
}

/**
 * This method display the board
 */
void TicTacToe::drawBoard() {

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

/**
 * Error Checking
 * This method checks user input.
 * If user inputs number between 1 and 3, then return true.
 * If user inputs number less than 1 or greater than 3, then print an error message and return false.
 */
bool TicTacToe::isValidNum(int numIn) {
	if (numIn < 1 || numIn > 3) {
		cout << "Error: You can only input between 1 and 3!\n";
		return false;
	}
	else {
		return true;
	}
}

/**
 *  Error Checking
 *  This method checks a user selection of the location is already taken.
 *  If the location is already taken, then return true.
 *  If the location is available, then return false.
 */
bool TicTacToe::isCellTaken(int row, int col) {
	// if the cell is empty, then the cell is not taken yet
	if (board[row - 1][col - 1] == ' ') {
		return false;
	}
	else {
		return true;
	}
}

/**
 * This method ask user to select row and column
 * and assign symbol to the location
 */
void TicTacToe::userTurn() {

	int row = 0;
	int col = 0;

	do {
		do {
			//ask a user to input row number
			cout << "Please input row number: ";
			cin >> row;
		} while (!isValidNum(row)); // loop until user inputs valid row number

		do {
			// ask a user to input column number
			cout << "Please input column number: ";
			cin >> col;
		} while (!isValidNum(col)); // loop until user inputs valid column number

		// when user inputs already taken cell, then display an error message
		if(isCellTaken(row, col)) {
			cout << "The cell you selected is taken. Please select different cell!\n";
		}

	} while(isCellTaken(row, col)); // loop until user select not taken cell

	// assign a user symbol(X) to the board
	board[row - 1][col - 1] = player;
}

/**
 * This method change player alternatively
 */
void TicTacToe::changePlayer() {

	// if current player is a user, then change player to a computer
	if(getPlayer() == 'X') {
		setPlayer('O');
	}

	// if current player is a computer, then change player to a user
	else {
		setPlayer('X');
	}
}

/**
 * This method generates a random number from 0 to 2
 */
int TicTacToe::generateRandomNum() {
	return rand() % 3;
}

/**
 * This method is for the computer to select cells  using random selection
 */
void TicTacToe::computerTurn() {

	int row = 0;
	int col = 0;

	do {
		// row selection by calling generateRandomNum() function
		row = generateRandomNum() + 1;
		// column selection by calling generateRandomNum() function
		col = generateRandomNum() + 1;
	} while (isCellTaken(row, col)); // loop until computer select not taken cell

	// assign a computer symbol(O) to the board
	board[row - 1][col - 1] = player;
}

/**
 * This method finds who is winner by compare each cells
 * If user wins, then return 'X'
 * If computer wins, then return 'O'
 * If no one wins yet, then return 'T'
 */
char TicTacToe::whoIsWin() {

	// First row comparison
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
	// Second row comparison
	if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
		if(board[1][0] != ' ') {
			if (board[1][0] == 'X') {
				return 'X';
			}
			else {
				return 'O';
			}
		}
	}
	// Third row comparison
	if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
		if(board[2][0] != ' ') {
			if (board[2][0] == 'X') {
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
			if (board[0][1] == 'X') {
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
			if (board[0][2] == 'X') {
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
			if (board[0][2] == 'X') {
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

	// create TicTacToe object named game
	TicTacToe game;

	do {
		// draw a board by calling drowBoard();
		game.drawBoard();

		// if the number of turn less than 9, then user keeps playing a game
		if (game.getTurn()< 9) {
			// increase turn
			game.addTurn();
			// user selects a cell
			game.userTurn();
			// if user wins
			if (game.whoIsWin() == 'X') {
				// draw the board and print a winning message
				game.drawBoard();
				cout << "=== You are a winner! ===\n";
				// then ends the game
				break;
			}

			// change a player by calling changePlayer();
			game.changePlayer();
		}

		// if the number of turn less than 9, then computer keeps playing a game
		if (game.getTurn() < 9) {
			// increase turn
			game.addTurn();
			// computer selects a cell
			game.computerTurn();
			// if computer wins
			if (game.whoIsWin() == 'O') {
				// draw the board and print a winning message
				game.drawBoard();
				cout << "=== Computer is a winner! ===\n";
				// then ends the game
				break;
			}

			// change a player by calling changePlayer();
			game.changePlayer();
		}

	} while(game.getTurn() < 9); // loop until turn number is less than 9

	// if the game is tied, then print a tie message
	if (game.whoIsWin() == 'T') {
		// draw the board and print a tie message
		game.drawBoard();
		cout << "===== Tie! =====" << endl;
	}
}
