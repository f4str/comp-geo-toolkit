#pragma once
#include <stdbool.h>
#include "vertex.h"

struct polygon {
	struct vertex* start;
	int vertices;
};

struct polygon* polygon_new(struct vertex* v);
void polygon_free(struct polygon* poly);
struct polygon* polygon_copy(struct polygon* poly);
float polygon_area(struct polygon* poly);
bool diagonal_ie(struct polygon* poly, struct vertex* a, struct vertex* b);
bool in_cone(struct vertex* a, struct vertex* b);
bool diagonal(struct polygon* poly, struct vertex* a, struct vertex* b);
void ear_init(struct polygon* poly);
