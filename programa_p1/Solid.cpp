#include "Solid.h"

void Solid::Render() {
	glPushMatrix();
	glTranslated(GetPos().GetX(), GetPos().GetY(), GetPos().GetZ());
	glColor3d(GetCol().GetRedComponent(), GetCol().GetGreenComponent(), GetCol().GetBlueComponent());
	glRotatef(this->GetRot().GetX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetRot().GetY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetRot().GetZ(), 0.0, 0.0, 1.0);
	glPopMatrix();
}

void Solid::Update(const float& time) {
	this->SetRot(Vector3D(this->GetRot() + this->GetOrSpeed() * time));
	this->SetPos(Vector3D(this->GetPos() + this->GetSpeed() * time));
}

bool Solid::Collision(Solid* s) {
	bool col = false;

	if (ColX(s) && ColY(s) && ColZ(s)) {
		this->SetPos(Vector3D(this->GetPos().GetX(), this->GetPos().GetY(), this->GetPos().GetZ() + 100));
		col = true;
	}
	return col;
}

bool Solid::ColX(Solid* s) {
	bool result = false;
	if (s->GetPos().GetX() + s->GetSize() / 2 >= this->GetPos().GetX() && s->GetPos().GetX() - s->GetSize() / 2 <= this->GetPos().GetX()) {
		result = true;
	}

	return result;
}

bool Solid::ColY(Solid* s) {
	bool result = false;
	if (s->GetPos().GetY() + s->GetSize() / 2 >= this->GetPos().GetY() && s->GetPos().GetY() - s->GetSize() / 2 <= this->GetPos().GetY()) {
		result = true;
	}

	return result;
}

bool Solid::ColZ(Solid* s) {
	bool result = false;
	if (s->GetPos().GetZ() + s->GetSize() / 2 >= this->GetPos().GetZ() && s->GetPos().GetZ() - s->GetSize() / 2 <= this->GetPos().GetZ()) {
		result = true;
	}

	return result;
}

int Solid::GetContent() {
	return 1;
}