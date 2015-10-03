#ifndef STATE_NODE_H
#define STATE_NODE_H

class StateNode
{
	private:
		char** state;
		int heuristic;

	public:
		StateNode(char** state);
		~StateNode();
		void calculateHeuristic();
		int getHeuristic();
		void printState();
		void calcHorzCol();
		void calcVertCol();
		void calcDiagCol();
		int calcCollisions(int queensPerRow);
		char** getState();
};

#endif
