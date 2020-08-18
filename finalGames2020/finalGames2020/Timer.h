#pragma once
#include <iostream>
#include <chrono> // libraty  for time and date

//Inspired by:  https://www.youtube.com/watch?v=oEx5vGNFrLk
//Creating a class that will give us the time

class Timer
{
	std::chrono::time_point < std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;
public:
	Timer();
	~Timer();
};

