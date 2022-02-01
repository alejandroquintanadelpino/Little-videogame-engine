#include "Camera.h"

void Camera::Render() {
	glTranslatef(-1 * this->GetPos().GetX(), -1 * this->GetPos().GetY(), -1 * this->GetPos().GetZ());
	glRotatef(this->GetRot().GetX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetRot().GetY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetRot().GetZ(), 0.0, 0.0, 1.0);
}