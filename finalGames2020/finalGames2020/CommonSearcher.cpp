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
		&& s.getMaze().getMaze(row, col) == 0 && !visited[row][col];

}

std::shared_ptr<Solution> BFS::search(Searchable& s) {
	std::shared_ptr<Solution> solve;

	//Function for routing by game type
	//The implementation of the function is by type of game so it should not have been covered here at all.
	std::cout << "Function for routing by game type" << std::endl;

	return solve;
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

//
//int BFS::bfsMaze(Maze2dSearchable& s, std::vector<std::vector<int>> current, int row, int col) {
//
//	if (row == s.getpositions().getXend() && col == s.getpositions().getYend())
//		return 1;
//	
//	if (current[row][col] == 0) {
//		current[row][col] = 1;
//
//		if ((row >= 0) && (row < s.getMaze().getW()) && (col - 1 >= 0) && (col - 1 < s.getMaze().getH())) {
//			if (bfsMaze(s, current, row, col - 1)) {
//				current[row][col] = 2;
//				s.getMaze().setMaze(row, col, 2);
//				return 1;
//			}
//		}
//		else if ((row + 1 >= 0) && (row + 1 < s.getMaze().getW()) && (col >= 0) && (col < s.getMaze().getH())) {
//			if (bfsMaze(s, current, row + 1, col)) {
//				current[row][col] = 2;
//				s.getMaze().setMaze(row, col, 2);
//
//				return 1;
//			}
//		}
//		else if ((row >= 0) && (row < s.getMaze().getW()) && (col + 1 >= 0) && (col + 1 < s.getMaze().getH())) {
//			if (bfsMaze(s, current, row, col + 1)) {
//				current[row][col] = 2;
//				s.getMaze().setMaze(row, col, 2);
//
//				return 1;
//			}
//		}
//		else if ((row - 1 >= 0) && (row - 1 < s.getMaze().getW()) && (col >= 0) && (col < s.getMaze().getH())) {
//			if (bfsMaze(s, current, row - 1, col)) {
//				current[row][col] = 2;
//				s.getMaze().setMaze(row, col, 2);
//
//				return 1;
//			}
//		}
//	}
//	
//
//	return 0;
//}


std::shared_ptr<Solution> BFS::search(Maze2dSearchable& s){
	Solution solve; //Holds the array of solutions
	std::shared_ptr<Solution> solvePtr ;
	//set pointer:
	solvePtr = std::shared_ptr<Solution>(&solve);

	//Start with curr position of the Player 
	int currPosition = s.getpositions().getCuurPosition();
	//get the (x,y) of end Position:
	int x = s.getpositions().getXend();
	int y = s.getpositions().getYend();


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

		//bfsMaze(s, _visited,i,j);

		//int neighbours[][2] = { {0,0}, {0,0}, {0,0}, {0,0} };
		//std::vector<Position>  neighbours;
		//std::vector<std::vector<int>>  neighbours;
		int neighboursX[4] = { 0 };
		int neighboursY[4] = { 0 };


		// check for all 4 possible movements from current cell
		// and enqueue each valid movement
		for (int k = 0; k < 4; k++)
		{
			// check if it is possible to go to position
			// (i + row[k], j + col[k]) from current position
			if (isValid(s, _visited , i + row[k], j + col[k]))
			{	
				//set all the neighbours of curr cube in arry 
				neighboursX[k] = i + row[k];
				neighboursY[k] = j + col[k];  //[0][0] ,[1][1],[2][2],[3][3]

				//if (!_visited[i + row[k]][j + col[k]]) // if next  is not visited
				//	prev.push_back(std::make_unique<Position>(s.getpositions()));

				// mark next cell as visited and enqueue it
				_visited[i + row[k]][j + col[k]] = 2;
				s.getMaze().setMaze(i + row[k], j + col[k], 2);


				m_evaluateNodes = m_evaluateNodes + 1;
				s.setNewPosition(i + row[k], j + col[k]);
				m_openList.push(s.getpositions());
				//q.push({ i + row[k], j + col[k], m_evaluateNodes + 1 });
			}
		}

		//Check the nebers :

	}

	drowFormat(s, _visited);
	s.getMaze().drowMaze();


	//set next cube: 
	m_openList.push(s.getpositions());
	s.setNewPosition(++x, ++y);
	m_openList.push(s.getpositions());

	//s.setNewPosition(++currPosition);
	//m_openList.push(s.getpositions());
	//std::cout << "2  ";
	print_queue();


	return solvePtr;
}