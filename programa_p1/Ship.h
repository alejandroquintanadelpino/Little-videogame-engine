#pragma once
#include "Model.h"

class Ship : public Model
{
private:
	int cargo;
	int hits;

public:
	Ship(double d = 1.0, Vector3D p = Vector3D(4.0, -4.0, 0.0), Color c = Color(1.0, 1.0, 0.0)) : Model(d, p, c) {
		this->cargo = 3;
		this->hits = 0;
	}

	inline int GetCargo() { return this->cargo; }
	inline void AddCargo(int cargamento) { this->cargo += cargamento; }
	inline void SubstractCargo() { this->cargo--; }
	inline void AddHit() { this->hits++; }
	inline int GetHits() { return this->hits; }
	inline Model* Me() { return (Model*)this; }
};

