#include <stdlib.h>
#include "edge.h"

struct edge* edge_new(struct point* p1, struct point* p2) {
	struct edge* e = malloc(sizeof(struct edge));
	e->p1 = p1;
	e->p2 = p2;
}

void edge_free(struct edge* e) {
	free(e);
}
