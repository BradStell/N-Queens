//////////////////////////////////////////////////////////////
//															//
//	Author: Brad Stell										//
//															//
//	Date: 10/5/2015											//
//															//
//	Language: c++											//
//															//
//	Description: Header file of custom namespace declaring	//
//		function entry point for calculating the heuristic	//
//		for the n-queens puzzle								//
//															//
//////////////////////////////////////////////////////////////

#ifndef HEURISTIC_H
#define HEURISTIC_H

// Make custom namespace to hold the heuristic
// calculating function
typedef std::vector<std::vector<char>> Char2D;

namespace NQueens
{
	int CalcHeuristic(Char2D state, int size);
}

#endif