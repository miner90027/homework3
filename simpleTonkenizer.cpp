/* Aleks McCormick
 * UAF CS 202
 * Homework3
 * Program 1: A Simple Tokenizer
 * 02/25/2021
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ostream;
using std::istream;

struct TokenAndPosition{
	string _token;
	int _line;
	unsigned int _column;
};

vector<string> lineToTokens(const string &line);
vector<TokenAndPosition> readLines(istream &is);
void printTokens(ostream &os, const vector<TokenAndPosition> &tokens);

int main(int argc, char* argv[]) {

	return 0;
}
