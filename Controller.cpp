#include "Controller.h"


void Controller::brackCommand(std::string currComand) {
	std::string str = currComand;
	std::string next,s11,s22,s33,s44;

	//std::string commandName, s1, s2;

	std::string::size_type pos = str.find('<');

	//save in str the command , and the reast in commandName
	if (str.npos != pos) {
		next = str.substr(pos + 1);
		str = str.substr(0, pos);
	}
	commandName = str;

	//2:
	std::string::size_type pos4 = next.find('<');
	if (pos4 > 100) {
		pos4 = next.find('>');
		s11 = next.substr(0, pos4);
		s1 = s11;
		return;
	}
	else if(next.npos != pos4) {
		s11 = next.substr(pos4+2 - 1);
		next = next.substr(0, pos4-1);
	}
	s1 = next;

	//3:
	std::string::size_type pos3 = s11.find('<');
	if (pos3 > 100) {
		pos3 = s11.find('>');
		s22 = s11.substr(0, pos3);
		s2 = s22;
		return;
	}
	else if (s11.npos != pos3) {
		s22 = s11.substr(pos3 + 2 - 1);
		s11 = s11.substr(0, pos3 - 1);
	}
	s2 = s11;


	//4:
	std::string::size_type pos2 = s22.find('<');
	if (pos2 > 100) {
		pos2 = s22.find('>');
		s33 = s22.substr(0, pos2);
		s3 = s33;
		return;
	}
	else if (s22.npos != pos2) {
		s33 = s22.substr(pos2 + 2 - 1);
		s22 = s22.substr(0, pos2 - 1);
	}
	s3 = s22;

	//5:
	std::string::size_type pos1 = s33.find('<');
	if (pos1 > 100) {
		pos1 = s33.find('>');
		s44 = s33.substr(0, pos1);
		s4 = s44;
		return;
	}
	else if (s33.npos != pos1) {
		s44 = s33.substr(pos1 + 2 - 1);
		s33 = s33.substr(0, pos1 - 1);
	}
	s4 = s44;


}
