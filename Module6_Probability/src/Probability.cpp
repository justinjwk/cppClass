//============================================================================
// Name        : Probability.cpp
// Author      : Justin Kim
// Description : This class is a Probability class
//				 that implements the Probability of independent events.
//				 This class has following operators and calculates possibilities
//				 A & B is the probability of both A and B occurring,
//				 A | B is the probability of either A or B occurring,
//				 A ^ B is the probability of either A or B but not both occurring,
//				 A – B is the probability of A but not B occurring,
//				 ~ A is the probability of A not occurring.
//============================================================================

#include <iostream>
#include "Probability.h"

using namespace std;

/**
 * constructor: receive probability
 */
Probability::Probability(double probIn)
{
	setProbability(probIn);
}

/**
 * getter for probability
 * return probability
 */
double Probability::getProbability() const
{
	return probability;
}

/**
 * setter for probability
 * Error check: only accept a number between 0.0 and 1.0
 * 				or print an error message and assign default value
 */
void Probability::setProbability(double probIn)
{
	// Error check
	// If event rage is from 0.0 to 1.0, then assign it
	if(probIn >=NEVER && probIn <=CERTAIN)
	{
		probability = probIn;
	}
	// If event rage is greater than 1.0, then print an error message
	// and assign default value(1.0)
	else if(probIn > CERTAIN)
	{
		cout << "Error: Event ranges should be from 0.0(never) to 1.0(certain)!\n";
		cout << "Event is set to 1" << endl;
		probability = CERTAIN;

	}
	// If event range is less than 0.0, then print an error message
	// and assign default value(0.0)
	else
	{
		cout << "Error: Event ranges should be from 0.0(never) to 1.0(certain)!\n";
		cout << "Event is set to 0" << endl;
		probability = NEVER;
	}
}


/**
 * operator overloading for &
 * case for both A and B occurring
 * A and B = P(A) x P(B)
 */
double operator&(Probability eventA, Probability eventB)
{
	// P and B = P(A) x P(B)
	return eventA.getProbability() * eventB.getProbability();
}

/**
 * operator overloading for |
 * case for either A or B occurring
 * P or B = (P(A) + P(B)) - P(A and B)
 */
double operator|(Probability eventA, Probability eventB)
{
	// P or B = (P(A) + P(B)) - P(A and B)
	return ((eventA + eventB) - (eventA & eventB));
}

/**
 * operator overloading for ~
 * case for not A not occuring
 * ~ A = 1 - P(A)
 */
double operator~(Probability eventA)
{
	// ~ A = 1 - P(A)
	return (1 - eventA.getProbability());
}

/**
 * operator overloading for ^
 * case for either A or B, but not both occurring
 * A ^ B = P(A and ~B) + P(P and ~A)
 */
double operator^(Probability eventA, Probability eventB)
{
	// A ^ B = P(A and ~B) + P(B and ~A)
	return (eventA & (~eventB)) + (eventB & (~eventA));
}

/**
 * operator overloading for A - B
 * case for A, but not B occurring
 * A - B = P(A) - P(A and B)
 */
double operator-(Probability eventA, Probability eventB)
{
	// A - B = P(A) - P(A and B)
	return (eventA - (eventA & eventB));
}

/**
 * operator overloading for +
 * adding two objects' possibilities
 */
double operator+(Probability eventA, Probability eventB)
{
	return (eventA.getProbability() + eventB.getProbability());
}

/**
 * operator overloading for - with different parameters
 * operator-(obj, double)
 */
double operator-(Probability eventA, double eventB)
{
	return eventA.getProbability() - eventB;
}





