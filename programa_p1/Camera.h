#pragma once
#include "Solid.h"

using namespace std;

class Camera : public Solid
{
public:
	Camera(Vector3D p = Vector3D()) : Solid() { SetPos(p); }

	void Render();
};

