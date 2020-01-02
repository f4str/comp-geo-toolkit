#include <stdbool.h>
#include "point.h"
#include "vertex.h"
#include "polygon.h"
#include "vector.h"
#include "edge.h"
#include "triangulation.h"

struct vector* ear_clipping_triangulation(struct polygon* poly) {
	struct vertex *v0, *v1, *v2, *v3, *v4;
	struct polygon* poly_copy = polygon_copy(poly);
	int n = poly->vertices;
	struct vector* v = vector_new();
	struct edge* e;
	
	ear_init(poly);
	while (n > 3) {
		v2 = poly_copy->start;
		do {
			// Search for ears
			if (v2->ear) {
				// Ear found
				v3 = v2->next;
				v4 = v3->next;
				v1 = v2->prev;
				v0 = v2->prev;
				
				// add edge (v1, v3) to vector
				e = edge_new(v1, v2);
				vector_add(v, e);
				
				// Update diagonal endpoints
				v1->ear = diagonal(poly, v0, v3);
				v3->ear = diagonal(poly, v1, v4);
				
				// Clip off ear v2
				v1->next = v3;
				v3->prev = v1;
				poly_copy->start = v3;
				--n;
				break;
			}
			v2 = v2->next;
		} while (v2 != poly_copy->start);
	}
	polygon_free(poly_copy);
	
	return v;
}
