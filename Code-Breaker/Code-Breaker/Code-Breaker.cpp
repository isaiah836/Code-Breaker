// Code-Breaker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
	char again = 'y';
	enum fields{WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall", "Do you feel you're bangoing your head against something?"},
		{"glasses","These might help you see the answer."},
		{"labored","Going slowly, is it?"},
		{"persistent","Keep at it."},
		{"scramble","what these words are"},
		{"welcome", "what you do when you invite people into your home"},
		{"happy", "if you are this and you know it clap your hands"},
		{"last", "if you are not first then you're ____"},
		{"long", "Not short but ____"},
		{"towel", "Dries you up"}
	};

	//Seed the random number generator
	srand(static_cast<unsigned int>(time(0)));
	
	do
	{
		int Tries = 0;
		//Welcomes user to the program
		cout << "Welcome to the CIA Code Breaker Program\n\n";
		cout << "This program will train you in decryptions for low-tech scrambles\n\n";
		cout << "Unscramble the letter to make a word.\n\n";
		cout << "Enter 'hint' for a hint.\n";
		cout << "Enter 'quit' to quit the game.\n\n";

		//Makes the user try to unscramble 3 words
		for (int i = 0; i < 3; ++i)
		{
			int choice = (rand() % NUM_WORDS);
			string theWord = WORDS[choice][WORD];//woord to guess
			string theHint = WORDS[choice][HINT]; //hint for the word
			string jumble = theWord; // jumbled version of the word
			string jumble_Check = theWord;
			int length = jumble.size();
			// a do while loop to make sure that when it scrambles it doesnt give the word unscrambled
			do
			{
				for (int i = 0; i < length; ++i)
				{
					int index1 = (rand() % length);
					int index2 = (rand() % length);
					char temp = jumble[index1];
					jumble[index1] = jumble[index2];
					jumble[index2] = temp;
				}
			} while (jumble == jumble_Check);

			//Makes the user take a guess
			string guess;
			cout << "The scramble is " << jumble << endl;
			cout << "\n\nTake your guess: ";
			cin >> guess;

			//just in case I take the user input and lower it here
			for (int i = 0; i < guess.length(); ++i)
			{
				guess[i] = tolower(guess[i]);
			}

			//Loop for guessing
			while ((guess != theWord) && (guess != "quit"))
			{
				if (guess == "hint")
				{
					cout << theHint;
				}
				else
				{
					system("cls");
					cout << "Sorry, that's not it.\n\n";
					cout << "The scramble is " << jumble << endl;
					++Tries;
				}

				cout << "\n\nTake your guess: ";
				cin >> guess;
			}
			if (guess == theWord)
			{
				system("cls");
				cout << "That's it You guessed it!\n\n";
				++Tries;
			}
			// Allows the user to quit
			else if (guess == "quit")
			{
				system("cls");
				cout << "Thanks for playing.\n";
				system("pause");
				return 0;
			}
		}
		// Displays user stats
		cout << "Total Tries: " << Tries << endl;
		cout << "Average tries per word: " << Tries / 3 << endl;
		//Ask the user if they would like to play again
		cout << "Would you like to play again?\n";
		cin >> again;

	} while (again != 'n');
	cout << "\nThanks for playing.\n";
	system("pause");

    return 0;
}

