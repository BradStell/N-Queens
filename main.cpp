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
//		with N queens placed randomly on the board. The goal of the game is		//
//		to place the queens in such a manner so that there is no conflicts		//
//		between queens. Thus, no queen shall be in the same row, column or		//
//		diagonal as any other queen.											//
//																				//
//////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include "hill-climbing.h"
#include "state-node.h"

void randomizeGame(char** state, int size);
void getSize(int &size);

int main(int argc, char* argv[])
{
	StateNode *initState;
	StateNode *finishState;
	bool finished = false;
	srand(time(NULL));
	int size = 4;

	getSize(size);

	char** init = new char*[size];
	for (int i = 0; i < size; i++)
		init[i] = new char[size];

	while (!finished)
	{
		randomizeGame(init, size);

		initState = new StateNode(init, size);
		//initState->printState();

		finishState = HillClimbing<StateNode>::Run(initState, size);

		if (finishState->getHeuristic() == 0)
			finished = true;
	}		

	std::cout << "\nFound solution:\n";
	finishState->printState();

	std::cout << "\ninit state h = " << initState->getHeuristic() << std::endl
		<< "Best state h = " << finishState->getHeuristic() << std::endl;

	return 0;
}

void randomizeGame(char** state, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			state[j][i] = ' ';
	}

	for (int i = 0; i < size; i++)
		state[rand() % size][i] = 'X';
}

void getSize(int &size)
{
	std::cout << "\nHow many queens do you want to solve for?";
	std::cin >> size;
}