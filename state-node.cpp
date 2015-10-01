#include <iostream>
#include "state-node.h"


StateNode::StateNode(char ** state)
{
	this->state = state;
}

StateNode::~StateNode()
{
}

void StateNode::calculateHeuristic()
{
}

int StateNode::getHeuristic()
{
	return 0;
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
