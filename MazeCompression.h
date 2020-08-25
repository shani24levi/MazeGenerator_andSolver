#pragma once
#include "Maze2d.h"
#include "Solution.h"

/********************************************/
/************Part of task B.a****************/
/***************Use Files *******************/
/********************************************/

class MazeCompression
{
public:
	MazeCompression() {}			 //for load from exist file
	MazeCompression(Maze2d& maze);  //for save m maze
	void save(std::string& FileName);
	void load(std::string& FileName);
	std::vector<std::vector<int>> getMaze() { return my_maze; }
	int getW() { return w; }
	int getH() { return h; }
	bool exists(const std::string& name);
	void printMazeFile(std::vector<std::vector<int>> my_maze, int w, int h);
	int convertToInt(int n);
	int getSize();



private:
	std::vector<std::vector<int>> my_maze;			/* Stores maze	*/
	int w, h, xS, yS, xE, yE;
	std::vector<int> com_maze;						/* Stores MazeCompression	*/
	long FileSize;
};
