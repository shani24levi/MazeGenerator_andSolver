#include <iostream>
#include <fstream>
#include <string>

#include "Controller.h"
#include "Maze2d.h"
#include "CLI.h"
#include "Maze2dGenerator.h"
#include "TestMazeGenerator.h"
#include "Maze2dSearchable.h"
#include "CommonSearcher.h"
#include "MazeCompression.h"
#include "Controller.h"
#include "Model.h"
#include "View.h"
#include "Demo.h"


using namespace std;


// The client
int main()
{

	//main for craerting maze:
	//--------------------------
	//TestMazeGenerator t;
	//simpleMaze2dGenerator m2;
	//t.testMazeGenerator(m2);
	//MyMaze2dGenerator m3;
	//t.testMazeGenerator(m3);

	//main for searches:
	//--------------------------
	//MyMaze2dGenerator m4; //create by defulte 5*5
	//Maze2d& maze = m4.generate(15, 15);
	//Maze2dSearchable e(maze);
	//auto p = e.getpositions();
	//std::vector<std::string> s = e.getpossiblemoves(p);
	//BFS bfs;
	//Solution b = bfs.search(e);

	//Demo d;
	//d.run();

	//main for file 
	//--------------------------
	//MazeCompression me(maze);
	//MazeCompression me;
	//std::string st = "te22222t1";
	//me.save(st);
	//me.load(st);
	//me.printMazeFile(me.getMaze(), me.getW(), me.getH());

	//main for MVC
	//--------------------------
	//out to a file
	std::filebuf fb;
	fb.open("test.txt", std::ios::out);
	std::ostream os(&fb);

	//read from a file
	std::ifstream inFile("example.txt");

	CLI cli(cin, cout);
	cli.start();

	//in from file sample
	CLI cli2(inFile,cout);
	cli.start();

	fb.close();
	inFile.close();

	cin.get();
	return 0;
}