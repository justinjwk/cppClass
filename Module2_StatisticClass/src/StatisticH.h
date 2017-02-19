/*
 * StatisticH.h
 *
 *  Created on: Feb 11, 2017
 *      Author: Justin
 */

#pragma once
#include <math.h>

class StatisticH
{
public:

	StatisticH() : count(0), sumX(0.0), sumXX(0.0) {

	}

	void add(double x) {
		count++;
		sumX += x;
		sumXX += x * x;
	}

	double average() const {
		if (count < 1) return 0.0;
		return sumX / count;
	}

	double STD() const {
		if (count < 2) return 0.0;
		return sqrt((sumXX - (sumX * sumX / count)) / (count - 1));
	}

	void reset() {
		count = 0;
		sumX = sumXX = 0.0;
	}

	double operator +=(double x) {
		add(x);
		return x;
	}

private:
	int count;
	double sumX;
	double sumXX;

};
