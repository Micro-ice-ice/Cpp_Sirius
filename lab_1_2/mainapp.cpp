#include <iostream>
#include <vector>
#include "src/Point.h"
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <sstream>
#include "src/f.h"

using namespace std;

int ReadPolygon (string filename, vector<Point> &points){

    std::ifstream f(filename);
	string current_line;

	while (getline(f, current_line)){

        try{

            std::istringstream input{current_line};
            string s ;
            input >> s;
            double x = stod(s);
            input >> s;
            double y = stod(s);

            Point p = Point(x, y);

            points.push_back(p);

        }
        catch(...){

            cerr << "File Error";
            return -1;
        }
    }

    if (points.size() < 3){

        cerr << "Polygon has to contain more than 2 points";
        return -1;
    }

    return 0;
}



int main(int argc, char* argv[])
{  

    if (argc != 4) {
        cerr << "Wrong input arguments" << endl;
        return -1;
    }

    try{

		string filename = argv[1];
		double x = stod(argv[2]);
		double y = stod(argv[3]);

        //cout << x << " " << y << endl;

        Point p = Point(x, y);

		vector<Point> points = vector<Point>();

		if (ReadPolygon(filename, points) != 0){

			cerr << "File error\n";
			return -1;
		}

        switch (isPInPoly(points, p))
        {
            case (INSIDE):

                cout << "INSIDE\n";

            break;
            case (OUTSIDE):

                cout << "OUTSIDE\n";

            break;
            case(BOUNDARY):

                cout << "BOUNDARY\n";
            break;
        }

        return 0;


	}
	catch(...){

		cerr << "Wrong input arguments" << endl;
        return -1;
	}
  
}
