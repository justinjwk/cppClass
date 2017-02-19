//============================================================================
// Name        : Module1_TriangleTest.cpp
// Author      : Justin Kim
// Version     :
// Copyright   : Your copyright notice
// Description : This program read three integers from a user and print
//				 a message whether it is equilateral, isosceles, or scalene.
//============================================================================

#include <iostream>

int main() {

	int number1 = 0;
	int number2 = 0;
	int number3 = 0;

	// print a greeting message
	std::cout << "=====================================================================\n";
	std::cout << " Welcome to Triangle Test!\n";
	std::cout << " This program reads three integers lengths of the sides of a trangle\n";
	std::cout << " and it let you know what kind of triangle it is.\n";
	std::cout << "=====================================================================\n";

	// for number 1 input
	do {
		// ask user to input a number
		std::cout << "Please enter first number: ";
		std::cin >> number1;

		// error check.
		// if user inputs a number 0 or negative number, show an error message
		if (number1 <= 0) {
			std::cout << "Number should be bigger than 0!\n";
		}
	} while (number1 <= 0); // loop until user inputs correct value

	// for number 2 input
	do {
		// ask user to input a number
		std::cout << "Please enter second number: ";
		std::cin >> number2;

		// error check.
		// if user inputs a number 0 or negative number, show an error message
		if (number2 <= 0) {
			std::cout << "Number should be bigger than 0!\n";
		}
	} while (number2 <= 0); // loop until user inputs correct value

	// for number 3 input
	do {
		// ask user to input a number
		std::cout << "Please enter third number: ";
		std::cin >> number3;

		// error check.
		// if user inputs a number 0 or negative number, show an error message
		if (number3 <= 0) {
			std::cout << "Number should be bigger than 0!\n";
		}
	} while (number3 <= 0); // loop until user inputs correct value

	// if the three numbers are the same length, then print it is equilateral.
	if (number1 == number2 && number2 == number3)
		std::cout << "The triangle is equilateral!";
	// if the two numbers are the same length, then print it is isosceles.
	else if (number1 == number2 || number2 == number3 || number3 == number1)
		std::cout << "The triangle is isosceles!";
	// if no numbers are the same length, then print it is scalene.
	else
		std::cout << "The triangle is scalene!";

	return 0;
}
