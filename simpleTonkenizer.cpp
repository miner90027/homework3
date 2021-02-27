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
#include "StopWatch.hpp"
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::getline;
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
	//checks to make sure the minimum number of arguments is entered
	if(argc < 2){
		cout << "No file input. Please specify a file to access." << endl;
		return -1;
	}

	//read in the command line argument as either a file name or path & check to make sure it opens
	ifstream fileIn(argv[1]);
	if(!fileIn){
		cout << "Could not open the specified file. If the file name doesn't work please specify the file path." << endl;
		return -2;
	}

	//check to see if there is an argument after the file path. If there is & it is the command "--lineonly" set the print boolean to false
	bool print = true;
	if(argc == 3){
		string lnOnly(argv[2]);
		if(lnOnly == "--lineonly")
			print = false;
	}

	StopWatch timer;
	//create a vector of tokens to store what is returned by readLines()
	vector<TokenAndPosition> tokens = readLines(fileIn);

	//print the tokens based on the state of the print boolean
	if(print){
		printTokens(cout, tokens);
	}
	timer.stop();
	cout << "Run time(milliseconds): " << timer.getTimeMilli() << endl;
	return 0;
}

void printTokens(ostream &os, const vector<TokenAndPosition> &tokens) {
	for(auto const &i: tokens){
		int spaceL = 5;
		int spaceC = 5;
		for(int x = i._line; x > 0; x/=10, --spaceL){}
		for(int x = i._column; x > 0; x/=10, --spaceC){}
		os << "Line";
		for(;spaceL > 0; --spaceL)
			os << " ";
		os << i._line << ", Column";
		for(;spaceC > 0; --spaceC)
			os << " ";
		os << i._column << ": \"" << i._token << "\"" << endl;
	}
}

vector<string> lineToTokens(const string &line) {
	vector<string> curLine;
	string temp;
	for(char i : line){
		temp.push_back(i);
		if(i == ' ' || i == '\n'){
			temp.erase(temp.end()-1);
			curLine.push_back(temp);
			temp = "";
		}
	}
	curLine.push_back(temp);

	return curLine;
}

vector<TokenAndPosition> readLines(istream &is) {
	int lineCnt = 1;
	string temp;
	vector<TokenAndPosition> tokenVec;
	TokenAndPosition nToken;

	while(getline(is, temp)){
		vector<string> curLine = lineToTokens(temp);
		unsigned int collCnt = 1;
		for(auto const &i: curLine){
			if(i != "\0"){
				nToken._column = collCnt;
				collCnt += i.size()+1;
				nToken._line = lineCnt;
				nToken._token = i;
				tokenVec.push_back(nToken);
			}
		}
		lineCnt++;
	}
	return tokenVec;
}
