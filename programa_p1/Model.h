#pragma once
#include <vector>
#include "triangle.h"
#include <stdexcept>
using namespace std;

class Model : public Solid
{
	vector<Triangle> triangles;

public:
	Model(double d, Vector3D p, Color c) : Solid(d, p, c){}
	Model() : Solid(){}

	Model* Clone() {
		return new Model(*this);
	}

	vector<Triangle> GetTriangles() { return triangles; }
	void SetSolids(vector<Triangle> vs) { triangles = vs; }

	Triangle getTriangle(int i) {
		if (i >= triangles.size() || i < 0)
			throw runtime_error("Out of range index, with value " + to_string(i) + " at ModelMeshTriangles::getTriangle()");
		return triangles[i];
	}
	
	Triangle operator[](int i) {
		if (i >= triangles.size() || i < 0)
			throw runtime_error("Out of range index, with value " + to_string(i) + " at ModelMeshTriangles::operator[]");
		return triangles[i];
	}

	void AddTriangle(Triangle t) { triangles.push_back(t); }
	void PaintColor(Color color);
	void Clear() { triangles.clear(); }
	void Render();
	void Update(double& dt);
};

