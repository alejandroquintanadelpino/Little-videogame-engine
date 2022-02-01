#include "Junk.h"

Junk* Junk::Clone()
{
    return new Junk(*this);
}

//void Junk::Render()
//{
//    glPushMatrix();
//    glTranslated(this->GetPos().GetX(), this->GetPos().GetY(), this->GetPos().GetZ());
//    glRotated(this->GetRot().GetX(), 1, 0, 0);
//    glRotated(this->GetRot().GetY(), 0, 1, 0);
//    glRotated(this->GetRot().GetZ(), 0, 0, 1);
//    glColor3d(this->GetCol().GetRedComponent(), this->GetCol().GetGreenComponent(), this->GetCol().GetBlueComponent());
//    glutSolidCube(0.3f);
//    glPopMatrix();
//}

int Junk::GetContent()
{
    return this->content;
}

bool Junk::Collision(Solid* s)
{
	bool col = false;

	if (ColX(s) && ColY(s) && ColZ(s)) {
		this->SetPos(Vector3D(this->GetPos().GetX(), this->GetPos().GetY(), this->GetPos().GetZ() + 100));
		col = true;
	}
	return col;
}

bool Junk::ColX(Solid* s)
{
	bool result = false;
	if (s->GetPos().GetX() + s->GetSize() / 2 >= this->GetPos().GetX() && s->GetPos().GetX() - s->GetSize() / 2 <= this->GetPos().GetX()) {
		result = true;
	}
	return result;
}

bool Junk::ColY(Solid* s)
{
	bool result = false;
	if (s->GetPos().GetY() + s->GetSize() / 2 >= this->GetPos().GetY() && s->GetPos().GetY() - s->GetSize() / 2 <= this->GetPos().GetY()) {
		result = true;
	}
	return result;
}

bool Junk::ColZ(Solid* s)
{
	bool result = false;
	if (s->GetPos().GetZ() + s->GetSize() / 2 >= this->GetPos().GetZ() && s->GetPos().GetZ() - s->GetSize() / 2 <= this->GetPos().GetZ()) {
		result = true;
	}
	return result;
}