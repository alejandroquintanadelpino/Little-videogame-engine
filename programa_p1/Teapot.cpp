#include "Teapot.h"

void Teapot::Render() {
	glPushMatrix();
	glTranslatef(this->GetPos().GetX(), this->GetPos().GetY(), this->GetPos().GetZ());
	glColor3f(this->GetCol().GetRedComponent(), this->GetCol().GetGreenComponent(), this->GetCol().GetBlueComponent());
	glRotatef(this->GetRot().GetX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetRot().GetY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetRot().GetZ(), 0.0, 0.0, 1.0);
	glutSolidTeapot(this -> GetSize());
	glPopMatrix();
}