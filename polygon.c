#include <stdbool.h>
#include "point.h"
#include "polygon.h"

float polygon_area(struct vertex* polygon) {
	double sum = 0;
	struct vertex* a = polygon->next;
	
	do {
		sum += area(polygon->p, a->p, a->next->p);
		a = a->next;
	} while (a->next != polygon);
	
	return sum;
}

bool diagonal_ie(struct vertex* polygon, struct vertex* a, struct vertex* b) {
	struct vertex* c = polygon;
	struct vertex* d;
	
	do {
		d = c->next;
		if ((c != a) && (c != b) && (d != a) && (d != b) && intersect(a->p, b->p, c->p, d->p)) {
			return false;
		}
		c = c->next;
	} while (c != polygon);
	
	return true;
}

bool in_cone(struct vertex* a, struct vertex* b) {
	struct vertex* a1 = a->next;
	struct vertex* a0 = a->prev;
	
	if (LeftOn(a->p, a1->p, a0->p)) {
		return Left(a->p, b->p, a0->p) && Left(b->p, a->p, a1->p);
	}
	return Right(a->p, b->p, a1->p) && Right(b->p, a->p, a0->p);
}

bool diagonal(struct vertex* polygon, struct vertex* a, struct vertex* b) {
	return in_cone(a, b) && in_cone(b, a) && diagonal_ie(polygon, a, b);
}
