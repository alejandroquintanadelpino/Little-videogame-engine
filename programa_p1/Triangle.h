#pragma once
#include "Solid.h"

class Triangle : public Solid
{
private:
	Vector3D vertex1, vertex2, vertex3;
	Vector3D n1, n2, n3;
	Color c1, c2, c3;

public:
	/**
	Triangle(Vector3D v1, Vector3D v2, Vector3D v3, Color c1, Color c2, Color c3) :
		Solid(), vertex1(v1), vertex2(v2), vertex3(v3), c1(c1), c2(c2), c3(c3) {
		Vector3D v21 = v2 - v1;
		Vector3D v32 = v3 - v2;
		Vector3D normal = v21.Cross(v32);
		n1 = n2 = n3 = normal.Normalize();
	}
	/**/
	/**/
	Triangle(Vector3D v1, Vector3D v2, Vector3D v3, Vector3D n1, Vector3D n2, Vector3D n3) :
		Solid(), vertex1(v1), vertex2(v2), vertex3(v3), n1(n1), n2(n2), n3(n3) {
		c1 = c2 = c3 = Color(0.0, 0.0, 0.0);
	}
	/**/

	inline Vector3D GetV1() { return vertex1; }
	inline Vector3D GetV2() { return vertex2; }
	inline Vector3D GetV3() { return vertex3; }
	inline Vector3D GetN1() { return n1; }
	inline Vector3D GetN2() { return n2; }
	inline Vector3D GetN3() { return n3; }
	inline Color GetC1() { return c1; }
	inline Color GetC2() { return c2; }
	inline Color GetC3() { return c3; }

	inline void SetV1(Vector3D v) { vertex1 = v; }
	inline void SetV2(Vector3D v) { vertex2 = v; }
	inline void SetV3(Vector3D v) { vertex3 = v; }
	inline void SetN1(Vector3D n) { n1 = n; }
	inline void SetN2(Vector3D n) { n2 = n; }
	inline void SetN3(Vector3D n) { n3 = n; }
	inline void SetC1(Color c) { c1 = c; }
	inline void SetC2(Color c) { c2 = c; }
	inline void SetC3(Color c) { c3 = c; }
	void Render();
};

