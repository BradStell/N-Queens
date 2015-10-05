//////////////////////////////////////////////////////////////////////////////////
//																				//
//   Author:	Brad Stell														//
//																				//
//	  Date:		9/30/2015														//
//																				//
//	  Language:		c++															//
//																				//
//	  Description:																//
//		This program will implement 'Random-Restart Hill Climbing' algorithm	//
//		to solve the N-Queens problem. The N-Queens problem has an N x N board	//
//		with N queens placed randomly on the board. The goal of the puzzle is	//
//		to place the queens in such a manner so that there is no conflicts		//
//		between queens. Thus, no queen shall be in the same row, column or		//
//		diagonal as any other queen.											//
//																				//
//////////////////////////////////////////////////////////////////////////////////

// C++ libraries
#include <iostream>
#include <cstdlib>
#include <time.h>

// My files
#include "hill-climbing.h"
#include "state-node.h"

//////////////////////////////
/// Function Declarations ///

/* Randomizes the queens on the board */
void randomizeGame(char** state, int size);

/* Gets the number of queens from the user */
void getNumQueens(int &size);


/*
	Main Function:
		Sets up the game board, starts the hill climbing algo, prints results
*/
int main(int argc, char* argv[])
{
	//////////////////
	/// Variables ///
	StateNode *initState = nullptr;					// Pointer to the initial state
	StateNode *finishState = nullptr;				// Pointer to the final state
	bool finished = false;							// Flag for checking if the puzzle has completed
	srand(static_cast<unsigned int>(time(NULL)));	// Seeding rand() for better random numbers
	int size = 4;									// Holds size of puzzle

	// Get the number of queens from the user
	getNumQueens(size);

	// Make dynamic 2D array of the specified size
	char** init = new char*[size];
	for (int i = 0; i < size; i++)
		init[i] = new char[size];

	// Game loop (not hillclimbing loop)
	while (!finished)
	{
		// Randomize the queens placement on the board
		randomizeGame(init, size);

		// Make the initial state with the current game board
		initState = new StateNode(init, size);

		// Run the hillclimbing algo
		finishState = HillClimbing<StateNode>::Run(initState, size);

		// Check to see if the algo returned a valid end state
		if (finishState->getHeuristic() == 0)
			finished = true;
	}		

	// Print results of game to screen
	std::cout << "\nFound solution:\n";
	finishState->printState();
	std::cout << "Best state h = " << finishState->getHeuristic() << std::endl;

	return 0;
}

/*
	Randomizes the placement of the queens on the board
*/
void randomizeGame(char** state, int size)
{
	// First remove all queens from the board
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			state[j][i] = ' ';
	}

	// Place a queen in each columb at a random row
	for (int i = 0; i < size; i++)
		state[rand() % size][i] = 'X';
}

/*
	Get number of queens as input from the user
*/
void getNumQueens(int &size)
{
	std::cout << "\n\t** This program solves the N-Queens puzzle **\n\n"
		<< "Rules:\n  You must choose the # of queens to be of size 4 or larger.\n"
		<< "  (< 4 there is no solution).\n"
		<< "  * Queens of size 10 and larger may take some time\n";

	// Make sure the number of queens is larger than 3
	do
	{
		std::cout << "\nHow many queens do you want to solve for?  __\b\b";
		std::cin >> size;
	} while (size < 4);
}