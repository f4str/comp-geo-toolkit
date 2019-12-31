#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "point.h"
#include "vertex.h"

struct vertex* vertex_new(float x, float y) {
	struct vertex* v = malloc(sizeof(struct vertex));
	v->p = point_new(x, y);
	v->ear = false;
	v->next = NULL;
	v->prev = NULL;
	return v;
}

void vertex_free(struct vertex* v) {
	point_free(v->p);
	free(v);
}

struct vertex* vertex_copy(struct vertex* v) {
	struct vertex* copy = malloc(sizeof(*v));
	copy->ear = v->ear;
	copy->p = point_copy(copy->p);
	copy->next = NULL;
	copy->prev = NULL;
	return copy;
}
