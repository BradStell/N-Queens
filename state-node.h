//////////////////////////////////////////////////////////
//														//
//	Author: Brad Stell									//
//														//
//	Date: 10/5/2015										//
//														//
//	Language: c++										//
//														//
//	Description: This class represends a node for a		//
//   particular instance of the game n-queens. The node	//
//   contains the game state, as well as a few methods	//
//   to operate on the node.							//
//														//
//////////////////////////////////////////////////////////

#ifndef STATE_NODE_H
#define STATE_NODE_H

#include <vector>
typedef std::vector<std::vector<char>> Char2D;

class StateNode
{
	private:
		Char2D state;
		int size;
		int heuristic;

	public:
		StateNode::StateNode() {}
		StateNode(const Char2D& theState, int theSize);
		int getHeuristic() { return heuristic; }
		void printState();
		Char2D& getState() { return state; }
};

#endif
