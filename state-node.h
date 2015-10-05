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
