//////////////////////////////////////////////////////////
//														//
//	Author: Brad Stell									//
//														//
//	Date: 10/5/2015										//
//														//
//	Language: c++										//
//														//
//	Description: This file contains the functions to	//
//		calculate the heuristic of the n-queens puzzle	//
//														//
//////////////////////////////////////////////////////////

#include <vector>
#include "heuristic.h"

/*
	Anonymous namespace containing function declarations 
	for the methods used to calculate the heuristic.
	Putting them in an anonymous namespace makes the functions
	invisible to outside code, making them only visible to the
	Methods in this file.
*/
namespace {
	static int heur = 0;
	void CalcHorzH(Char2D state, int &heuristic, int size);
	void CalcColH(Char2D state, int &heuristic, int size);
	void CalcDiagH(Char2D state, int &heuristic, int size);
	int calcCollisions(int queensPerRow, int size);
}


// Visible function from other code with the NQueens namespace
// Calculates the heuristic value of a particular state
int NQueens::CalcHeuristic(Char2D state, int size)
{
	heur = 0;

	// Calculate collisions per row
	CalcHorzH(state, heur, size);

	// Calculate collisions per column
	CalcColH(state, heur, size);

	// Calculate collisions per diagonal
	CalcDiagH(state, heur, size);

	return heur;
}


/*
Anonymous namespace containing function definitions
for the methods used to calculate the heuristic.
Putting them in an anonymous namespace makes the functions
invisible to outside code, making them only visible to the
Methods in this file.
*/
namespace {

	/* Calculate the horizontal collisions between queens */
	void CalcHorzH(Char2D state, int &heur, int size)
	{
		int queensPerRow = 0;
		int collisions = 0;

		// loop through the rows searching for queens,
		// if a queen is encountered increment the 
		// queensPerRow counter.
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (state[i][j] == 'X')
				{
					queensPerRow++;
				}
			}

			// Based on the number of queens in a particular row
			// find how many collisions that equates to
			collisions += calcCollisions(queensPerRow, size);

			// Reset the variable because we are about to go to another row
			queensPerRow = 0;
		}

		// Add number of collisions to the heuristic variable
		heur += collisions;
	}

	/* Calculate the column collisions */
	void CalcColH(Char2D state, int &heur, int size)
	{
		int queensPerCol = 0;
		int collisions = 0;

		// Loop through the columns counting how many queens appear
		// in each column
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (state[j][i] == 'X')
				{
					queensPerCol++;
				}
			}

			// Based on the # of queens in a column, find how many
			// collisions that equates to
			collisions += calcCollisions(queensPerCol, size);

			// Reset variable because we are about to go to another column
			queensPerCol = 0;
		}

		// Add number of collisions to the heuristic variable
		heur += collisions;
	}

	/* Calculate diagonal collisions */
	void CalcDiagH(Char2D state, int &heur, int size)
	{
		int queensPerDiag = 0;
		int collisions = 0;

		// Loop through the diagonals bottom left to top right
		int k = 0, l = 0;
		for (int i = 0; i < size * 2 + size / 2 + 1; i++)
		{
			k = 0;
			l = i;
			for (int j = i; j < size * 2 + size / 2 + 1; j++)
			{
				if (l >= 0 && l < size && k < size)
				{
					if (state[l][k] == 'X')
						queensPerDiag++;
				}					
				k++;
				l--;
			}
			// Based on # of queens in diagonal, find how many 
			// collisions this equates to
			collisions += calcCollisions(queensPerDiag, size);

			// Reset queen for next diagonal
			queensPerDiag = 0;
		}

		// Second diagonal: top left to bottom right
		queensPerDiag = 0;
		int r = 0, p = 0;
		for (int i = 0; i < size * 2 + size / 2 + 1; i++)
		{
			r = size - 1;
			p = i;
			for (int j = i; j < size * 2 + size / 2 + 1; j++)
			{
				if (p >= 0 && p < size && r >= 0)
				{
					if (state[p][r] == 'X')
						queensPerDiag++;
				}
				r--;
				p--;
			}
			// Based on # of queens in diagonal, find how many 
			// collisions this equates to
			collisions += calcCollisions(queensPerDiag, size);

			// Reset queen for next diagonal
			queensPerDiag = 0;
		}

		// Add diagonal collisions to heuristic total
		heur += collisions;
	}

	/* 
		Calculate # of collisions based on number of queens per
		row/column/diagonal
	*/
	int calcCollisions(int queensPerRow, int size)
	{
		int collisions = 0;
		int temp = 0;

		// If there are 0 or 1 queens, there are no collisions
		if (queensPerRow == 0 || queensPerRow == 1)
			return 0;

		// Loop for as many queens as there are on the game board
		for (int i = 0; i <= size; i++)
		{
			/* 
			 If there are as many queens in a row/column/diagonal
			 as the index, i, then the number of collisions is the
			 sum of all previous indexes, i.
			 Example: 
				If there are 4 queens per row, then there are
			  1 + 2 + 3 = 6 collisions.
			  If there are 5 queens per row, then there is
			  1 + 2 + 3 + 4 = 10 collisions
			*/
			if (queensPerRow == i)
				collisions = temp;
			// Sum all indexes until the index matches the # of queens
			else
				temp += i;
		}

		return collisions;
	}
}