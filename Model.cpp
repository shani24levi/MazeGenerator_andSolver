#include "Model.h"
#include <iostream>
#include "Maze2dGenerator.h"
#include "MazeCompression.h"
#include "Maze2dSearchable.h"
#include "CommonSearcher.h"

Maze2d& Model::generateMaze(int w, int h, std::string& className) {
	Maze2d maze1;
	std::string classNameHere = "myMaze2d";
	std::string& classNam1 = classNameHere;
	if (className.compare(classNam1) == 0) {
		MyMaze2dGenerator myMaze;
		Maze2d& maze = myMaze.generate(w, h);
		return maze;
	}
	if (className == "simpleMaze2d") {
		simpleMaze2dGenerator myMaze;
		Maze2d& maze = myMaze.generate(w, h);
		return maze;
	}
	else{
		std::cout << "Class Name is not difened";
		return maze1;
	}
}

void Model::save(std::string& name, Maze2d& maze) {
	MazeCompression mc(maze);
	mc.save(name);
}

void Model::load(std::string& name, Maze2d& maze) {
	MazeCompression mc(maze);
	mc.load(name);
}

int Model::mazeSize(Maze2d& maze) {
	return maze.getData().size();
}

int Model::fileSize(Maze2d& maze) {
	MazeCompression mc(maze);
	return mc.getSize();
}

Solution& Model::solve(Maze2d& maze, std::string& name) {
	if (name == "BFS") {
		Maze2dSearchable e(maze);
		BFS bfs;
		Solution b = bfs.search(e);
		return b;
	}
	//didnt do aSraer class
	if (name == "AStar") {
		//Maze2dSearchable e(maze);
		//AStar a;
		//Solution b = a.search(e);
		//return b;
	}
	else {
		std::cout << "Search Type is not difened";
	}

}
