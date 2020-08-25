#pragma once

#include <map>
#include <string>
#include "Command.h"


using namespace std;

class Controller
{
public:
	Controller(Maze2d* light)
	{
		m_commands["dir"] = new DirCommand(light);
		m_commands["generate_maze"] = new generatCommand(light);
		m_commands["display"] = new displyCommand(light);
		m_commands["save_maze"] = new saveCommand(light);
		m_commands["load_maze"] = new loadCommand(light);
		m_commands["maze_size"] = new sizeMazeCommand(light);
		m_commands["file_size"] = new sizeFileCommand(light);
		m_commands["solve"] = new solveCommand(light);
		m_commands["display_solution"] = new displySolveCommand(light);
	}
	~Controller() {}
	void brackCommand(std::string currComand);
	std::string getComand() { return commandName; }
	std::string gets1() { return s1; }
	std::string gets2() { return s2; }
	std::string gets3() { return s3; }
	std::string gets4() { return s4; }

public:
	Command* get(const string& command)
	{
		auto it = m_commands.find(command);
		if (it == m_commands.end())
			return nullptr;

		return it->second;
	}



private:
	map<string, Command*> m_commands;
	std::string currComand;
	std::string commandName, s1, s2,s3,s4;
	int w, h;
};
