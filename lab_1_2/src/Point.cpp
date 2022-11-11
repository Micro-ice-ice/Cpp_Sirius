#include "Point.h"
#include "Edge.h"
#include <math.h>

Point::Point()
{
	X = 0;

	Y = 0;
}

Point::Point(double x, double y)
{
	X = x;

	Y = y;

}

double Point::Distance(Point const &p)
{
	return sqrt((p.X - X) * (p.X - X) + (p.Y - Y) * (p.Y - Y));
}

Point Point::operator+(Point const &p)
{
	return Point(X + p.X, Y + p.Y);
}

Point Point::operator-(Point const &p)
{
	return Point(X - p.X, Y - p.Y);
}

int Point::operator==(Point const &p)
{

	return (X == p.X) && (Y == p.Y);
}

double Point::operator*(Point const &p)
{
	return X * p.X + Y * p.Y;
}



int Point::Position(Edge e)
{

	return Position(e.P1, e.P2);
}

double Point::Length()
{
	return sqrt(X * X + Y * Y);
}

int Point::Position(Point &p1, Point &p2)
{
	Point p0 = *this;
	Point a = p2 - p1;
	Point b = p0 - p1;
	double sa = a.X * b.Y - b.X * a.Y;
	if (sa > 0.0)
		return LEFT;
	if (sa < 0.0)
		return RIGHT;
	if ((a.X * b.X < 0.0) || (a.Y * b.Y < 0.0))
		return BEHIND;
	if (a.Length() < b.Length())
		return BEYOND;
	if (p1 == p0)
		return ORIGIN;
	if (p2 == p0)
		return DESTINATION;
	return BETWEEN;
}
