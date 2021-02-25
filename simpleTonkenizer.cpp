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
	if(argc < 2){
		cout << "No file input. Please specify a file to access." << endl;
		return -1;
	}

	ifstream fileIn(argv[1]);

	if(!fileIn){
		cout << "Could not open the specified file. If the file name doesn't work please specify the file path." << endl;
		return -2;
	}

	return 0;
}

void printTokens(ostream &os, const vector<TokenAndPosition> &tokens) {
	for(auto i: tokens){
		os << "Line\t" << i._line << ", Column\t" << i._column << ": \"" << i._token << "\"" << endl;
	}
}