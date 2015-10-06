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
#include <vector>

// My files
#include "hill-climbing.h"
#include "state-node.h"

//////////////////////////////
/// Function Declarations ///

/* Randomizes the queens on the board */
// Char2D is a std::vector< std::vector<char> > (2D vector)
void randomizeGame(Char2D &state, int size);

/* Gets the number of queens from the user */
void getNumQueens(int &size);

// Global Variables
int STATES_CHANGED = 0;
int RESTARTS = -1;


/*
	Main Function:
		Sets up the game board, starts the hill climbing algo, prints results
*/
int main(int argc, char* argv[])
{
	//////////////////
	/// Variables ///
	StateNode finishState;
	bool finished = false;							// Flag for checking if the puzzle has completed
	srand(static_cast<unsigned int>(time(NULL)));	// Seeding rand() for better random numbers
	int size = 4;									// Holds size of puzzle

	// Get the number of queens from the user
	getNumQueens(size);

	// Make dynamic 2D array of the specified size
	Char2D init(size, std::vector<char>(size));
	
	// Puzzle Main loop
	while (!finished)
	{		
		// Randomize the queens placement on the board
		randomizeGame(init, size);

		// Make the initial state with the current game board
		StateNode initState(init, size);

		// Run the hillclimbing algo
		finishState = HillClimbing<StateNode>::Run(initState, size, STATES_CHANGED);

		// Check to see if the algo returned a valid end state
		if (finishState.getHeuristic() == 0)
			finished = true;
	}		

	// Print results of game to screen
	std::cout << "\nComplete State\n";
	finishState.printState();
	std::cout << "\nNumber of Restarts: " << RESTARTS << std::endl
		<< "States moved to: " << STATES_CHANGED << std::endl;

	return 0;
}

/*
	Randomizes the placement of the queens on the board
*/
void randomizeGame(Char2D &state, int size)
{
	RESTARTS++;

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
		<< "  * Queens of size 16 and larger may take some time\n";

	// Make sure the number of queens is larger than 3
	do
	{
		std::cout << "\nHow many queens do you want to solve for?  __\b\b";
		std::cin >> size;
	} while (size < 4);
}