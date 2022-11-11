#pragma once

#include <iostream>
#include <vector>
#include "Point.h"
#include "Edge.h"

enum Contact_P_Edge { TOUCHING, CROSSING, INESSENTIAL };

enum Position_P_Poligon { INSIDE, OUTSIDE, BOUNDARY};

int edgeType(Point& a, Edge& e);

int isPInPoly(vector<Point> const& points, Point &p);