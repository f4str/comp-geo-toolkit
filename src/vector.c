#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct vector* vector_new() {
	struct vector* v = malloc(sizeof(struct vector));
	v->size = 0;
	v->capacity = INITIAL_CAPACITY;
	v->data = malloc(INITIAL_CAPACITY * sizeof(void*));
	return v;
}

void vector_init(struct vector* v) {
	v->size = 0;
	v->capacity = INITIAL_CAPACITY;
	v->data = malloc(INITIAL_CAPACITY * sizeof(void*));
}

void vector_free(struct vector* v) {
	free(v->data);
	free(v);
}

int vector_size(const struct vector* v) {
	return v->size;
}

int vector_capacity(const struct vector* v) {
	return v->capacity;
}

bool vector_empty(const struct vector* v) {
	return v->size == 0;
}

void* vector_get(const struct vector* v, int index) {
	return v->data[index];
}

void vector_set(struct vector* v, int index, void* e) {
	v->data[index] = e;
}

bool vector_contains(const struct vector* v, void* e) {
	int i;
	for (i = 0; i < v->size; ++i) {
		if (v->data[i] == e) {
			return true;
		}
	}
	return false;
}

int vector_index(const struct vector* v, void* e) {
	int i;
	for (i = 0; i < v->size; ++i) {
		if (v->data[i] == e) {
			return i;
		}
	}
	return -1;
}

void vector_add(struct vector* v, void* e) {
	if (v->size == v->capacity) {
		v->data = realloc(v->data, v->capacity * 2);
		v->capacity *= 2;
	}
	
	v->data[v->size] = e;
	++v->size;
}

void vector_insert(struct vector* v, int index, void* e) {
	if (v->size == v->capacity) {
		v->data = realloc(v->data, v->capacity * 2);
		v->capacity *= 2;
	}
	
	++v->size;
	
	int i;
	for (i = v->size; i >= index; --i) {
		v->data[i] = v->data[i - 1];
	}
	v->data[index] = e;
}

void* vector_remove(struct vector* v, int index) {
	void* temp = v->data[index];
	--v->size;
	
	int i;
	for (i = index; i < v->size; ++i) {
		v->data[i] = v->data[i + 1];
	}
	return temp;
}

bool vector_erase(struct vector* v, void* e) {
	int i = vector_index(v, e);
	if (i >= 0) {
		vector_remove(v, i);
		return true;
	}
	return false;
}

void vector_clear(struct vector* v) {
	free(v->data);
	v->size = 0;
	v->capacity = INITIAL_CAPACITY;
	v->data = malloc(INITIAL_CAPACITY * sizeof(void*));
}
