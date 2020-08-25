#include "MazeCompression.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define SIZE 20000

MazeCompression::MazeCompression(Maze2d& maze) { //constarctor for empty maze
	my_maze = maze.getData();  //Get data of maze and set it as object class
	w = maze.getW();
	h = maze.getH();

	//find the end and start position 
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++) {
			if (my_maze[i][j] == 9) { //9 meens start position 
				xS = i;
				yS = j;
			}
			if (my_maze[i][j] == 10) { //10 meens goal position 
				xE = i;
				yE = j;
			}
		}
}

bool MazeCompression::exists(const std::string& name) {
	ifstream file(name); //open file
	if (!file)
		return false;
	else
	{
		file.close();
		return true;
	}
}


void MazeCompression::save(std::string& FileName) {
	if (my_maze.size() == 0)
		//first need to set it in constractor.
		throw "No maze has been set in order to save it ";

	std::string name = FileName;
	//set it as valid file.txt
	std::string txt = ".txt";
	name.append(txt);
	std::string path2 = "C:/Users/shani/source/repos/finalGames2020/finalGames2020/Files/";
	path2.append(name);
	name = path2;


	//check if FileName given is allray exist and ask for difrent nameFile
	while (exists(name)) {
		cout << "File Name is allrady exists" << endl;
		cout << "Choose new Name :  " << endl;
		cin >> name;
	}

	ofstream myfile;
	myfile.open(name.c_str(), ios::trunc);  //open empty file for writing

	myfile << "(" << w << ", " << h << ")" << endl; //size
	myfile << "(" << xS << ", " << yS << ")" << endl; //start
	myfile << "(" << xE << ", " << yE << ")" << endl; //end

	//Compression of the maze: 
	//markes : Wall=1 , Space =0 , Start = 9 , End =10 , PathSolution =2 (2 is not checked here)
	int count0 = 0, count1 = 0, findStart = 0, findEnd = 0;
	int k = 0, z = 0;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (my_maze[i][j] == 0 && count0 > 0)
				count0++;
			else if (my_maze[i][j] == 1 && count1 > 0)
				count1++;

			//for chenges num
			if (my_maze[i][j] == 0 && count1 > 0) {
				com_maze.push_back(count1);
				com_maze.push_back(1);

				myfile << count1 << "  " << 1 << "  ";
				count1 = 0;
				count0++;
			}
			else if (my_maze[i][j] == 1 && count0 > 0) {
				com_maze.push_back(count0);
				com_maze.push_back(0);

				myfile << count0 << "  " << 0 << "  ";
				count0 = 0;
				count1++;
			}

			//for first [0][0]
			else if (my_maze[i][j] == 0 && count0 == 0 && count1 == 0)
				count0++;
			else if (my_maze[i][j] == 1 && count0 == 0 && count1 == 0)
				count1++;

			//for start and goal
			else if (my_maze[i][j] == 9) {
				findStart++;
				if (count0 > 0) {
					com_maze.push_back(count0);
					com_maze.push_back(0);

					myfile << count0 << "  " << 0 << "  ";
					count0 = 0;
				}
				if (count1 > 0) {
					com_maze.push_back(count1);
					com_maze.push_back(1);


					myfile << count1 << "  " << 1 << "  ";
					count1 = 0;
				}
				com_maze.push_back(findStart);
				com_maze.push_back(9);

				myfile << findStart << "  " << 9 << "  ";
			}
			else if (my_maze[i][j] == 10) {
				findEnd++;
				if (count0 > 0) {
					com_maze.push_back(count0);
					com_maze.push_back(0);

					myfile << count0 << "  " << 0 << "  ";
					count0 = 0;
				}
				if (count1 > 0) {
					com_maze.push_back(count1);
					com_maze.push_back(1);

					myfile << count1 << "  " << 1 << "  ";
					count1 = 0;
				}
				com_maze.push_back(findEnd);
				com_maze.push_back(10);
				myfile << findEnd << "  " << 10 << "  ";
			}
		}
	}

	cout << "Maze Data Saved in a File" << endl;
	myfile.close();
}


