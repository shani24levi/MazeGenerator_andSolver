#include "CommonSearcher.h"

CommonSearcher::CommonSearcher() :m_evaluateNodes(0) {
	//row = { -1, 0, 0, 1 };
	row[0] = -1;
	row[1] = 0;
	row[2] = 0;
	row[3] = 1;

	//col = { 0, -1, 1, 0 };
	col[0] = 0;
	col[1] = -1;
	col[2] = 1;
	col[3] = 0;
}


bool operator<(const Position& p1, const Position& p2)
{
	return p1._Currposition < p2._Currposition;
}

void CommonSearcher::print_queue() {
	while (!m_openList.empty()) {
		std::cout << m_openList.top() << " ";
		m_openList.pop();
	}
	std::cout << '\n';
}

/////***------------------BFS----------------------------***///

bool  BFS::isValid(Maze2dSearchable& s , std::vector<std::vector<int>>  visited, int row, int col)
{

	return (row >= 0) && (row < s.getMaze().getW()) && (col >= 0) && (col < s.getMaze().getH())
		&& s.getMaze().getMaze(row, col) == 0 && !visited[row][col]; //visited =0 meens unvisted
}

bool  BFS::isValidEnd(Maze2dSearchable& s, std::vector<std::vector<int>>  visited, int row, int col)
{
	return (row >= 0) && (row < s.getMaze().getW()) && (col >= 0) && (col < s.getMaze().getH())
		&& s.getMaze().getMaze(row, col) == 10;
}

Solution BFS::search(Searchable& s) {
	Solution solve2;

	//Function for routing by game type
	//The implementation of the function is by type of game so it should not have been covered here at all.
	std::cout << "Function for routing by game type" << std::endl;

	return solve2;
}


void BFS::drowFormat(Maze2dSearchable& s, std::vector<std::vector<int>>  visited) {
	for (int i = 0; i <s.getMaze().getW() ; i++)
	{
		std::cout << "  ";
		for (int j = 0; j < s.getMaze().getH(); j++)
		{
			std::cout << " " << visited[i][j] << "  ";
		}
		std::cout << " ";
		std::cout << '\n';
	}
}


Solution BFS::search(Maze2dSearchable& s) {
	Solution solve; //Holds the array of solutions

	//get the (x,y) of end Position:
	int x = s.getpositions().getXend();
	int y = s.getpositions().getYend();
	GoalFound = false;


	//push it as a starting point of the path souletion
	m_openList.push(s.getpositions()); //look on position1 position2 as start 

	// initially all cells are unvisited
	std::vector<std::vector<int>>  _visited;
	for (int l = 0 ; l < s.getMaze().getW(); l++) {
		std::vector<int> row;
		for (int ll = 0; ll < s.getMaze().getH(); ll++) {
			row.push_back(0);
		}
		_visited.push_back(row);
	}

	while (!m_openList.empty())
	{
		// pop front node from queue and process it
		Position position = m_openList.top();
		m_openList.pop();

		// (i, j) represents current cell and dist stores its
		// minimum distance from the source
		int i = position.getPosition1(), j = position.getPosition2();
		//int i = node.x, j = node.y, dist = node.dist;

		// if destination is found 
		if (i == x && j == y)
		{
			int min_dist = m_evaluateNodes;
			break;
		}

		// check for all 4 possible movements from current cell
		for (int k = 0; k < 4; k++)
		{
			//when get to the goal 
			if (isValidEnd(s, _visited, i + row[k], j + col[k])) {
				prev.push_back(std::make_unique<Position>(s.getpositions()));
				s.setNewPosition(i + row[k], j + col[k]);
				prev.push_back(std::make_unique<Position>(s.getpositions()));
				GoalFound = true;
			}
		}

		if (GoalFound) break;

		//  enqueue each valid movement
		for (int k = 0; k < 4; k++)
		{

			// get all un visited nodes
			if (isValid(s, _visited , i + row[k], j + col[k]))
			{	
				// mark next cell as visited and enqueue it
				_visited[i + row[k]][j + col[k]] = 2;
				prev.push_back(std::make_unique<Position>(s.getpositions()));

				//s.getMaze().setMaze(i + row[k], j + col[k], 2);

				m_evaluateNodes = m_evaluateNodes + 1;
				//put the node to array of nabres
				s.setNewPosition(i + row[k], j + col[k]);
				m_openList.push(s.getpositions());
			}
		}
	}
	//if not found return empty
	if( !GoalFound ) 
		return solve;  //empty

	//if found set in a sulotion and retuen
	Position endP = s.getpositions();
	auto nextPtr = std::make_unique<Position>(endP); //end position


	auto nn = prev.size();
	int n = (int)nn;
		
	for (nextPtr; prev.size() ;) {

		if (n == 0) {
			solve.setSolution(std::move(nextPtr));
			return solve;
		}
		--n;
		std::unique_ptr<Position> nextPtr = std::move(prev.at(n));
		int x = nextPtr.get()->getPosition1();
		int y = nextPtr.get()->getPosition2();

		solve.setSolution(std::move(nextPtr));
		if(s.getMaze().getMaze(x,y) != 10 && s.getMaze().getMaze(x, y) != 9)
			s.getMaze().setMaze( x , y , 2 );
	}
}



/////***------------------AStar----------------------------***///
Solution AStar::search(Searchable& s) {
	Solution solve2;

	//Function for routing by game type
	//The implementation of the function is by type of game so it should not have been covered here at all.
	std::cout << "Function for routing by game type" << std::endl;

	return solve2;
}
Solution AStar::search(Maze2dSearchable& s) {
	Solution solve; //Holds the array of solutions
	return solve;
}

void AStar::setSolve(Maze2dSearchable& m, Solution& s) {
	//int n = s.SolutionSize();
		
	//for (int i=0 ; i < n; i++) {
	//	//auto a = s.getSolution1();
	//	//a[n].get()->getPosition1();
	//	//int x = a.front().get()->getPosition1();
	//	//int y = a.front().get()->getPosition2();

	//	//if(m.getMaze().getMaze(x,y) != 10 && m.getMaze().getMaze(x, y) != 9)
	//	//	m.getMaze().setMaze( x , y , 2 );
	//}
}

void AStar::printAStarInMaze(Maze2dSearchable& m) {
	//std::cout << m.getMaze() << std::endl;
}
