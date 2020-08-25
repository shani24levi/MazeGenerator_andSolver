#pragma once
#include<iostream> 
#include <fstream>			 //ifstream
#include <map>			
#include<string>			/*  for string class  */ 
#include "Maze2d.h"
#include "Command.h"
#include "Controller.h"




/********************************************/
/************Part of task B.b****************/
/***************part of View*****************/
/************Commendes from user*************/
/********************************************/

/*************************************************************/
/********************pormat of file is************************/
/*********************comandName1<..> '\n' *******************/
/*********************comandName2<..> '\n' *******************/
/*********************comandName3<..> '\n' *******************/
/*********************Exite '\n' *****************************/
/*************************************************************/




class CLI
{
public:
	CLI() : in(&std::cin), out(&std::cout) {}
	CLI(std::istream& in, std::ostream& out);
	void start();
	void Read(std::istream& is);

protected:
	std::ostream* out; // The output stream
	std::istream* in; // The input stream
	std::vector<std::string> commendes;

};