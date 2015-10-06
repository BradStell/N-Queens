//////////////////////////////////////////////////////////
//														//
//	Author: Brad Stell									//
//														//
//	Date: 10/5/2015										//
//														//
//	Language: c++										//
//														//
//	Description: This class represends a node for a		//
//   particular instance of the game n-queens. The node	//
//   contains the game state, as well as a few methods	//
//   to operate on the node.							//
//														//
//////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include "state-node.h"
#include "heuristic.h"

/* Constructor, accepts a state and a size (the number of queens) */
StateNode::StateNode(const Char2D& theState, int theSize) :
	state(theState),
	size(theSize),
	heuristic(NQueens::CalcHeuristic(state, size)) {}

/* Prints the state with a nice like board for better visualization */
void StateNode::printState()
{
	for (int i = 0; i < this->size; i++)
		std::cout << " ____";
	std::cout << std::endl;

	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			if (j < this->size - 1)
			{
				
				std::cout << "| " << state[i][j] << "  ";
				
			}
			else
			{
				
				std::cout << "| " << state[i][j] << "  |";
				
			}

		}
		std::cout << std::endl;
		for (int k = 0; k < this->size; k++)
			std::cout << "|____";
		std::cout << "|\n";
	}
}