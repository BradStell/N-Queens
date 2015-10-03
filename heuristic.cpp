#include "heuristic.h"


int NQueens::CalcHeuristic(char ** state)
{
	NQueens::heur = 0;

	NQueens::CalcHorzH(state, NQueens::heur);
	NQueens::CalcColH(state, NQueens::heur);
	NQueens::CalcDiagH(state, NQueens::heur);

	return NQueens::heur;
}

void NQueens::CalcHorzH(char ** state, int &heur)
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

	NQueens::heur += collisions;
}

void NQueens::CalcColH(char ** state, int &heur)
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

	NQueens::heur += collisions;
}

void NQueens::CalcDiagH(char ** state, int &heur)
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

	NQueens::heur += collisions;
}

int NQueens::calcCollisions(int queensPerRow)
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