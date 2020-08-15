#include "Maze2d.h"

Maze2d::Maze2d(int width, int height) : w(width), h(height), _maze(w, std::vector<int>(h, 0))
{
	//Set the start location of the maze:
	startIndex = rand() % w * h + 1;
	currIndex = startIndex;

	//Set the end location of the maze:
	//An array that contains the possible exits of the maze :
	int insert = w * h;
	for (int i = 2; i < w; i++) { //The last row of the matrix without the first sides so the loop starts from 2
		sidesMazeIndexs.push_back(insert--);
	}
	insert = w * h;
	int insertHelf = h;
	int k = 2;
	for (int i = 1; i < h; i++) {
		sidesMazeIndexs.push_back(insertHelf);
		insertHelf = h * k++;
	}
	//Random exit is selected from the array of options
	int flag = 1;
	while (flag) {
		int num = rand() % (sidesMazeIndexs.size() - 1) + 1;
		endIndex = sidesMazeIndexs[num];
		if (endIndex != startIndex)
			flag = 0;
	}

	//Create a temp array of maze (for making comparisons in the matrix)
	int num = 1;
	for (int i = 0; i < w; i++) {
		std::vector<int> row;
		for (int j = 0; j < h; j++) {
			row.push_back(num++);
		}
		_tempArray.push_back(row);
	}
	//Set the start and the end Position in the maze 
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++) {
			if (_tempArray[i][j] == startIndex)
				_maze[i][j] = 9; //start
			if (_tempArray[i][j] == endIndex)
				_maze[i][j] = 10; //end
			if (_tempArray[i][j] == startIndex) { //set (x,y) of Start
				_mazPositions.setX(i);
				_mazPositions.setY(j);
			}

		}
	//set the positions as Position object of the maze for Future use of the player
	//setStartPosition(startIndex);
	//setCurrPosition(currIndex);
	//setEndPosition(endIndex); 
	_mazPositions.StartPosition(startIndex);
	_mazPositions.CuurPosition(currIndex);
	_mazPositions.EndPosition(endIndex);
	
}

Maze2d::Maze2d() {
	/*A maze is created  with 5 * 5 if there is no  given wand h*/
	Maze2d(5, 5);
}

int Maze2d::getCurrMazeIndex() {
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++) {
			if (_tempArray[i][j] == currIndex) {
				currX = i;
				currY = j;
			}
		}
	return currIndex;
}

void Maze2d::setCurrPosition(int curr) {
	currIndex = curr;
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++) {
			if (_tempArray[i][j] == currIndex) {
				currX = i;
				currY = j;
			}
		}
	_mazPositions.CuurPosition(currIndex);
}


void Maze2d::drowMaze() {
	char Wall = char(219);
	std::cout << "S is for Starting Point\nG is for Goal Point\nThe Maze:  \n\n";
	for (int j = 0; j < h; j++) {
		for (int i = 0; i < w; i++) {
			if (_maze[j][i] == 1) {
				std::cout << Wall;
			}
			else if (_maze[j][i] == 9) { //9 meens start position 
				std::cout << "S";
			}
			else if (_maze[j][i] == 10) { //10 meens end position 
				std::cout << "G";
			}
			else {
				if (_maze[j][i] == 2) { //visited =2;
					_maze[j][i] = 0;
				}
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}

std::string Maze2d::getGoalPosition() {
	std::string goalposition = "Goal Position is in cube " + std::to_string(endIndex);
	return goalposition;
}

Position Maze2d::getStartPosition() {
	return _mazPositions;
}

std::vector<std::string> Maze2d::getPossibleMoves(Position& p) {
	std::vector<std::string> possibalMoves; //Contains the Position options

	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++) {
			if (_tempArray[i][j] == currIndex) {
				//chacke 4 cases and set in string array:
				int ii = i;
				int jj = j;

				int right = 1 + jj;
				int left = jj - 1;
				int down = ii + 1;
				int up = ii - 1;
				//Checking which side of the current location I do not have a wall
				//Also Check that it is not outside the matrix
				if (i <= w)
					if (_maze[i][right] != 1)
						possibalMoves.push_back("RIGHT");

				if (left >= 0)
					if (_maze[i][left] != 1)
						possibalMoves.push_back("LEFT");

				if (j <= h)
					if (_maze[down][j] != 1)
						possibalMoves.push_back("DOWN");

				if (j >= 0)
					if (_maze[up][j] != 1)
						possibalMoves.push_back("UP");

				return possibalMoves;
			}
		}
	//security incident - it should never happen!!!
	std::cout << "something is wrong" << std::endl;
	return possibalMoves;
}

//for seting Walls/visited in the Maze in the class that contains a maze-type object
void Maze2d::setMaze(int i, int j, int num) {
	for (int ii = 0; ii < w; ii++)
		for (int jj = 0; jj < h; jj++) {
			if (ii == i && jj == j) {
				_maze[i][j] = num;
				return;
			}
		}
}

//like copy constractor - need it for genarst Walls in the maze
//use as a pointer For access to an asbestos class  
Maze2d* Maze2d::operator = (Maze2d* m) {
	_maze = m->_maze;
	sidesMazeIndexs = m->sidesMazeIndexs;
	_tempArray = m->_tempArray;
	w = m->w;
	h = m->h;
	_mazPositions = m->_mazPositions;
	startIndex = m->startIndex;
	currIndex = m->currIndex;
	endIndex = m->endIndex;
	return this;
}