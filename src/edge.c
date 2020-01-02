#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "vertex.h"
#include "edge.h"

struct edge* edge_new(struct vertex* v1, struct vertex* v2) {
	struct edge* e = malloc(sizeof(struct edge));
	e->v1 = v1;
	e->v2 = v2;
}

void edge_free(struct edge* e) {
	free(e);
}
