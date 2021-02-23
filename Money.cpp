/* Aleks McCormick
 * UAF CS 202
 * Homework3
 * Program 2: Money class
 * 02/20/2021
 */
#include <iostream>
#include <math.h>
#include "Money.hpp"

Money::Money(int d, int c): _dollars(d), _cents(c) {
	if(_dollars < 0 && _cents >= 0)
		_cents = -_cents;

	_totalCents = (_dollars * 100) + _cents;
}

Money::Money(double d):_totalCents(d*100) {
	_totalCents = round(_totalCents);
}

std::ostream &operator<<(std::ostream &os, const Money &mon) {
	os << "$" << mon._totalCents / 100;
	return os;
}
