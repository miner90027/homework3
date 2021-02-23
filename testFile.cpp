/* Aleks McCormick
 * UAF CS 202
 * Homework3
 * Main Program: A Simple Tokenizer
 * 02/20/2021
 */
#include <iostream>
#include "Money.hpp"
using std::cout;
using std::endl;

int main() {
	Money dollar;
	Money mon(12, 50);
	Money tst(20.6679);
	Money test(-30, 99);

	cout << (dollar > 19) << endl;
	cout << (mon != tst)<< endl;
	cout << (tst == 20.67)<< endl;
	cout << (test <= dollar) << endl;
	return 0;
}