int MazeCompression::convertToInt(int n) {
	switch (n)
	{
	case 48:  n = 0;
		break;
	case 49:  n = 1;
		break;
	case 50:  n = 2;
		break;
	case 51:  n = 3;
		break;
	case 52:  n = 4;
		break;
	case 53:  n = 5;
		break;
	case 54:  n = 6;
		break;
	case 55:  n = 7;
		break;
	case 56:  n = 8;
		break;
	case 57:  n = 9;
		break;

	default:
		break;
	}
	return n;
}

void MazeCompression::load(std::string& FileName) {

	//set it as valid file.txt
	std::string txt = ".txt";
	FileName.append(txt);
	std::string path2 = "C:/Users/shani/source/repos/finalGames2020/finalGames2020/Files/";
	path2.append(FileName);
	FileName = path2;

	if (exists(FileName) == false) {
		cout << "File Name is Not exists" << endl;
		cout << "Can not lode it to a maze " << endl;
		return;
	}
	string line;
	ifstream myfile(FileName);
	bool fEof = false;
	char tempLine[20000];
	int numOfData = 0;
	int num = 0;
	int myData[2];
	int d = 0;
	int lineNum = 0;
	int go = 0;
	int myMaze[10000] = { 0 };

	if (myfile.is_open())
	{

		while (getline(myfile, line))
		{
			lineNum++;
			cout << line << '\n';

			go = numOfData;
			for (char& c : line)
				tempLine[numOfData++] = c;

			//line 4:
			int now = 0, dd = 0;
			if (lineNum == 4) {
				for (int i = go; tempLine[i] != -52; i++) {
					if ((int)tempLine[i] <= 57 && (int)tempLine[i] >= 48) { //between 0-9


					//insert:
						now++;
						num = convertToInt(tempLine[i]);
						//if its 10 :
						int after = i + 1;
						if (after < SIZE) {
							if ((int)tempLine[after] <= 57 && (int)tempLine[after] >= 48) {
								num = num * 10;
								i++;
							}
						}
						myData[d++] = num;
						if (now == 2) {
							for (int d1 = 0; d1 < myData[0]; d1++)
								myMaze[dd++] = myData[1];

							d = 0;
							now = 0;
						}

					}
				}

				//put into maze:
				int k = 0;
				for (int i = 0; i <= w - 1; i++) {
					std::vector<int> row;
					for (int j = 0; j <= h - 1; j++) {
						row.push_back(myMaze[k++]);
					}
					my_maze.push_back(row);
				}

				//size of file :
				long begin, end;
				begin = myfile.tellg();
				myfile.seekg(0, ios::end);
				end = myfile.tellg();
				myfile.close();
				FileSize = (end - begin);
				myfile.close();
				return;
			}



			for (int i = go; tempLine[i] != -52; i++) {
				if ((int)tempLine[i] <= 57 && (int)tempLine[i] >= 48) { //between 0-9
					//insert:
					num += convertToInt(tempLine[i]);
					//chake num after 
					int after = i + 1;

					if (after < 200) {
						if ((int)tempLine[after] <= 57 && (int)tempLine[after] >= 48)
							num = num * 10;
						//if ther is no num after so thets the num anf put it as object
						else
						{
							myData[d++] = num;
							num = 0;
						}
					}
				}
			}

			//1 line:
			if (lineNum == 1) {
				w = myData[0];
				h = myData[1];
				d = 0;
			}

			//2 line:
			if (lineNum == 2) {
				xS = myData[0];
				yS = myData[1];
				d = 0;
			}

			//3 line:
			if (lineNum == 3) {
				xE = myData[0];
				yE = myData[1];
				d = 0;
			}
		}
		myfile.close();
	}
}


void MazeCompression::printMazeFile(std::vector<std::vector<int>> my_maze, int w, int h) {
	Maze2d m(my_maze, w, h);
	cout << m << endl;		 //print from Maze2d Operator
}

int MazeCompression::getSize() {
	return FileSize;
}