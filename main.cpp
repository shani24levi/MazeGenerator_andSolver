#include <iostream>
using namespace std;
#include "Maze2dGenerator.h"
#include "TestMazeGenerator.h"
#include "Maze2dSearchable.h"
#include "CommonSearcher.h"


#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3

int main(void)
{
	try
	{
		//TestMazeGenerator t;
		//simpleMaze2dGenerator m2;
		//t.testMazeGenerator(m2);
		//MyMaze2dGenerator m3;
		//t.testMazeGenerator(m3);

		//main for searches:
		MyMaze2dGenerator m4; //create by defulte 5*5
		Maze2d& maze = m4.generate(15, 15);

		Maze2dSearchable e(maze);
		auto p = e.getpositions();
		std::vector<std::string> s = e.getpossiblemoves(p);
		BFS bfs;
		std::shared_ptr<Solution> b = bfs.search(e);
		//Solution s = bfs.search(e);




		//m.measureAlgorithmTime();
		//m.drow(m1);

		//m = new simpleMaze2dGenerator();
		//	m->drow();
		// std::cout<< m->measureAlgorithmTime();


	//	t.testMazeGenerator(m1);
		//t.testMazeGenerator(new MyMaze2dGenerator());

	}
	catch (const std::exception&)
	{

	}

	return 0;
}





