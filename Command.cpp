#include "Command.h"
void Command::brackCommand() {
	std::string str = currComand;
	//std::string commandName, s1, s2;

	std::string::size_type pos = currComand.find('<');
	std::string::size_type pos2 = currComand.find('>');

	if (currComand.npos != pos && currComand.npos != pos2) {
		commandName = currComand.substr(pos + 1);
		currComand = currComand.substr(0, pos);
	}

	std::string::size_type pos4 = commandName.find('<');
	if (commandName.npos != pos4) {
		s1 = commandName.substr(pos4 + 1);
		commandName = commandName.substr(0, pos4);
	}

	std::string::size_type pos3 = s1.find('<');
	if (s1.npos != pos3) {
		s2 = s1.substr(pos3 + 1);
		s1 = s1.substr(0, pos3);
	}
}
