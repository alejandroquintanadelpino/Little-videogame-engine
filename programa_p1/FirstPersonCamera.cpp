#include "FirstPersonCamera.h"

void FirstPersonCamera::Render() {
	glRotatef(this->GetRot().GetX(), 1, 0, 0);
	glRotatef(this->GetRot().GetY(), 0, 1, 0);
	glRotatef(this->GetRot().GetZ(), 0, 0, 1);
	glTranslatef(-1 * this->GetPos().GetX(), -1 * this->GetPos().GetY(), -1 * this->GetPos().GetZ());
}

void FirstPersonCamera::Update(const double& time) {
	this->SetSpeed(this->calcSpeedVector());
	Camera::Update(time);
}

Vector3D FirstPersonCamera::calcSpeedVector() {
	float yOrientation = degToRad(this->GetRot().GetY());
	float xOrientation = degToRad(this->GetRot().GetX());

	//Flying camera
	float xComponent = sin(yOrientation) * cos(xOrientation);
	float yComponent = -sin(xOrientation);
	float zComponent = -cos(yOrientation) * cos(xOrientation);

	//Walking camera
	//float xComponent = sin(yOrientation);
	//float yComponent = 0;
	//float zComponent = -cos(yOrientation);

	Vector3D speedVector = { xComponent, yComponent, zComponent };
	return speedVector;
}

void FirstPersonCamera::ProcessKeyPressed(unsigned char key, int px, int py) {
	switch (key) {
	case 'w':
	case 'W':
		this->Update(this->cameraStep);
		break;
	case 's':
	case 'S':
		this->Update(-1 * this->cameraStep);
		break;
	}
}

void FirstPersonCamera::ProcessMouseMovement(int x, int y) {
	if (this->GetMouseX() >= 0 && this->GetMouseY() >= 0) {
		Vector3D orientation = this->GetRot() + Vector3D(y - this->GetMouseY(), x - this->GetMouseX(), 0);
		this->SetRot(orientation);
	}
	this->SetMouseX(x);
	this->SetMouseY(y);
}