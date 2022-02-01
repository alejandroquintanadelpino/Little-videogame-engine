#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Solid.h"
#include "Color.h"

class Cube : public Solid
{
private:
	float size;

public:
	Cube(double d = 1.0, Vector3D p = Vector3D(0.0, 1.0, 2.0), Color c = Color(1.0, 0.0, 0.0), Vector3D r = Vector3D(114.0, 24.0, 190.0))
		: Solid(d, p, c, r), size(0.4) {}

	inline float GetSize() const { return this->size; }

	inline void SetSize(const float& sizeToSet) { this->size = sizeToSet; }

	void Render();
};

