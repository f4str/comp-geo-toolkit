#pragma once

struct vertex {
	struct point* p;
	bool ear;
	struct vertex* next;
	struct vertex* prev;
};

float polygon_area(struct vertex*);
bool diagonal_ie(struct vertex*, struct vertex*, struct vertex*);
bool in_cone(struct vertex*, struct vertex*);
bool diagonal(struct vertex*, struct vertex*, struct vertex*);
