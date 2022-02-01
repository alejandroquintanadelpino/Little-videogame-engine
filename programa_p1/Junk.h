#pragma once
#include "Model.h"
class Junk : public Model
{
private:
	int content;

public:
	Junk(double d = 1.0, Vector3D p = Vector3D(), Color c = Color(1.0, 1.0, 1.0)) : Model(d, p, c) {
		this->content = rand() % 2 + 1;
	}
	Junk* Clone();
	//void Render();	
	int GetContent();
	inline void SetContent(int content) { this->content = content; }
	bool Collision(Solid* s);
	bool ColX(Solid* s);
	bool ColY(Solid* s);
	bool ColZ(Solid* s);
};

