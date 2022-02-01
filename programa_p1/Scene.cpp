#include "Scene.h"

Scene* Scene::Clone() {
	return new Scene(*this);
}

void Scene::SetCamara(Vector3D c) {
	Camera* newCamera = new Camera(c);
	this->activeCamera = newCamera;
}

void Scene::Render() {
	//this->camera->Render();
	for (Solid* ps : gameObjects) {
		ps->Render();
	}
}

void Scene::Update(const float& dt) {
	//this->camera->Update(dt);
	for (Solid* ps : gameObjects) {
		ps->Update(dt);
		//this->CheckBoundary(ps);
	}
}

void Scene::CheckBoundary(Solid* ps) {
	if (ps->GetPos().GetX() > this->GetBoundary().GetX() || ps->GetPos().GetX() < 0) {
		//ps->SetSpeed(Vector3D(-ps->GetSpeed().GetX(), ps->GetSpeed().GetY(), ps->GetSpeed().GetZ()));
		//ps->SetPos(Vector3D(this->GetPos().GetX(), this->GetPos().GetY(), this->GetPos().GetZ() + 100));
	}

	if (ps->GetPos().GetY() > this->GetBoundary().GetY() || ps->GetPos().GetY() < 0) {
		//ps->SetSpeed(Vector3D(ps->GetSpeed().GetX(), -ps->GetSpeed().GetY(), ps->GetSpeed().GetZ()));
		//ps->SetPos(Vector3D(this->GetPos().GetX(), this->GetPos().GetY(), this->GetPos().GetZ() + 100));
	}

	if (ps->GetPos().GetZ() > this->GetBoundary().GetZ() || ps->GetPos().GetZ() < 0) {
		//ps->SetSpeed(Vector3D(ps->GetSpeed().GetX(), ps->GetSpeed().GetY(), -ps->GetSpeed().GetZ()));
		//ps->SetPos(Vector3D(this->GetPos().GetX(), this->GetPos().GetY(), this->GetPos().GetZ() + 100));
	}
}

void Scene::ProcessKeyPressed(unsigned char key, int x, int y) {
	/*cout << "Has pulsado la tecla: " << key << endl;*/
	switch (key) {
	case 'e':

		if (this->player->GetPos().GetX() <= 6) { //si no esta en el borde de la derecha (no me funciona la negación dentro del if por algún motivo desconocido)
			this->player->SetPos(Vector3D(this->player->GetPos().GetX() + 2.0, this->player->GetPos().GetY(), this->player->GetPos().GetZ())); //mueve a la derecha
		}
		break;
	case 'q':

		if (!this->player->GetPos().GetX() <= 0) {
			this->player->SetPos(Vector3D(this->player->GetPos().GetX() - 2, this->player->GetPos().GetY(), this->player->GetPos().GetZ()));
		}
		break;
	case 'f':
		activeCamera->SetPos(Vector3D(0, -3, 10));
		activeCamera->SetRot(Vector3D(-60, 0, 20));
		break;
	case 'g':
		activeCamera->SetPos(Vector3D(4, -3, 10));
		activeCamera->SetRot(Vector3D(-60, 0, 0));
		break;

	}
}

void Scene::ProcessMouseMovement(int x, int y) {
	//cout << "La posicion del raton es:" << x << "," << y << endl;
	//if (mx >= 0 && my >= 0) {
	//	Vector3D r = this->activeCamera->GetRot() + Vector3D(y - my, x - mx, 0) * 1;
	//	this->activeCamera->SetRot(r);
	//}
	//mx = x;
	//my = y;
}

void Scene::ProcessMouseClick(int button, int state, int x, int y) {
	//cout << "boton:" << button << " estado:" << state << " x:" << x << " y:" << y << endl;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mx = x;
		my = y;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		mx = 0;
		my = 0;
	}
}
