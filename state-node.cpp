#include <iostream>
#include "state-node.h"


StateNode::StateNode(char ** state)
{
	this->state = state;
	this->heuristic = 0;

	/*for (int i = 0; i < 4; i++)
		delete[] state[i];*/

	calculateHeuristic();
}

StateNode::~StateNode()
{
	for (int i = 0; i < 4; i++)
		delete [] state[i];
}

void StateNode::calculateHeuristic()
{
	calcHorzCol();
	calcVertCol();
	calcDiagCol();
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

void StateNode::calcHorzCol()
{
	int queensPerRow = 0;
	int collisions = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (state[i][j] == 'X')
			{
				queensPerRow++;
			}
		}
		collisions += calcCollisions(queensPerRow);
		queensPerRow = 0;
	}

	this->heuristic += collisions;
}

void StateNode::calcVertCol()
{
	int queensPerCol = 0;
	int collisions = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (state[j][i] == 'X')
			{
				queensPerCol++;
			}
		}
		collisions += calcCollisions(queensPerCol);
		queensPerCol = 0;
	}

	this->heuristic += collisions;
}

void StateNode::calcDiagCol()
{
	int queensPerDiag = 0;
	int collisions = 0;

	// Do first diagonal
	for (int k = 0; k < 4 * 2; k++)
	{
		for (int j = 0; j <= k; j++)
		{
			int i = k - j;
			if (i < 4 && j < 4) {
				if (state[j][i] == 'X')
				{
					queensPerDiag++;
				}
			}
		}
		collisions += calcCollisions(queensPerDiag);
		queensPerDiag = 0;
	}

	queensPerDiag = 0;
	// Do second diagonal
	for (int i = 4 - 1; i > 0; i--) 
	{
		for (int j = 0, x = i; x <= 4 - 1; j++, x++) 
		{
			if (state[x][j] == 'X')
			{
				queensPerDiag++;
			}
		}
		collisions += calcCollisions(queensPerDiag);
		queensPerDiag = 0;
	}

	for (int i = 0; i <= 4 - 1; i++) 
	{
		for (int j = 0, y = i; y <= 4 - 1; j++, y++) 
		{
			if (state[j][y] == 'X')
			{
				queensPerDiag++;
			}
		}
		collisions += calcCollisions(queensPerDiag);
		queensPerDiag = 0;
	}

	this->heuristic += collisions;
}

int StateNode::calcCollisions(int queensPerRow)
{
	int collisions = 0;
	int temp = 0;

	if (queensPerRow == 0 || queensPerRow == 1)
		return 0;

	for (int i = 0; i <= 4; i++)
	{		
		if (queensPerRow == i)
			collisions = temp;
		else
			temp += i;
	}

	return collisions;
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
