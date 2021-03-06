//===================================================================================
// Name        : TicTacToe.h
// Author      : Justin Kim
// Description : This file is a definition of class TicTacToe that
// 				 play a TicTacToe game.
//				 Member functions are defined in TicTacToe.cpp
//===================================================================================


class TicTacToe {

public:
	TicTacToe();							// constructor
	void displayWelcomeMsg();				// display a welcome message
	void addTurn();							// increase turn by 1
	int getTurn();							// return turnNum
	char getPlayer();						// return player
	void initializeGame();					// initialize the game
	void drawBoard();						// draw the board
	void userTurn();						// ask user input a cell
	void changePlayer();					// change the player
	void computerTurn();					// computer select a cell
	char whoIsWin();						// check who is a winner

private:
	char board[3][3];						// game board
	char player;							// player either 'X' or 'O'
	int turnNum;							// counter for turns
	void resetTurn();						// reset turn to 0
	void setPlayer(char playerIn);			// set player
	bool isValidNum(int numIn);				// check whether user inputs valid number
	bool isCellTaken(int row, int col);		// check whether selected cell is already taken
	void resetBoard();						// reset the board with empty char
	int generateRandomNum();				// generate a random number from 1 to 3
};
