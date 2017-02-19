//===================================================================================
// Name        : Statistic.cpp
// Author      : Justin Kim
// Description : This program receives a sequence of numbers from a user
//      		 and calculates the average and standard deviation of the sequence.
//===================================================================================

#include <iostream>
#include <cmath> // include cmatch to use sqrt
#include "Statistic.h" // include definition of class GradeBook
using namespace std;

// this method displays welcome message to user
void Statistic::displayWelcomeMsg() const {
	cout << "==========================================================\n";
	cout << "              Welcome to Statistic Program!\n";
	cout << "This program calculates an average and standard deviation\n";
	cout << "==========================================================\n" << endl;
}

// this method asks a user input
// and calculate the average and standard deviation
void Statistic::getAverageSTD() const {


	int counter = 0;					// counting for how many numbers user inputs
	double sum = 0;						// stores sum of the sequence
	double sumOfSquareNumberIn = 0;		// stores sum of square of each number
	double average = 0;					// stores average of the sequence
	double standardDeviation = 0;		// stores standard deviation of the sequence
	double numberIn = 0;				// stores user input

	const int END_OF_DATA_ENTRY = -99;	// the value for terminate the program

	// loop until user input -99
	do {

		// ask a user input numbers
		cout << "Enter a number or -99 to quit: ";
		cin >> numberIn;

		// when user is not input -99
		if (numberIn != END_OF_DATA_ENTRY) {

			// increase counter
			counter++;
			// add number to sum
			sum += numberIn;
			// add square of the number to sumOfSquareNumberIn
			sumOfSquareNumberIn += (numberIn * numberIn);
		}
	} while (numberIn != END_OF_DATA_ENTRY);	// if the user input -99, then stop the loop

	// when user input a number
	if (counter != 0) {

		// calculate the average
		average = sum / counter;

		// calculate the standard deviation
		standardDeviation = sqrt((sumOfSquareNumberIn-(sum * average))/(counter - 1));

		// display the results
		cout << "==========================================================\n";
		cout << "Average = " << average << "\n";
		cout << "Standard Deviation = " << standardDeviation;

	}
	// when user didn't input any number, print an error message
	else {
		cout << "No numbers were entered\n";
	}
}
/*
int main() {

	// create a Statistic object named data
	Statistic data;

	// call object's displayWelcomeMsg function
	data.displayWelcomeMsg();

	// call object's getAverageSTD function
	data.getAverageSTD();

}
*/
