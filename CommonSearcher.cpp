#include "CommonSearcher.h"


bool operator<(const Position& p1, const Position& p2)
{
	 //this will return true when second person  
	 //has greater height. suppose we have p1.height=5  
	 //and p2.height=5.5 then the object which 
	 //have max height will be at the top(or  
	 //max priority) 
	return p1._Currposition < p2._Currposition;
}


void CommonSearcher::print_queue() {
	while (!m_openList.empty()) {
		std::cout << m_openList.top() << " ";
		m_openList.pop();
	}
	std::cout << '\n';
}

///***------------------BFS----------------------------***///

std::shared_ptr<Solution> BFS::search(Searchable& s) {
	std::shared_ptr<Solution> solve;

	//Start with curr position of the Player 
	int currPosition = s.getpositions().getCuurPosition(); 
	//get the (x,y) of curr Position:
	int x = s.getpositions().getPosition1();
	int y = s.getpositions().getPosition2();

	//push it as a starting point of the path souletion
	m_openList.push(s.getpositions());

	//set next cube: 
	m_openList.push(s.getpositions());
	s.setNewPosition(++x,++y);
	m_openList.push(s.getpositions());

	//s.setNewPosition(++currPosition);
	//m_openList.push(s.getpositions());
	//std::cout << "2  ";
	print_queue();
	return solve;
}
