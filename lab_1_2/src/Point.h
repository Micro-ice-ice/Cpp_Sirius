#pragma once
//#include "Edge.h"

enum Position_P_Edge { LEFT, RIGHT, BEYOND, BEHIND, BETWEEN, ORIGIN, DESTINATION };

class Edge;

class Point
{
public:

	double X; //coord x

	double Y; //coord y

	Point();

	Point(double x, double y);

	double Distance(Point const &p);

	Point operator+ (Point const &p);

	Point operator- (Point const &p);

	int operator== (Point const &p);

	double operator* (Point const &p);

	int Position(Edge e);

	double Length();

	int Position(Point &p1, Point &p2);
};

