#pragma once
#include "Maze2d.h"
#include "View.h"
#include "Model.h"
#include <string> 
#include <map>
using namespace std;


class Command
{
public:
	Command() {
		v = new View(_out);
		mo = new Model(_out);
	}
	virtual void execute() = 0;
	void setCommend(std::string& s) { currComand = s; }
	void inOut(std::istream* in, std::ostream* out) {
		_in = in;
		_out = out;
	}
	void brackCommand();
	void setAllComm(std::string& a, std::string& a1, std::string& a2, std::string& a3, std::string& a4) {
		commandName = a;
		s1 = a1;
		s2 = a2;
		s3 = a3;
		s4 = a4;
	}

	int convert(std::string& a) {
		int myint1 = stoi(a);
		return myint1;
	}

protected:
	Maze2d m1;
	View* v;
	Model* mo;
	std::ostream* _out; // The output stream
	std::istream* _in; // The input stream
	std::string currComand;
	std::string commandName, s1, s2,s3,s4;
	int w, h;
	map<string, Maze2d> myMazesByName;

};
 

class DirCommand : public Command
{
public:
	DirCommand(Maze2d* light) : m_light(light), Command(){}
	DirCommand(Maze2d _m1) { _m1 = m1; }
	void execute()
	{
		std::string path;
		if (s1 != " ") {
			path = s1;
		}
		else {
			std::cout << "path is not valid" << std::endl;
			return;
		}
		
		v->setOut(_out);
		v->dir(path);	
	}
private:
	Maze2d* m_light;
	Maze2d m1;

};


class generatCommand : public Command
{
public:
	generatCommand(Maze2d* light) : m_light(light), Command() {}
	void execute()
	{
		//v = new View(_out);
		//mo = new Model(_out);
		w = convert(s2);
		h = convert(s3);

		Maze2d& _m = mo->generateMaze(w, h, s4);
		v->setOut(_out);
		//need to check if it came back as a valid maze and then
		v->generateMaze(s1);
		//save it in my map:
		myMazesByName[s1] = _m;
		v->setMazes(s1, _m);
	}
private:
	Maze2d* m_light;
};


class displyCommand : public Command
{
public:
	displyCommand(Maze2d* light) : m_light(light), Command() {}
	void execute()
	{
		//v = new View(_out);
		//mo = new Model(_out);

		v->setOut(_out);
		v->display(s1);
	}
private:
	Maze2d* m_light;
};

class saveCommand : public Command
{
public:
	saveCommand(Maze2d* light) : m_light(light) {}
	saveCommand(Maze2d _m1) { _m1 = m1; }
	void execute()
	{
		v = new View(_out);
		mo = new Model(_out);
		mo->setOut(_out);
		mo->save(s1, _m);
	}
private:
	Maze2d* m_light;
	Maze2d _m;

};

class loadCommand : public Command
{
public:
	loadCommand(Maze2d* light) : m_light(light) {}
	loadCommand(Maze2d _m1) { _m1 = m1; }
	void execute()
	{
		v = new View(_out);
		mo = new Model(_out);
		mo->setOut(_out);
		mo->load(s1, m1);
		mo->save(s2, m1); //save it with new name =s2
	}
private:
	Maze2d* m_light;
	Maze2d _m;

};

class sizeMazeCommand : public Command
{
public:
	sizeMazeCommand(Maze2d* light) : m_light(light) {}
	sizeMazeCommand(Maze2d _m1) { _m1 = m1; }

	void execute()
	{
		v = new View(_out);
		mo = new Model(_out);
		mo->setOut(_out);
		int size = mo->mazeSize(m1);
		v->setOut(_out);
		v->mazeSize(size);
	}
private:
	Maze2d* m_light;
	Maze2d _m;
};

class sizeFileCommand : public Command
{
public:
	sizeFileCommand(Maze2d* light) : m_light(light) {}
	sizeFileCommand(Maze2d _m1) { _m1 = m1; }

	void execute()
	{
		v = new View(_out);
		mo = new Model(_out);
		mo->setOut(_out);
		int size = mo->fileSize(m1);
		v->setOut(_out);
		v->fileSize(size);
	}
private:
	Maze2d* m_light;
	Maze2d _m;

};

class solveCommand : public Command
{
public:
	solveCommand(Maze2d* light) : m_light(light) {}
	solveCommand(Maze2d _m1) { _m1 = m1; }

	void execute()
	{
		v = new View(_out);
		mo = new Model(_out);
		mo->setOut(_out);
		//Solution s = mo->solve(m1, s1);
		//v->setOut(_out);
		//if(s.getSolution() != nullptr)
		//v->solve(s1);
	}
private:
	Maze2d* m_light;
	Maze2d _m;

};

class displySolveCommand : public Command
{
public:
	displySolveCommand(Maze2d* light) : m_light(light) {}
	displySolveCommand(Maze2d _m1) { _m1 = m1; }

	void execute()
	{
		v = new View(_out);
		mo = new Model(_out);
		v->setOut(_out);
		v->display(s1);
	}
private:
	Maze2d* m_light;
	Maze2d _m;
};

