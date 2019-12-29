#pragma once

struct point {
	float x;
	float y;
};

float area(struct point*, struct point*, struct point*);
bool left(struct point*, struct point*, struct point*);
bool left_on(struct point*, struct point*, struct point*);
bool right(struct point*, struct point*, struct point*);
bool right_on(struct point*, struct point*, struct point*);
bool collinear(struct point*, struct point*,struct  point*);
bool intersect_proper(struct point*, struct point*, struct point*, struct point*);
bool between(struct point*, struct point*, struct point*);
bool intersect(struct point*, struct point*, struct point*, struct point*);
