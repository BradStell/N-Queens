#ifndef HILL_CLIMBING_H
#define HILL_CLIMBING_H

#include "state-node.h"

//////////////////////////////////
/// Dynamic Class Declaration ///
template <class T>
class HillClimbing
{
	public:
		static T* Run(T *initState);
		static T* GetBestNeighbor(T* currentState);
		static int CalcHeuristic(char** state);
		static void CalcHorzH(char ** state, int &heuristic);
		static void CalcColH(char ** state, int &heuristic);
		static void CalcDiagH(char ** state, int &heuristic);
		static int calcCollisions(int queensPerRow);
};


/////////////////////////////////
/// Dynamic Class Definition ///

/*
	Hill Climbing Run method is the main entry point for the 
	hill climbing algorithm
*/
template <class T>
T* HillClimbing<T>::Run(T *initState)
{
	T *current = initState;
	T *neighbor;
	bool stillLooking = true;	

	while (stillLooking)
	{
		neighbor = GetBestNeighbor(current);
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
T* HillClimbing<T>::GetBestNeighbor(T *currentState)
{
	int** heuristicArray = new int*[4];
	for (int i = 0; i < 4; i++)
		heuristicArray[i] = new int[4];

	char** nowState = currentState->getState();
	int row = 0;
	T* bestNeighbor;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// find the queen
			if (nowState[j][i] == 'X')
			{
				// set current state heuristic
				heuristicArray[j][i] = CalcHeuristic(nowState);

				// Grab the row spot for manipulation
				row = j;

				// remove queen from that spot
				nowState[j][i] = ' ';				

				// Move queen up
				while (row > 0)
				{
					nowState[--row][i] = 'X';
					heuristicArray[row][i] = CalcHeuristic(nowState);
					nowState[row][i] = ' ';
				}

				row = j;
				// Move queen down
				while (row < 3)
				{
					nowState[++row][i] = 'X';
					heuristicArray[row][i] = CalcHeuristic(nowState);
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
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (heuristicArray[j][i] < heuristicArray[minRow][minCol])
			{
				minRow = j;
				minCol = i;
			}
		}					
	}

	// Replace Queen
	for (int j = 0; j < 4; j++)
	{
		if (nowState[j][minCol] == 'X')
			nowState[j][minCol] = ' ';
	}
	nowState[minRow][minCol] = 'X';

	bestNeighbor = new T(nowState);

	return bestNeighbor;
}

template<class T>
inline int HillClimbing<T>::CalcHeuristic(char ** state)
{
	int heuristic = 0;

	CalcHorzH(state, heuristic);
	CalcColH(state, heuristic);
	CalcDiagH(state, heuristic);

	return heuristic;
}

template<class T>
inline void HillClimbing<T>::CalcHorzH(char ** state, int &heuristic)
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

	heuristic += collisions;
}

template<class T>
inline void HillClimbing<T>::CalcColH(char ** state, int &heuristic)
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

	heuristic += collisions;
}

template<class T>
inline void HillClimbing<T>::CalcDiagH(char ** state, int &heuristic)
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

	heuristic += collisions;
}

template<class T>
inline int HillClimbing<T>::calcCollisions(int queensPerRow)
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

#endif