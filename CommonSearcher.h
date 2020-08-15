#pragma once
#include "Searcher.h"
#include <functional>
#include <queue>

			/********************************************/
			/************Part of task A.c****************/
			/***************Search Maze******************/
			/********************************************/

class CommonSearcher : public Searcher
{
public:
	CommonSearcher() :m_evaluateNodes(0) {}

	////implamantion of Searcher mathodes
	virtual std::shared_ptr<Solution> search(Searchable& s) = 0 ; //abstract mathode
	virtual int getNumberOfNodeMaze2d() { return m_evaluateNodes; }

	const Position& popOpenList() { m_evaluateNodes++; return m_openList.top(); }
	void print_queue();


protected:
	int m_evaluateNodes;
	std::priority_queue<Position> m_openList;

};



///***------------------BFS----------------------------***///
/*Pseudocode BFS:

BFS (G, s)											//Where G is the graph and s is the source node
	  let Q be queue.
	  Q.enqueue( s )								//Inserting s in queue until all its neighbour vertices are marked.

	  mark s as visited.
	  while ( Q is not empty)
		 v  =  Q.dequeue( )							 //Removing that vertex from queue,whose neighbour will be visited now
		  
													 //processing all the neighbours of v
		  for all neighbours w of v in Graph G
			   if w is not visited
						Q.enqueue( w )				 //Stores w in Q to further visit its neighbour
						mark w as visited.
*/

class BFS : public CommonSearcher
{
public:
	BFS() : CommonSearcher(){}
	virtual std::shared_ptr<Solution> search(Searchable& s);
};



///***------------------AStar----------------------------***///
class AStar : public CommonSearcher
{
public:
	AStar() : CommonSearcher() {}
	virtual std::shared_ptr<Solution> search(Searchable& s);
};
