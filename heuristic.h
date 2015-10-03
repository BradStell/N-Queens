#ifndef HEURISTIC_H
#define HEURISTIC_H

namespace NQueens
{
	static int heur = 0;
	int CalcHeuristic(char** state);
	void CalcHorzH(char ** state, int &heuristic);
	void CalcColH(char ** state, int &heuristic);
	void CalcDiagH(char ** state, int &heuristic);
	int calcCollisions(int queensPerRow);
}


#endif