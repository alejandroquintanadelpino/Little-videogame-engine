#pragma once
#include "Model.h"

class Asteroid : public Model
{
public:
	Asteroid(double d = 1.0, Vector3D p = Vector3D(), Color c = Color(1.0, 0.0, 0.0)) : Model(d, p, c){}
	Asteroid* Clone();
	bool Collision(Solid* s);
	bool ColX(Solid* s);
	bool ColY(Solid* s);
	bool ColZ(Solid* s);
};

