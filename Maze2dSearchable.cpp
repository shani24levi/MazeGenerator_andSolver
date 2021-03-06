#include "Maze2dSearchable.h"


Maze2dSearchable::Maze2dSearchable(Maze2d& maze)
{	//Set Maze uses opertor = of class Maze2d
	m = maze;

	//Set Position  uses opertor = of class Position
	auto mm = m.Positions();
	p = mm;
}


Maze2dSearchable* Maze2dSearchable::operator = (Position* p) {
	m.Positions() = p;
	return this;
}



Position  Maze2dSearchable::getpositions() {
	return p;
}

std::vector<std::string>  Maze2dSearchable::getpossiblemoves(Position& p) {
	std::vector<std::string> possibalMoves = m.getPossibleMoves(p);
	return possibalMoves;
}

void  Maze2dSearchable::setNewPosition(int x, int y) {
	int ii = 0;
	int count = 0;
	for (; ii < m.getW(); ii++) {
		for (int j = 0; j < m.getH(); j++) {
			count++;
			if (ii == x && j == y) {
				p.setX(ii);
				p.setY(j);
				p.choosePosition(count);
				p.CuurPosition(count);
				return;
			}
		}

	}
}