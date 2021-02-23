/* Aleks McCormick
 * UAF CS 202
 * Homework3
 * Program 2: Money class
 * 02/20/2021
 */

#ifndef HOMEWORK3_MONEY_HPP
#define HOMEWORK3_MONEY_HPP


class Money {

public:
	Money(int d, int c);
	Money(double d = 0);

	double getTotal();
private:
	double _totalCents;
	double _dollars;
	double _cents;

};


#endif //HOMEWORK3_MONEY_HPP
