/*
 * PhoneNumber.h
 *
 *  Created on: Mar 11, 2017
 *      Author: Justin
 */

#ifndef PHONENUMBER_H_
#define PHONENUMBER_H_

#include <iostream>
#include <string>

class PhoneNumber
{
	friend std::ostream &operator<<(std::ostream &, const PhoneNumber &);
	friend std::istream &operator>>(std::istream &, PhoneNumber &);

private:
	std::string areaCode;
	std::string exchange;
	std::string line;
};



#endif /* PHONENUMBER_H_ */
