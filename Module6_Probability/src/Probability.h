//===================================================================================
// Name        : Probability.h
// Author      : Justin Kim
// Description : This file is a definition of class Probability that
// 				 implements the Probability of independent events
//				 Member functions are defined in Probability.cpp
//===================================================================================

#ifndef PROBABILITY_H_
#define PROBABILITY_H_

#include <iostream>
#include <stdexcept>

class Probability
{
public:

	Probability(double event);				// constructor
	double getProbability() const;			// getter for probability
	void setProbability(double probIn);		// setter for probability

	static const double NEVER = 0.0;		// const value for minimum value
	static const double CERTAIN = 1.0;		// const value for maximum value

private:
	double probability;


};

double operator&(Probability eventA, Probability eventB);	// operator overloading for &
double operator|(Probability eventA, Probability eventB);	// operator overloading for |
double operator^(Probability eventA, Probability eventB);	// operator overloading for ^
double operator~(Probability eventA);						// operator overloading for ~
double operator-(Probability eventA, Probability eventB);	// operator overloading for -

double operator+(Probability eventA, Probability eventB);	// operator overloading for +
double operator-(Probability eventA, double eventB);		// operator overloading for - (obj, double)

#endif /* EVENT_H_ */
