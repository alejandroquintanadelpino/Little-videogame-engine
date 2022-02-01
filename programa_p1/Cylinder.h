#pragma once
#include "Solid.h"

class Cylinder : public Solid
{
private:
	float baseRadius;
	float topRadius;
	float height;
	int slices;
	int stacks;

public:
	Cylinder(double d, Vector3D p = Vector3D(1.0, 1.0, -2.0), Color c = Color(), Vector3D r = Vector3D(70.0, 20.0, 0.0))
		: Solid(d, p, c, r), baseRadius(0.2), topRadius(0.2), height(0.5), slices(8), stacks(6) {}

	inline float GetBaseRadius() const { return this->baseRadius; }
	inline float GetTopRadius() const { return this->topRadius; }
	inline float GetHeight() const { return this->height; }
	inline int GetSlices() const { return this->slices; }
	inline int GetStacks() const { return this->stacks; }

	inline void SetBaseRadius(const float& baseRadiusToSet) { this->baseRadius = baseRadiusToSet; }
	inline void SetTopRadius(const float& topRadiusToSet) { this->topRadius = topRadiusToSet; }
	inline void SetHeight(const float& heightToSet) { this->height = heightToSet; }
	inline void SetSlices(const int& slicesToSet) { this->slices = slicesToSet; }
	inline void SetStacks(const int& stacksToSet) { this->stacks = stacksToSet; }

	void Render();
};

