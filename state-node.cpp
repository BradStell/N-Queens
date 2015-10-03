#include <iostream>
#include "state-node.h"
#include "heuristic.h"


StateNode::StateNode(char ** state)
{
	this->state = state;
	this->heuristic = 0;

	this ->heuristic = NQueens::CalcHeuristic(state);
}

StateNode::~StateNode()
{
	for (int i = 0; i < 4; i++)
		delete [] state[i];
}

int StateNode::getHeuristic()
{
	return this->heuristic;
}

void StateNode::printState()
{
	std::cout << " ____ ____ ____ ____\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j < 3)
			{
				
				std::cout << "| " << state[i][j] << "  ";
				
			}
			else
			{
				
				std::cout << "| " << state[i][j] << "  |";
				
			}

		}
		std::cout << "\n|____|____|____|____|\n";
	}
}

char ** StateNode::getState()
{
	// Must make copy of state to prevent outside manipulation
	char** state = new char*[4];
	for (int i = 0; i < 4; i++)
		state[i] = new char[4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			state[i][j] = this->state[i][j];
	}

	return state;
}