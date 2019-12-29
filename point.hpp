#pragma once

struct Point {
	double x;
	double y;
	Point(double a, double b) : x(a), y(b) {};
};

double Area(Point* a, Point* b, Point* c);
bool Left(Point* a, Point* b, Point* c);
bool LeftOn(Point* a, Point* b, Point* c);
bool Right(Point* a, Point* b, Point* c);
bool RightOn(Point* a, Point* b, Point* c);
bool Collinear(Point* a, Point* b, Point* c);
bool IntersectProper(Point* a, Point* b, Point* c, Point* d);
bool Between(Point* a, Point* b, Point* c);
bool Intersect(Point* a, Point* b, Point* c, Point* d);
