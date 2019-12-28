#pragma once

struct Point {
	int x;
	int y;
};

int Area2(Point& a, Point& b, Point& c);
bool Left(Point& a, Point& b, Point& c);
bool LeftOn(Point& a, Point& b, Point& c);
bool Right(Point& a, Point& b, Point& c);
bool RightOn(Point& a, Point& b, Point& c);
bool Collinear(Point& a, Point& b, Point& c);
bool IntersectProp(Point& a, Point& b, Point& c, Point& d);
bool Between(Point& a, Point& b, Point& c);
bool Intersect(Point& a, Point& b, Point& c, Point& d);