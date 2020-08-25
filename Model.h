#pragma once
#include "Maze2d.h"
#include "Solution.h"

/********************************************/
/************ Part of task C ****************/
/***************    MVC    ******************/
/********************************************/

class Model
{
public:
	Model(std::ostream* o) : out(o) {}
	Maze2d& generateMaze(int w, int h, std::string& className);
	void save(std::string& name, Maze2d& maze);
	void load(std::string& name, Maze2d& maze);
	int mazeSize(Maze2d& maze);
	int fileSize(Maze2d& maze);
	Solution& solve(Maze2d& maze, std::string& name);

	std::ostream* getOut() { return out; }
	void setOut(std::ostream* o) { o = out; }


private:
	std::ostream* out; // The output stream
};

