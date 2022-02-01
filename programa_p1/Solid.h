#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"
#include <vector>
#include <exception>
#include <string>

class Solid
{
private:
	Vector3D pos;
	Vector3D orientation;
	Vector3D orientationSpeed;
	Vector3D speed;
	Color col;
	double size;

public:
	Solid(double d = 1.0, Vector3D p = Vector3D(0.0, 0.0, 0.0), Color c = Color(), Vector3D r = Vector3D(), Vector3D os = Vector3D(), Vector3D s = Vector3D())
		: size(d), pos(p), col(c), orientation(r), orientationSpeed(os), speed(s) {}

	inline Vector3D GetPos() { return pos; }
	inline Vector3D GetRot() { return orientation; }
	inline Vector3D GetOrSpeed() { return orientationSpeed; }
	inline Vector3D GetSpeed() { return speed; }
	inline Color GetCol() { return col; }
	inline double GetSize() { return size; }

	inline void SetPos(Vector3D p) { pos = p; }
	inline void SetRot(Vector3D r) { orientation = r; }
	inline void SetOrSpeed(Vector3D os) { orientationSpeed = os; }
	inline void SetSpeed(Vector3D s) { speed = s; }
	inline void SetCol(Color c) { col = c; }
	inline void SetSize(double d) { size = d; }

	virtual void Render() = 0;
	virtual void Update(const float& dt);

	virtual bool Collision(Solid* s);
	virtual bool ColX(Solid* s);
	virtual bool ColY(Solid* s);
	virtual bool ColZ(Solid* s);

	virtual int GetContent();
};

