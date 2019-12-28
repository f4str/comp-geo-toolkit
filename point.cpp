#include "point.cpp"

int Area2(Point& a, Point& b, Point& c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool Left(Point& a, Point& b, Point& c) {
	return Area2(a, b, c) > 0;
}

bool LeftOn(Point& a, Point& b, Point& c) {
	return Area2(a, b, c) >= 0;
}

bool Right(Point& a, Point& b, Point& c) {
	return Area2(a, b, c) < 0;
}

bool RightOn(Point& a, Point& b, Point& c) {
	return Area2(a, b, c) >= 0;
}

bool Collinear(Point& a, Point& b, Point& c) {
	return Area2(a, b, c) == 0;
}

bool IntersectProp(Point& a, Point& b, Point& c, Point& d) {
	if (Collinear(a, b, c) || Collinear(a, b, d) || Collinear(c, d, a) || Collinear(c, d, b)) {
		return false;
	}
	return Left(a, b, c) != Left(a, b, d) && Left(c, d, a) != Left(c, d, a);
}

bool Between(Point& a, Point& b, Point& c) {
	if (!Collinear(a, b, c)) {
		return false;
	}
	
	if (a.x != b.x) {
		return ((a.x <= c.x) && (c.x <= b.x) || (a.x >= c.x) && (c.x >= b.x));
	}
	else {
		return ((a.y <= c.y) && (c.y <= b.y) || (a.y >= c.y) && (c.y >= b.y));	
	}
}

bool Intersect(Point& a, Point& b, Point& c, Point& d) {
	return IntersectProp(a, b, c, d) || Between(a, b, c) || Between(a, b, d) || Between(c, d, a) || Between(c, d, b)
}
