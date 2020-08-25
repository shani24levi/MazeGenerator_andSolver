#include "CLI.h"
#include <iostream>
#include <fstream>


CLI::CLI(std::istream& in, std::ostream& out) :in(&in), out(&out) {
	//input
	if (&in != &std::cin)
	{
		std::cout << "input from File" << std::endl;
	}
	//output
	if (&out != &std::cout)
	{
		std::cout << "output from File" << std::endl;
	}
}


void CLI::Read(std::istream& is)
{
	std::string line;
	while (getline(is, line)) {
		std::cout << line;
		commendes.push_back(line);
	}
}

void CLI::start() {
	Maze2d* light = new Maze2d;

	/*Advanced Use from screen */
	if (in == &std::cin) {
		string command = "";
		while (command.compare("exit") != 0)
		{
			Controller* controller = new Controller(light);
			cout << ">>";
			cin >> command;

			controller->brackCommand(command);
			string mycommand = controller->getComand();
			string s1 = controller->gets1();
			string s2 = controller->gets2();
			string s3 = controller->gets3();
			string s4 = controller->gets4();

			Command* com = controller->get(mycommand);
			if (nullptr != com) {
				com->setAllComm(mycommand, s1, s2, s3, s4);
				//com->setCommend(command);
				com->inOut(in,out);
				com->execute();
			}
			else
				cout << "Unsupported Command!" << endl;

		}
	}

	else //if (in != &std::cin) meens its a file
	{
		std::istream& instart = *in;
		std::string command;

		Read(instart);

		//go over comandes in the array.
		int i = 0;
		while (commendes[i++].compare("exit") != 0)
		{
			Controller* controller = new Controller(light);
			command = commendes[i];

			Command* com= controller->get(command);
			if (nullptr != com)
				com->execute();
			else
				std::cout << "Unsupported Command!" << std::endl;
		}
	}
}