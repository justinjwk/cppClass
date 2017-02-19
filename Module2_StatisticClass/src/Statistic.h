//===================================================================================
// Name        : Statistic.h
// Author      : Justin Kim
// Description : This file is a definition of class Statistic that
// 				 receives a sequence of numbers from a user and calculates
//				 the average and standard deviation of the sequence.
//				 Member functions are defined in Statistic.cpp
//===================================================================================

class Statistic {
public:
	void displayWelcomeMsg() const; // display a welcome message
	void getAverageSTD() const;  	// calculate the average and standard deviation

private:
	int counter;					// counting for how many numbers user inputs
	double sum;						// stores sum of the sequence
	double sumOfSquareNumberIn;		// stores sum of square of each number
	double average;					// stores average of the sequence
	double standardDeviation;		// stores standard deviation of the sequence
	double numberIn;				// stores user input
};
