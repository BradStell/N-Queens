#ifndef HILL_CLIMBING_H
#define HILL_CLIMBING_H

#include "state-node.h"
#include "heuristic.h"

//////////////////////////////////
/// Dynamic Class Declaration ///
template <class T>
class HillClimbing
{
	public:
		static T* Run(T *initState, int size);
		static T* GetBestNeighbor(T* currentState, int size);
};


/////////////////////////////////
/// Dynamic Class Definition ///

/*
	Hill Climbing Run method is the main entry point for the 
	hill climbing algorithm
*/
template <class T>
T* HillClimbing<T>::Run(T *initState, int size)
{
	T *current = initState;
	T *neighbor;
	bool stillLooking = true;	

	while (stillLooking)
	{
		neighbor = GetBestNeighbor(current, size);
		if (neighbor->getHeuristic() >= current->getHeuristic())
			return current;
		else
			current = neighbor;
	}

	return current;
}

/*
	GetBestNeighbor will return the node which has the lowest
	heuristic value.
*/
template <class T>
T* HillClimbing<T>::GetBestNeighbor(T *currentState, int size)
{
	int** heuristicArray = new int*[size];
	for (int i = 0; i < size; i++)
		heuristicArray[i] = new int[size];

	char** nowState = currentState->getState();
	int row = 0;
	T* bestNeighbor;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			// find the queen
			if (nowState[j][i] == 'X')
			{
				// set current state heuristic
				heuristicArray[j][i] = NQueens::CalcHeuristic(nowState, size);

				// Grab the row spot for manipulation
				row = j;

				// remove queen from that spot
				nowState[j][i] = ' ';				

				// Move queen up
				while (row > 0)
				{
					nowState[--row][i] = 'X';
					heuristicArray[row][i] = NQueens::CalcHeuristic(nowState, size);
					nowState[row][i] = ' ';
				}

				row = j;
				// Move queen down
				while (row < 3)
				{
					nowState[++row][i] = 'X';
					heuristicArray[row][i] = NQueens::CalcHeuristic(nowState, size);
					nowState[row][i] = ' ';
				}

				// Restore queen
				nowState[j][i] = 'X';
			}
		}
	}

	// find minimum value
	int minRow = 0;
	int minCol = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (heuristicArray[j][i] < heuristicArray[minRow][minCol])
			{
				minRow = j;
				minCol = i;
			}
		}					
	}

	// Replace Queen
	for (int j = 0; j < size; j++)
	{
		if (nowState[j][minCol] == 'X')
			nowState[j][minCol] = ' ';
	}
	nowState[minRow][minCol] = 'X';

	bestNeighbor = new T(nowState, size);

	return bestNeighbor;
}

#endif