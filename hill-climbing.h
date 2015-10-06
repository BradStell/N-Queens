//////////////////////////////////////////////////////////////
//															//
//	Author: Brad Stell										//
//															//
//	Date: 10/5/2015											//
//															//
//	Language: c++											//
//															//
//	Description: This class is the hill climbing algorithm.	//
//   It has one public method called run which will run		//
//	 the hill climbing algorithm on a state.				//
//															//
//////////////////////////////////////////////////////////////

#ifndef HILL_CLIMBING_H
#define HILL_CLIMBING_H

#include "state-node.h"
#include "heuristic.h"

//////////////////////////////////
/// Dynamic Class Declaration ///
template <class T>
class HillClimbing
{
	private:
		static T GetBestNeighbor(T currentState, int size);

	public:
		static T Run(T initState, int size);
};


/////////////////////////////////
/// Dynamic Class Definition ///

/*
	Hill Climbing Run method is the main entry point for the 
	hill climbing algorithm
*/
template <class T>
T HillClimbing<T>::Run(T initState, int size)
{
	// Make pointers to two StateNodes
	T current = initState;
	T neighbor;

	// Set a flag indicating if we are still looking for a finished 
	// state or not
	bool stillLooking = true;	

	// While we have not found a finished state, look for one
	while (stillLooking)
	{
		// Get the best neighboring state of the current state
		neighbor = GetBestNeighbor(current, size);

		// If the best neighbor of current does not have a better
		// heuristic value, then current is the best state we can do
		// so return it
		if (neighbor.getHeuristic() >= current.getHeuristic())
		{
			//delete neighbor;
			return current;
		}
			

		// If the heuristic of neighbor was better than current,
		// make it our new current and start the algo over
		else
		{
			//delete current;
			current = neighbor;
		}
	}
}

/*
	GetBestNeighbor will return the node which has the lowest
	heuristic value.
*/
template <class T>
T HillClimbing<T>::GetBestNeighbor(T currentState, int size)
{
	// Make a 2D array to hold the heuristic matrix
	int** heuristicArray = new int*[size];
	for (int i = 0; i < size; i++)
		heuristicArray[i] = new int[size];

	// Get the current state of the game board
	Char2D nowState = currentState.getState();

	// Set an index as to what row we are on
	int row = 0;

	// Make a pointer to a StateNode for reference to the best state
	/*T* bestNeighbor;*/

	// Loop through all columns in the 2D game board array
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			// Find the queen
			if (nowState[j][i] == 'X')
			{
				// Set the value in the heuristic array at the location of the 
				// queens current position
				heuristicArray[j][i] = NQueens::CalcHeuristic(nowState, size);

				// Grab the row location of the queen for manipulation
				row = j;

				// Remove queen from that spot
				nowState[j][i] = ' ';				

				// Move queen up one tile at a time, at each new location 
				// put the value of the new heuristic into the heuristic array
				// at the location of where the queen is moved to
				while (row > 0)
				{
					nowState[--row][i] = 'X';
					heuristicArray[row][i] = NQueens::CalcHeuristic(nowState, size);
					nowState[row][i] = ' ';
				}

				// Grab the location of the original queen again
				row = j;

				// Move queen down one tile at a time, at each new location 
				// put the value of the new heuristic into the heuristic array
				// at the location of where the queen is moved to
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

	// find minimum value in the heuristic array
	// looping through the columns
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

	for (int i = 0; i < size; i++)
		delete[] heuristicArray[i];

	// Place the queen in the location of the best heuristic value
	// from the heuristic array
	for (int j = 0; j < size; j++)
	{
		if (nowState[j][minCol] == 'X')
			nowState[j][minCol] = ' ';
	}
	nowState[minRow][minCol] = 'X';

	// Make a new StateNode object with the new best state
	T bestNeighbor(nowState, size);

	return bestNeighbor;
}

#endif