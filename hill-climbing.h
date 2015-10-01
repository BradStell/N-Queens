#ifndef HILL_CLIMBING_H
#define HILL_CLIMBING_H

#include "state-node.h"

//////////////////////////////////
/// Dynamic Class Declaration ///
template <class T>
class HillClimbing
{
	public:
		static T* Run(T *initState);
		static T* GetBestNeighbor(T* currentState);
};


/////////////////////////////////
/// Dynamic Class Definition ///

/*
	Hill Climbing Run method is the main entry point for the 
	hill climbing algorithm
*/
template <class T>
T* HillClimbing<T>::Run(T *initState)
{
	T *current = initState;
	T *neighbor;
	bool stillLooking = true;

	std::cout << current->getHeuristic();

	/*while (stillLooking)
	{
		neighbor = GetBestNeighbor(current);
		if (neighbor->getHeuristic() >= current->getHeuristic)
			return current;
		else
			current = neighbor;
	}*/
}

/*
	GetBestNeighbor will return the node which has the lowest
	heuristic value.
*/
template <class T>
T* HillClimbing<T>::GetBestNeighbor(T *currentState)
{

}

#endif