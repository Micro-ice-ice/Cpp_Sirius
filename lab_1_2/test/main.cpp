#include <gtest/gtest.h>
#include "../src/Point.h"
#include "../src/Edge.h"
#include <vector>
#include "../src/f.h"


using namespace std;

TEST(TestGroupName, Subtest_1){

    vector<Point> points = vector<Point>();

    Point p1 = Point(1, 2);
    points.push_back(p1);
    Point p2 = Point(2, 3);
    points.push_back(p2); 
    Point p3 = Point(3, 2);
    points.push_back(p3);
    Point p4 = Point(2, 1);
    points.push_back(p4);

    Point p = Point(0, 0);

    ASSERT_TRUE(isPInPoly(points, p) == Position_P_Poligon::OUTSIDE); 
}

TEST(TestGroupName, Subtest_2){

    vector<Point> points = vector<Point>();

    Point p1 = Point(1, 2);
    points.push_back(p1);
    Point p2 = Point(2, 3);
    points.push_back(p2); 
    Point p3 = Point(3, 2);
    points.push_back(p3);
    Point p4 = Point(2, 1);
    points.push_back(p4);

    Point p = Point(0, 1);

    ASSERT_TRUE(isPInPoly(points, p) == Position_P_Poligon::OUTSIDE); 
}

TEST(TestGroupName, Subtest_3){

    vector<Point> points = vector<Point>();

    Point p1 = Point(1, 2);
    points.push_back(p1);
    Point p2 = Point(2, 3);
    points.push_back(p2); 
    Point p3 = Point(3, 2);
    points.push_back(p3);
    Point p4 = Point(2, 1);
    points.push_back(p4);

    Point p = Point(0, 2);

    ASSERT_TRUE(isPInPoly(points, p) == Position_P_Poligon::OUTSIDE); 

}


TEST(TestGroupName, Subtest_4){

    vector<Point> points = vector<Point>();

    Point p1 = Point(1, 2);
    points.push_back(p1);
    Point p2 = Point(2, 3);
    points.push_back(p2); 
    Point p3 = Point(3, 2);
    points.push_back(p3);
    Point p4 = Point(2, 1);
    points.push_back(p4);

    Point p = Point(2, 2);

    ASSERT_TRUE(isPInPoly(points, p) == Position_P_Poligon::INSIDE); 

}


TEST(TestGroupName, Subtest_5){

    vector<Point> points = vector<Point>();

    Point p1 = Point(1, 2);
    points.push_back(p1);
    Point p2 = Point(2, 3);
    points.push_back(p2); 
    Point p3 = Point(3, 2);
    points.push_back(p3);
    Point p4 = Point(2, 1);
    points.push_back(p4);

    Point p = Point(2, 1.5);

    ASSERT_TRUE(isPInPoly(points, p) == Position_P_Poligon::INSIDE); 

}


TEST(TestGroupName, Subtest_6){

    vector<Point> points = vector<Point>();

    Point p1 = Point(1, 2);
    points.push_back(p1);
    Point p2 = Point(2, 3);
    points.push_back(p2); 
    Point p3 = Point(3, 2);
    points.push_back(p3);
    Point p4 = Point(2, 1);
    points.push_back(p4);

    Point p = Point(3, 2);

    ASSERT_TRUE(isPInPoly(points, p) == Position_P_Poligon::BOUNDARY); 

}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}