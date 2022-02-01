#pragma once
#include <GL/glut.h>
#include "Solid.h"
#include "Vector3D.h"
#include "Color.h"

class Sphere : public Solid
{
private:
	float radius;
	int slices;
	int slacks;

public:
	Sphere(double d = 1.0, Vector3D p = Vector3D(4.0, 2.0, 1.0), Color c = Color(0.90, 0.0, 0.90), Vector3D r = Vector3D(191.0, 51.0, 321.0))
		: Solid(d, p, c, r), radius(0.5), slices(20), slacks(15) {}

	inline float GetRadius() const { return this->radius; }
	inline int GetSlices() const { return this->slices; }
	inline int GetSlacks() const { return this->slacks; }

	inline void SetRadius(const float& radiusToSet) { this->radius = radiusToSet; }
	inline void SetSlices(const int& slicesToSet) { this->slices = slicesToSet; }
	inline void SetSlacks(const int& slacksToSet) { this->slacks = slacksToSet; }

	void Render();
};

