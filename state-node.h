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

class StateNode
{
	private:
		char** state;
		int heuristic;
		int size;

	public:
		StateNode(char** state, int size);
		~StateNode();
		int getHeuristic();
		void printState();
		char** getState();
};

#endif
