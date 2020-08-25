#pragma once
#include "Maze2d.h"
#include <map>
using namespace std;

/********************************************/
/************ Part of task C ****************/
/***************    MVC    ******************/
/********************************************/

class View
{
public:
	View() {}
	View(std::ostream* o) : out(o) {}

	void dir(std::string& s);
	void generateMaze(std::string name);
	//void display(Maze2d* m);
	void display(std::string name);

	void mazeSize(int size);
	void fileSize(int size);
	void solve(std::string name);
	///void display(std::string name);

	std::ostream* getOut() { return out; }
	void setOut(std::ostream* o) {
		if (o != nullptr)
			out = o; 
	}

	void setMazes(string& s, Maze2d& m) {
		myMazesByName[s] = m;
	}
	Maze2d& getMaze(string s) {
		for (auto itr = myMazesByName.find(s); itr != myMazesByName.end(); itr++)
			return myMazesByName.find(s)->second;
	}
	


protected:
	std::ostream* out; // The output stream
	Maze2d mView;
	map<string, Maze2d> myMazesByName;

};

