// RobotState.cpp: определяет точку входа для приложения.
//

#include "RobotState.h"
#include "Robot.h"
#include <string>
#include <fstream>
#include <vector>
#include <regex>

using namespace std;

Robot RobotStart(vector<int> const& commands, int x0, int y0, int orient0) {

	
	Robot robot = Robot(x0, y0, orient0);

	for (int i = 0; i < commands.size(); i++){

		robot.Move(commands[i]);
	}

	return robot;
}

int ReadCommands(string filename, vector<int> &commands){

	std::ifstream f(filename);
	string current_line;

	

	while (getline(f, current_line))
	{
		static const auto r = regex(R"(\s)");
		current_line = regex_replace(current_line, r, "");
		if (current_line == "f"){

			commands.push_back(Command::forward);
			continue;
		}
		if (current_line == "b"){

			commands.push_back(Command::backward);
			continue;
		}
		if (current_line == "r"){

			commands.push_back(Command::turn_right);
			continue;
		}
		if (current_line == "l"){

			commands.push_back(Command::turn_left);
			continue;
		}
	}

	return 0;
	
}

int main(int argc, char* argv[])
{
	if (argc != 5) {
        cerr << "Wrong input arguments" << endl;
        return -1;
    }


	try{

		string filename = argv[1];
		int x_0 = stoi(argv[2]);
		int y_0 = stoi(argv[3]);
		int orient_0 = -1;
		
		static const auto r = regex(R"(\s)");

		string orient = regex_replace(argv[4], r, "");

		if (orient == "up"){

			orient_0 = Orient::up;
		}
		if (orient == "down"){

			orient_0 = Orient::down;
		}
		if (orient == "left"){
			orient_0 = Orient::left;
		}
		if (orient == "right"){

			orient_0 = Orient::right;
		}

		if (orient_0 == -1){

			cerr << "Wrong input arguments" << endl;
       		return -1;
		}

		vector<int> commands = vector<int>();

		Robot myRobot = Robot(x_0, y_0, orient_0);

		if (ReadCommands(filename, commands) != 0){

			cerr << "File error\n";
			return -1;
		}

		myRobot.Move(commands);

		cout << myRobot.ToString();
	}
	catch(...){

		cerr << "Wrong input arguments" << endl;
	}
	

}
