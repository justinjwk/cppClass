//============================================================================
// Name        : Practice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "PhoneNumber.h"
using namespace std;

int main()
{
	PhoneNumber phone;

	cout << "Enter phone number in the form (123) 456-7890:" << endl;

	cin >> phone;

	cout << "The phone number entered was: ";
	cout << phone << endl;
}
