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

	cout << mon * 10 << endl;
	cout << mon * mon << endl;
	cout << (test *= -1) << endl;
	return 0;
}