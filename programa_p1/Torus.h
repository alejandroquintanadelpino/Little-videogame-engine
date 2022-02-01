#pragma once
#include "Solid.h"

class Torus : public Solid
{
private:
	float internalRadius;
	float externalRadius;
	int faces;
	int rings;

public:
	Torus(double d, Vector3D p = Vector3D(0.0, 4.0, 0.0), Color c = Color(0.2, 0.7, 0.8), Vector3D r = Vector3D(20.0, 0.0, 0.0))
		: Solid(d, p, c, r), internalRadius(0.2), externalRadius(0.3), faces(8), rings(6) {}

	inline float GetInternalRadius() const { return this->internalRadius; }
	inline float GetExternalRadius() const { return this->externalRadius; }
	inline int GetFaces() const { return this->faces; }
	inline int GetRings() const { return this->rings; }

	inline void SetInternalRadius(const float& internalRadiusToSet) { this->internalRadius = internalRadiusToSet; }
	inline void SetExternalRadius(const float& externalRadiusToSet) { this->externalRadius = externalRadiusToSet; }
	inline void SetFaces(const int& facesToSet) { this->faces = facesToSet; }
	inline void SetRings(const int& ringsToSet) { this->rings = ringsToSet; }

	void Render();
};

