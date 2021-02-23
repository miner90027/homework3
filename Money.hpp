/* Aleks McCormick
 * UAF CS 202
 * Homework3
 * Program 2: Money class
 * 02/20/2021
 */

#ifndef HOMEWORK3_MONEY_HPP
#define HOMEWORK3_MONEY_HPP
#include <iostream>

class Money {
	friend std::ostream & operator<< (std::ostream &os, const Money &mon);
	friend bool operator== (const Money &lhs, const Money &rhs);
	friend bool operator< (const Money &lhs, const Money &rhs);
	friend Money operator+(const Money &lhs, const Money &rhs);
	friend Money operator-(const Money &lhs, const Money &rhs);

public:
	Money(int d, int c);
	Money(double d = 0);

	Money & operator+=(const Money &rhs);
	Money & operator-=(const Money &rhs);
	Money & operator*=(const Money &rhs);

private:
	double _totalCents;
	double _dollars;
	double _cents;

};

Money operator*(Money lhs, const Money &rhs);

bool operator!=(const Money &lhs, const Money &rhs);
bool operator>(const Money &lhs, const Money &rhs);
bool operator<=(const Money &lhs, const Money &rhs);
bool operator>=(const Money &lhs, const Money &rhs);

#endif //HOMEWORK3_MONEY_HPP
