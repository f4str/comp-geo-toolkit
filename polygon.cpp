#include "point.hpp"
#include "polygon.hpp"

Vertex::~Vertex() {
	delete point;
	delete next;
	delete prev;
}

Polygon::~Polygon() {
	delete start;
}

Vertex* Polygon::StartVertex() {
	return start;
}

double Polygon::PolygonArea() {
	double sum = 0;
	Vertex* a = start->next;
	
	do {
		sum += Area(start->point, a->point, a->next->point);
		a = a->next;
	} while (a->next != start);
	
	return sum;
}

bool Polygon::DiagonalInteriorExterior(Vertex* a, Vertex* b) {
	Vertex* c = start;
	Vertex* d;
	
	do {
		d = c->next;
		if ((c != a) && (c != b) && (d != a) && (d != b) && Intersect(a->point, b->point, c->point, d->point)) {
			return false;
		}
		c = c->next;
	} while (c != start);
	
	return true;
}

bool Polygon::InCone(Vertex* a, Vertex* b) {
	Vertex* a1 = a->next;
	Vertex* a0 = a->prev;
	
	if (LeftOn(a->point, a1->point, a0->point)) {
		return Left(a->point, b->point, a0->point) && Left(b->point, a->point, a1->point);
	}
	return Right(a->point, b->point, a1->point) && Right(b->point, a->point, a0->point);
}

bool Polygon::Diagonal(Vertex* a, Vertex* b) {
	return InCone(a, b) && InCone(b, a) && DiagonalInteriorExterior(a, b);
}
