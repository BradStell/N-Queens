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
#include "hill-climbing.h"
#include "state-node.h"

int main(int argc, char* argv[])
{
	char** init = new char*[4];
	for (int i = 0; i < 4; i++)
		init[i] = new char[4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == 0)
				init[i][j] = 'X';
			else
				init[i][j] = ' ';
		}
	}

	char** test = new char*[4];
	for (int i = 0; i < 4; i++)
		test[i] = new char[4];

	char letter = 'a';
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			test[i][j] = letter++;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			std::cout << test[i][j] << " ";		
		std::cout << std::endl;
	}
	std::cout << std::endl;
	StateNode testState(test);
	testState.printDiagonals();
	std::cout << std::endl;
	testState.printOtherDiags();


	/*StateNode *initState = new StateNode(init);

	StateNode *finishState = HillClimbing<StateNode>::Run(initState);*/

	return 0;
}