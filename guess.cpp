//guess implementation

#include "guess.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void Guess::startGuess()
{
	int userGuess;
	int range;
	int integers;
	int numberOfTries = 0;
	int correctNumbers = 0;
	
	//Entering in m and n
	cout << "Enter the max of the number range for the game: ";
	cin >> range;
	cout << "Enter the number of integers for the game: ";
	cin >> integers;

	//createRandomNumber call
	createRandomNumber(range, integers);

	while (true)
	{
		//Inputting guesses
		for (int i = 0; i < integers; i++)
		{
			cout << "Enter in guess " << i << ": ";
			cin >> userGuess;
			guessVector.push_back(userGuess);
		}

		//Call for comparing the guess to the random numbers
		correctNumbers = compareGuess(guessVector);

		cout << endl;

		if (correctNumbers == integers)
		{
			cout << "Congratulations! You guessed all correct!" << endl;
			exit(0);
		}

		else
		{
			cout << correctNumbers << " of your guesses are correct. Enter in your next set of guesses." << endl;
			guessVector.clear();
		}
	}
}

void Guess::createRandomNumber(int range, int integers)
{
	//Generating random numbers and populating randomVector
	srand(time(NULL));
	for (int i = 0; i < integers; i++)
	{
		int newRandom = rand() % range + 1;
		randomVector.push_back(newRandom);
	}

	cout << endl;
}

int Guess::compareGuess(vector <int> &userVector)
{
	//This will compare the user's guess with the random vector
	//It will return either the number of correct numbers
	
	int size = randomVector.size();
	int correctNumbers = 0;

	for (int i = 0; i < size; i++)
	{
		int searchValue = userVector[i];
		int first = 0;
		int middle;
		int last = size - 1;
		int position = -1;
		bool found = false;

		while (!found && first <= last)
		{
			middle = (first + last) / 2;
			if (randomVector[middle] == searchValue)
			{
				found = true;
				position = middle;
			}
			else if (randomVector[middle] > searchValue)
			{
				last = middle - 1;
			}
			else
			{
				first = middle + 1;
			}
		}

		if (found == true)
		{
			correctNumbers++;
		}
	}

	return correctNumbers;
}