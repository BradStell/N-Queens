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

void randomizeGame(char** state);

int main(int argc, char* argv[])
{
	StateNode *initState;
	StateNode *finishState;
	bool finished = false;
	srand(time(NULL));

	char** init = new char*[4];
	for (int i = 0; i < 4; i++)
		init[i] = new char[4];

	while (!finished)
	{
		randomizeGame(init);

		initState = new StateNode(init);
		//initState->printState();

		finishState = HillClimbing<StateNode>::Run(initState);

		if (finishState->getHeuristic() == 0)
			finished = true;
	}		

	std::cout << "\nFound solution:\n";
	finishState->printState();

	std::cout << "\ninit state h = " << initState->getHeuristic() << std::endl
		<< "Best state h = " << finishState->getHeuristic() << std::endl;

	return 0;
}

void randomizeGame(char** state)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			state[j][i] = ' ';
	}

	for (int i = 0; i < 4; i++)
		state[rand() % 4][i] = 'X';
}