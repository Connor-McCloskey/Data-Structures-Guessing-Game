#pragma once
#ifndef GUESS_H
#define GUESS_H

//Preprocessor directives
#include <vector>

//Namespace
using namespace std;

//Class declaration
class Guess 
{
private:
	vector <int> randomVector;
	vector <int> foundVector;
	vector <int> guessVector;

public:
	//startGuess member function
	void startGuess();

	//createRandomNumber member function
	void createRandomNumber(int, int);

	//compareGuess member function
	int compareGuess(vector<int>&);
};

#endif
