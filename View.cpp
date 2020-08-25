#include "View.h"
#include <fstream>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

/*
https://stackoverflow.com/questions/50668814/vs2017-e0135-namespace-std-has-no-member-filesystem
*/


void View::dir(std::string& dir_path) {
	std::string path = dir_path;
	// print it out to screen or to  file
	if (getOut() == &std::cout) { 
		for (const auto& entry : fs::directory_iterator(path))
			std::cout << entry.path() << std::endl;
	}
	else
	{
		for (const auto& entry : fs::directory_iterator(path))
			*out << entry.path() << std::endl;

	}
}

//
void View::generateMaze(std::string name) {
	if (getOut() == &std::cout) {
		std::cout << "Maze " << name << " is ready" << std::endl;
	}
	else
	{
		*out << "Maze " << name << " is ready" << std::endl;
	}
}

//
//void View::display(Maze2d* m) {
//	if (getOut() == &std::cout) {
//		std::cout << m << std::endl;
//	}
//	else
//	{
//		*out << m << std::endl;
//	}
//}

void View::display(std::string name) {
	Maze2d m;
	for (auto itr = myMazesByName.find(name); itr != myMazesByName.end(); itr++)
		 m = myMazesByName.find(name)->second;
	//Maze2d m = getMaze(name);
	if (getOut() == &std::cout) {
		std::cout << m << std::endl;
	}
	else
	{
		*out << m << std::endl;
	}
}



void View::mazeSize(int size) {
	if (getOut() == &std::cout) {
		std::cout << size << std::endl;
	}
	else
	{
		*out << size << std::endl;
	}
}

void View::fileSize(int size) {
	if (getOut() == &std::cout) {
		std::cout << size << std::endl;
	}
	else
	{
		*out << size << std::endl;
	}
}

void View::solve(std::string name) {
	if (getOut() == &std::cout) {
		std::cout << "Solution for " << name << " is ready" << std::endl;
	}
	else
	{
		*out << "Solution for " << name << " is ready" << std::endl;
	}
}

//void View::display(std::string name) {
//	if (getOut() == &std::cout) {
//		std::cout << mView << std::endl;
//	}
//	else
//	{
//		*out << mView << std::endl;
//	}
//}
