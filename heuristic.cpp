#include "heuristic.h"


int NQueens::CalcHeuristic(char ** state, int size)
{
	NQueens::heur = 0;

	NQueens::CalcHorzH(state, NQueens::heur, size);
	NQueens::CalcColH(state, NQueens::heur, size);
	NQueens::CalcDiagH(state, NQueens::heur, size);

	return NQueens::heur;
}

void NQueens::CalcHorzH(char ** state, int &heur, int size)
{
	int queensPerRow = 0;
	int collisions = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (state[i][j] == 'X')
			{
				queensPerRow++;
			}
		}
		collisions += calcCollisions(queensPerRow, size);
		queensPerRow = 0;
	}

	NQueens::heur += collisions;
}

void NQueens::CalcColH(char ** state, int &heur, int size)
{
	int queensPerCol = 0;
	int collisions = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (state[j][i] == 'X')
			{
				queensPerCol++;
			}
		}
		collisions += calcCollisions(queensPerCol, size);
		queensPerCol = 0;
	}

	NQueens::heur += collisions;
}

void NQueens::CalcDiagH(char ** state, int &heur, int size)
{
	int queensPerDiag = 0;
	int collisions = 0;

	// Do first diagonal
	for (int k = 0; k < size * 2; k++)
	{
		for (int j = 0; j <= k; j++)
		{
			int i = k - j;
			if (i < size && j < size) {
				if (state[j][i] == 'X')
				{
					queensPerDiag++;
				}
			}
		}
		collisions += calcCollisions(queensPerDiag, size);
		queensPerDiag = 0;
	}

	queensPerDiag = 0;
	// Do second diagonal
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0, x = i; x <= size - 1; j++, x++)
		{
			if (state[x][j] == 'X')
			{
				queensPerDiag++;
			}
		}
		collisions += calcCollisions(queensPerDiag, size);
		queensPerDiag = 0;
	}

	for (int i = 0; i <= size - 1; i++)
	{
		for (int j = 0, y = i; y <= size - 1; j++, y++)
		{
			if (state[j][y] == 'X')
			{
				queensPerDiag++;
			}
		}
		collisions += calcCollisions(queensPerDiag, size);
		queensPerDiag = 0;
	}

	NQueens::heur += collisions;
}

int NQueens::calcCollisions(int queensPerRow, int size)
{
	int collisions = 0;
	int temp = 0;

	if (queensPerRow == 0 || queensPerRow == 1)
		return 0;

	for (int i = 0; i <= size; i++)
	{
		if (queensPerRow == i)
			collisions = temp;
		else
			temp += i;
	}

	return collisions;
}