#pragma once
#include "point.h"
#include "vector.h"

struct vector* graham_scan_ch(struct point** points, int length);
struct vector* jarvis_march_ch(struct point** points, int length);
struct vector* divide_and_conquer_ch(struct point** points, int length);
struct vector* quickhull_ch(struct point** points, int length);
struct vector* quickhull_upper_ch(struct point** points, int length);
struct vector* quickhull_lower_ch(struct point** points, int length);
