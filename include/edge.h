#pragma once

struct edge {
	struct point* p1;
	struct point* p2;
};

struct edge* edge_new(struct point* p1, struct point* p2);
void edge_free(struct edge* e);
