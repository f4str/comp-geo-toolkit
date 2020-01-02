#pragma once

struct edge {
	struct vertex* v1;
	struct vertex* v2;
};

struct edge* edge_new(struct vertex* v1, struct vertex* v2);
void edge_free(struct edge* e);
