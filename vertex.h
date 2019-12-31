#pragma once

struct vertex {
	struct point* p;
	bool ear;
	struct vertex* next;
	struct vertex* prev;
};

struct vertex* vertex_new(float x, float y);
void vertex_free(struct vertex* v);
struct vertex* vertex_copy(struct vertex* v);
