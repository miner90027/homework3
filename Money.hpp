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

public:
	Money(int d, int c);
	Money(double d = 0);

private:
	double _totalCents;
	double _dollars;
	double _cents;

};


#endif //HOMEWORK3_MONEY_HPP
