#pragma once
#include <GL/glut.h>
#include "Solid.h"
#include "Vector3D.h"
#include "Color.h"

class Teapot : public Solid
{
private:
	//float coordinateX;
	//float coordinateY;
	//float coordinateZ;
	
	//float redComponent;
	//float greenComponent;
	//float blueComponent;

	float size;

	//Vector3D pos;
	//Vector3D orientation;
	//Color col;

public:
	Teapot(double d, Vector3D p = Vector3D(1.0, -1.0, -3.0), Color c = Color(0.0, 0.74, 0.20), Vector3D r = Vector3D(352.0, 96.0, 60.0)) 
		: Solid(d, p, c, r), size(0.4){}

	//inline float GetCoordinateX() const { return this->coordinateX; }
	//inline float GetCoordinateY() const { return this->coordinateY; }
	//inline float GetCoordinateZ() const { return this->coordinateZ; }
	//inline float GetRedComponent() const { return this->redComponent; }
	//inline float GetGreenComponent() const { return this->greenComponent; }
	//inline float GetBlueComponent() const { return this->blueComponent; }
	//inline Vector3D GetPos() { return pos; }
	//inline Vector3D GetRot() { return orientation; }
	//inline Color GetCol() { return col; }
	inline float GetSize() const { return this->size; }

	//inline void SetCoordinateX(const float& coordinateXToSet) { this->coordinateX = coordinateXToSet; }
	//inline void SetCoordinateY(const float& coordinateYToSet) { this->coordinateY = coordinateYToSet; }
	//inline void SetCoordinateZ(const float& coordinateZToSet) { this->coordinateZ = coordinateZToSet; }
	//inline void SetRedComponent(const float& redComponentToSet) { this->redComponent = redComponentToSet; }
	//inline void SetGreenComponent(const float& greenComponentToSet) { this->greenComponent = greenComponentToSet; }
	//inline void SetBlueComponent(const float& blueComponentToSet) { this->blueComponent = blueComponentToSet; }
	//inline void SetPos(Vector3D p) { pos = p;  }
	//inline void SetRot(Vector3D r) { orientation = r; }
	//inline void SetCol(Color c) { col = c; }
	inline void SetSize(const float& sizeToSet) { this->size = sizeToSet; }

	void Render();
};

