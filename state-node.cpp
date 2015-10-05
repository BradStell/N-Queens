#include <iostream>
#include "state-node.h"
#include "heuristic.h"


StateNode::StateNode(char ** state, int size)
{
	this->state = state;
	this->size = size;
	this ->heuristic = NQueens::CalcHeuristic(state, size);
}

StateNode::~StateNode()
{
	for (int i = 0; i < this->size; i++)
		delete [] state[i];
}

int StateNode::getHeuristic()
{
	return this->heuristic;
}

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

char ** StateNode::getState()
{
	// Must make copy of state to prevent outside manipulation
	char** state = new char*[this->size];
	for (int i = 0; i < this->size; i++)
		state[i] = new char[this->size];

	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
			state[i][j] = this->state[i][j];
	}

	return state;
}