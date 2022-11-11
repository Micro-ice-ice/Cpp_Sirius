#pragma once
#include <string>
#include <iostream>
#include <vector>

enum Orient
{
	up,
	down,
	right,
	left
};

enum Command
{
	forward,
	backward,
	turn_right,
	turn_left
};

class Robot {

public:

	int X;

	int Y;

	int Orient;

	Robot(int x, int y, int orient);

	void Move(int command);
	
	void Move(std::vector<int> const& commands);

	std::string ToString();

	int operator==(Robot r);
};