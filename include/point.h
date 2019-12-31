#pragma once

struct point {
	float x;
	float y;
};

struct point* point_new(float x, float y);
void point_free(struct point* p);
struct point* point_copy(struct point* p);
float area(struct point* a, struct point* b, struct point* c);
bool left(struct point* a, struct point* b, struct point* c);
bool left_on(struct point* a, struct point* b, struct point* c);
bool right(struct point* a, struct point* b, struct point* c);
bool right_on(struct point* a, struct point* b, struct point* c);
bool collinear(struct point* a, struct point* b,struct point* c);
bool intersect_proper(struct point* a, struct point* b, struct point* c, struct point* d);
bool between(struct point* a, struct point* b, struct point* c);
bool intersect(struct point* a, struct point* b, struct point* c, struct point* d);
