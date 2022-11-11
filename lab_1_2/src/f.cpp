#include "f.h"

int edgeType(Point& a, Edge& e)
{
    Point v = e.P1;
    Point w = e.P2;
    switch (a.Position(e)) {
    case LEFT:
        return ((v.Y < a.Y) && (a.Y <= w.Y)) ? CROSSING : INESSENTIAL;
    case RIGHT:
        return ((w.Y < a.Y) && (a.Y <= v.Y)) ? CROSSING : INESSENTIAL;
    case BETWEEN:
    case ORIGIN:
    case DESTINATION:
        return TOUCHING;
    default:
        return INESSENTIAL;
    }
}

int isPInPoly(vector<Point> const& points, Point &p) {

    int parity = 0;
    for (int i = 0; i < points.size() - 1; i++) {
        
        Edge e = Edge(points[i], points[i + 1]);

        switch (edgeType(p, e)) {
        case TOUCHING:
            return BOUNDARY;
        case CROSSING:
            parity = 1 - parity;
        }
        //cout << parity;
    }

    Edge e = Edge(points[points.size() - 1], points[0]);

    switch (edgeType(p, e)) {
    case TOUCHING:
        return BOUNDARY;
    case CROSSING:
        parity = 1 - parity;
    }

    //cout << parity;

    switch (parity)
    {
    case 1:
        return INSIDE;
        break;
    case 0:
        return OUTSIDE;
    }
}