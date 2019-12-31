#include <stdbool.h>
#include <stdlib.h>
#include "point.h"

struct point* point_new(float x, float y) {
	struct point* p = malloc(sizeof(struct point));
	p->x = x;
	p->y = y;
	return p;
}

void point_free(struct point* p) {
	free(p);
}

struct point* point_copy(struct point* p) {
	struct point* copy = malloc(sizeof(*p));
	copy->x = p->x;
	copy->y = p->y;
	return copy;
}

float area(struct point* a, struct point* b, struct point* c) {
	float det = (b->x - a->x) * (c->y - a->y) - (c->x - a->x) * (b->y - a->y);
	return det / 2;
}

bool left(struct point* a, struct point* b, struct point* c) {
	return area(a, b, c) > 0;
}

bool left_on(struct point* a, struct point* b, struct point* c) {
	return area(a, b, c) >= 0;
}

bool right(struct point* a, struct point* b, struct point* c) {
	return area(a, b, c) < 0;
}

bool right_on(struct point* a, struct point* b, struct point* c) {
	return area(a, b, c) >= 0;
}

bool collinear(struct point* a, struct point* b, struct point* c) {
	return area(a, b, c) == 0;
}

bool intersect_proper(struct point* a, struct point* b, struct point* c, struct point* d) {
	if (collinear(a, b, c) || collinear(a, b, d) || collinear(c, d, a) || collinear(c, d, b)) {
		return false;
	}
	return left(a, b, c) != left(a, b, d) && left(c, d, a) != left(c, d, a);
}

bool between(struct point* a, struct point* b, struct point* c) {
	if (!collinear(a, b, c)) {
		return false;
	}
	
	if (a->x != b->x) {
		return ((a->x <= c->x) * (c->x <= b->x) || (a->x >= c->x) * (c->x >= b->x));
	}
	else {
		return ((a->y <= c->y) * (c->y <= b->y) || (a->y >= c->y) * (c->y >= b->y));	
	}
}

bool intersect(struct point* a, struct point* b, struct point* c, struct point* d) {
	return intersect_proper(a, b, c, d) || between(a, b, c) || between(a, b, d) || between(c, d, a) || between(c, d, b);
}
