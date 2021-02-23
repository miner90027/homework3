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

Money::Money(double d):_totalCents(round(d*100)) {

}

std::ostream &operator<<(std::ostream &os, const Money &mon) {
	os << "$" << (mon._totalCents / 100);
	return os;
}

bool operator==(const Money &lhs, const Money &rhs) {
	return lhs._totalCents == rhs._totalCents;
}

bool operator<(const Money &lhs, const Money &rhs) {
	return lhs._totalCents < rhs._totalCents;
}

Money operator+(const Money &lhs, const Money &rhs) {
	return (lhs._totalCents + rhs._totalCents) / 100;
}

Money operator-(const Money &lhs, const Money &rhs) {
	return (lhs._totalCents - rhs._totalCents) / 100;
}

Money &Money::operator+=(const Money &rhs) {
	return *this = *this + rhs;
}

Money &Money::operator-=(const Money &rhs) {
	return *this = *this - rhs;
}

Money &Money::operator*=(const Money &rhs) {
	return *this = (_totalCents * rhs._totalCents) / 10000;
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
