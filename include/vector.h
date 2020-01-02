#pragma once
#include <stdbool.h>

static const int INITIAL_CAPACITY = 16;

struct vector {
	void** data;
	int size;
	int capacity;
};

struct vector* vector_new(void);
void vector_init(struct vector* v);
void vector_free(struct vector* v);
int vector_size(const struct vector* v);
int vector_capacity(const struct vector* v);
bool vector_empty(const struct vector* v);
void* vector_get(const struct vector* v, int index);
void vector_set(struct vector* v, int index, void* e);
bool vector_contains(const struct vector* v, void* e);
int vector_index(const struct vector* v, void* e);
void vector_add(struct vector* v, void* e);
void vector_insert(struct vector* v, int index, void* e);
void* vector_remove(struct vector* v, int index);
bool vector_erase(struct vector* v, void* e);
void vector_clear(struct vector* v);
