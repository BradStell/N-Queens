#ifndef HEURISTIC_H
#define HEURISTIC_H

namespace NQueens
{
	static int heur = 0;
	int CalcHeuristic(char** state, int size);
	void CalcHorzH(char ** state, int &heuristic, int size);
	void CalcColH(char ** state, int &heuristic, int size);
	void CalcDiagH(char ** state, int &heuristic, int size);
	int calcCollisions(int queensPerRow, int size);
}


#endif