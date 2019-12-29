#pragma once

struct Vertex {
	Point* point;
	bool ear;
	Vertex* next;
	Vertex* prev;
	Vertex(Point* p) : point(p), ear(false), next(nullptr), prev(nullptr) {}
	~Vertex();
};

class Polygon {
	private:
		Vertex* start;
	public:
		Polygon(Vertex* v) : start(v) {}
		~Polygon();
		Vertex* StartVertex();
		double PolygonArea();
		bool DiagonalInteriorExterior(Vertex* a, Vertex* b);
		bool InCone(Vertex* a, Vertex* b);
		bool Diagonal(Vertex* a, Vertex* b);
};
