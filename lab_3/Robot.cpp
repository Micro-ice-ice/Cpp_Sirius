#include "Robot.h"

Robot::Robot(int x, int y, int orient)
{
	X = x;

	Y = y;

	Orient = orient;
}

void Robot::Move(int command)
{
	switch (command)
	{

	case (Command::forward):

		switch (this->Orient)
		{
		case up:
			Y--;
			break;
		case down:
			Y++;
			break;
		case right:
			X++;
			break;
		case left:
			X--;
			break;
		default:
			break;
		}
		break;

	case (Command::backward):

		switch (this->Orient)
		{
		case up:
			Y++;
			break;
		case down:
			Y--;
			break;
		case right:
			X--;
			break;
		case left:
			X++;
			break;
		default:
			break;
		}
		break;
		break;

	case (Command::turn_right):

		switch (this->Orient)
		{
		case up:
			this->Orient = right;
			break;
		case down:
			this->Orient = left;
			break;
		case right:
			this->Orient = down;
			break;
		case left:
			this->Orient = up;
			break;
		default:
			break;
		}
		break;
		break;

	case (Command::turn_left):

		switch (this->Orient)
		{
		case up:
			this->Orient = left;
			break;
		case down:
			this->Orient = right;
			break;
		case right:
			this->Orient = up;
			break;
		case left:
			this->Orient = down;
			break;
		default:
			break;
		}
		break;
		break;
	}
}

void Robot::Move(std::vector<int> const& commands){

	for (int i = 0; i < commands.size(); i++){

		Move(commands[i]);
	}
}

std::string Robot::ToString()
{
	std::string result = "";
	result += "Final position : (";
	result += std::to_string(X) + ", " + std::to_string(Y) + ")" + "\n";
	result += "Final orientation: ";
	switch (this->Orient)
	{
	case up:
		result += "up";
		break;
	case down:
		result += "down";
		break;
	case right:
		result += "right";
		break;
	case left:
		result += "left";
		break;
	default:
		break;
	}
	result += "\n";
	return result;
}

int Robot::operator==(Robot r)
{
	return (X == r.X) && (Y == r.Y) && (Orient == r.Orient);
}


