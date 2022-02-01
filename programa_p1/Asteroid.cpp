#include "Asteroid.h"

Asteroid* Asteroid::Clone()
{
	return new Asteroid(*this);
}

bool Asteroid::Collision(Solid* s)
{
	bool col = false;

	if (ColX(s) && ColY(s) && ColZ(s)) {
		this->SetPos(Vector3D(this->GetPos().GetX(), this->GetPos().GetY(), this->GetPos().GetZ() + 100));
		col = true;
	}
	return col;
}

bool Asteroid::ColX(Solid* s)
{
	bool result = false;
	if (s->GetPos().GetX() + s->GetSize() / 2 >= this->GetPos().GetX() && s->GetPos().GetX() - s->GetSize() / 2 <= this->GetPos().GetX()) {
		result = true;
	}
	return result;
}

bool Asteroid::ColY(Solid* s)
{
	bool result = false;
	if (s->GetPos().GetY() + s->GetSize() / 2 >= this->GetPos().GetY() && s->GetPos().GetY() - s->GetSize() / 2 <= this->GetPos().GetY()) {
		result = true;
	}
	return result;
}

bool Asteroid::ColZ(Solid* s)
{
	bool result = false;
	if (s->GetPos().GetZ() + s->GetSize() / 2 >= this->GetPos().GetZ() && s->GetPos().GetZ() - s->GetSize() / 2 <= this->GetPos().GetZ()) {
		result = true;
	}
	return result;
}
