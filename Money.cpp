/* Aleks McCormick
 * UAF CS 202
 * Homework3
 * Program 2: Money class
 * 02/20/2021
 */
#include <iostream>
#include <math.h>
#include "Money.hpp"

Money::Money(int d, int c) {
	if(d < 0 && c >= 0)
		c = -c;

	_totalCents = (round((d *100)+c))/100;
}

Money::Money(double d):_totalCents((round(d*100))/100) {

}

std::ostream &operator<<(std::ostream &os, const Money &mon) {
	if(mon._totalCents == 0)
		os << "$0.00";
	else if(mon._totalCents < 0)
		os << "-$" << (mon._totalCents * -1);
	else
		os << "$" << (mon._totalCents);
	return os;
}

bool operator==(const Money &lhs, const Money &rhs) {
	return lhs._totalCents == rhs._totalCents;
}

bool operator<(const Money &lhs, const Money &rhs) {
	return lhs._totalCents < rhs._totalCents;
}

Money operator+(const Money &lhs, const Money &rhs) {
	return (lhs._totalCents + rhs._totalCents);
}

Money operator-(const Money &lhs, const Money &rhs) {
	return (lhs._totalCents - rhs._totalCents);
}

Money &Money::operator+=(const Money &rhs) {
	return *this = *this + rhs;
}

Money &Money::operator-=(const Money &rhs) {
	return *this = *this - rhs;
}

Money &Money::operator*=(const Money &rhs) {
	return *this = (_totalCents * rhs._totalCents);
}

Money &Money::operator/=(const Money &rhs) {
	return *this = (_totalCents / rhs._totalCents);
}

bool operator!=(const Money &lhs, const Money &rhs) {
	return !(lhs == rhs);
}

bool operator>(const Money &lhs, const Money &rhs) {
	return rhs < lhs;
}

bool operator<=(const Money &lhs, const Money &rhs) {
	return !(lhs > rhs);
}

bool operator>=(const Money &lhs, const Money &rhs) {
	return !(lhs < rhs);
}

Money operator*(Money lhs, const Money &rhs) {
	return lhs *= rhs;
}

Money operator/(Money lhs, const Money &rhs) {
	return lhs /= rhs;
}
