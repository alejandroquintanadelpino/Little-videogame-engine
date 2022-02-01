#include "Model.h"

void Model::PaintColor(Color color) {
	for (Triangle& t : triangles) {
		t.SetC1(color);
		t.SetC2(color);
		t.SetC3(color);
	}
}

void Model::Render() {
	glPushMatrix();
	glTranslated(this->GetPos().GetX(), this->GetPos().GetY(), this->GetPos().GetZ());
	glRotated(this->GetRot().GetX(), 1, 0, 0);
	glRotated(this->GetRot().GetY(), 0, 1, 0);
	glRotated(this->GetRot().GetZ(), 0, 0, 1);
	for (Triangle& t : triangles)
		t.Render();
	glPopMatrix();
}

void Model::Update(double& dt) {
	Model::Update(dt);
	for (Triangle& t : triangles) {
		t.Update(dt);
	}
}