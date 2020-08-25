#pragma once
#include<iostream>
#include<string>		/*  for string class  */ 
#include "Maze2dGenerator.h"
#include "Position.h"

/********************************************/
/************Part of task A.c****************/
/***************Search Maze******************/
/********************************************/

class Searchable  //Pure Abstract class 
{
public:
	virtual std::vector<std::string> getpossiblemoves(Position& p) = 0;
	virtual Position getpositions() = 0;
	virtual void setNewPosition(int x, int y) = 0;
	virtual std::string getClass() = 0;

};