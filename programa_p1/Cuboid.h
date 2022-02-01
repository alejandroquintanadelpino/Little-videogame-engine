#pragma once
#include "Solid.h"

class Cuboid : public Solid
{
private:
	float length;
	float height;
	float width;

public:
	Cuboid(double d, Vector3D p = Vector3D(0.5, 1.0, -2.0), Color c = Color(0.0, 0.0, 0.97), Vector3D r = Vector3D(67.0, 90.0, 43.0)) 
		: Solid(d, p, c, r), length(0.2), height(0.3), width(0.1) {}

	inline float GetLength() const { return this->length; }
	inline float GetHeight() const { return this->height; }
	inline float GetWidth() const { return this->width; }

	inline void SetLength(const float& lengthToSet) { this->length = lengthToSet; }
	inline void SetHeight(const float& heightToSet) { this->height = heightToSet; }
	inline void SetWidth(const float& widthToSet) { this->width = widthToSet; }

	void Render();
};

