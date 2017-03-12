//============================================================================
// Name        : Module6_main.cpp
// Author      : Justin Kim
// Description : This is main class that is test driver runs Probability
//				 Error checking in case input is not valid
//				 Test cases with different possibilities
//============================================================================

#include <iostream>
#include "Probability.h"
using namespace std;

int main() {

	double result = 0;

	// Error checking : input value is greater than 1
	cout << "**** Error check: when input is greater than 1 ****" << endl;
	Probability errorCheckA(1.5);
	cout << endl;

	// Error checking : input value is less than 0
	cout << "**** Error check: when input is less than 0 ****" << endl;
	Probability errorCehckB(-1.5);
	cout << endl;

	// Test case1 : A = 0.6, B = 0.9
	cout << "**** Test1 ****" << endl;
	Probability eventA(0.6);
	Probability eventB(0.9);

	// Display each possibilities
	cout << "A = " << eventA.getProbability() << " / B = " << eventB.getProbability() << endl;

	// Operator &
	result = eventA & eventB;
	cout << "A & B = " << result << endl;

	// Operator |
	result = eventA | eventB;
	cout << "A | B = " << result << endl;

	// Operator ^
	result = eventA ^ eventB;
	cout << "A ^ B = " << result << endl;

	// Operator -
	result = eventA - eventB;
	cout << "A - B = " << result << endl;

	// Operator ~
	result = ~eventA;
	cout << "~ A = " << result << endl;

	cout << endl;

	// Test case2 : C = 0.8, D = 0.2
	cout << "**** Test2 ****" << endl;
	Probability eventC(0.8);
	Probability eventD(0.2);

	// Display each possibilities
	cout << "C = " << eventC.getProbability() << " / D = " << eventD.getProbability() << endl;

	// Operator &
	result = eventC & eventD;
	cout << "C & D = " << result << endl;

	// Operator |
	result = eventC | eventD;
	cout << "C | D = " << result << endl;

	// Operator ^
	result = eventC ^ eventD;
	cout << "C ^ D = " << result << endl;

	// Operator -
	result = eventC - eventD;
	cout << "C - D = " << result << endl;

	// Operator ~
	result = ~eventC;
	cout << "~ C = " << result << endl;

	cout << endl;


	// Test case3 : e = 1, F = 1
	cout << "**** Test3 ****" << endl;
	Probability eventE(1);
	Probability eventF(1);

	// Display each possibilities
	cout << "E = " << eventE.getProbability() << " / F = " << eventF.getProbability() << endl;

	// Operator &
	result = eventE & eventF;
	cout << "E & F = " << result << endl;

	// Operator |
	result = eventE | eventF;
	cout << "E | F = " << result << endl;

	// Operator ^
	result = eventE ^ eventF;
	cout << "E ^ F = " << result << endl;

	// Operator -
	result = eventE - eventF;
	cout << "E - F = " << result << endl;

	// Operator ~
	result = ~eventE;
	cout << "~ E = " << result << endl;

	cout << endl;

}
