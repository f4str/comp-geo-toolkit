#include <stdlib.h>
#include "polygon.h"

struct polygon* polygon_new(struct vertex* v) {
	struct polygon* poly = malloc(sizeof(struct polygon));
	poly->vertices = v;
	poly->vertices = 1;
	return poly;
}

void polygon_free(struct polygon* poly) {
	struct vertex* v = poly->start;
	struct vertex* prev;
	
	do {
		prev = v;
		v = v->next;
		vertex_free(prev);
	} while (v != poly->start);
	
	free(poly);
}

struct polygon* polygon_copy(struct polygon* poly) {
	struct polygon* copy = malloc(sizeof(*poly));
	struct vertex *v1, *v2, *prev;
	
	copy->vertices = poly->vertices;
	do {
		v1 = vertex_copy(v2);
		v1->prev = prev;
		prev->next = v1;
		prev = v1;
		v2 = v2->next;
	} while (v1 != poly->start);
	
	return copy;
}

float polygon_area(struct polygon* poly) {
	double sum = 0;
	struct vertex* a = poly->start->next;
	
	do {
		sum += area(poly->start->p, a->p, a->next->p);
		a = a->next;
	} while (a->next != poly->start);
	
	return sum;
}

bool diagonal_ie(struct polygon* poly, struct vertex* a, struct vertex* b) {
	struct vertex* c = poly->start;
	struct vertex* d;
	
	do {
		d = c->next;
		if ((c != a) && (c != b) && (d != a) && (d != b) && intersect(a->p, b->p, c->p, d->p)) {
			return false;
		}
		c = c->next;
	} while (c != poly->start);
	
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

bool diagonal(struct polygon* poly, struct vertex* a, struct vertex* b) {
	return in_cone(a, b) && in_cone(b, a) && diagonal_ie(poly, a, b);
}

void ear_init(struct polygon* poly) {
	struct vertex* v1 = poly->start;
	struct vertex *v0, *v2;
	
	do {
		v2 = v1->next;
		v0 = v1->prev;
		v1->ear = diagonal(poly->start, v0, v2);
		v1 = v1->next;
	} while (v1 != poly->start);
}
