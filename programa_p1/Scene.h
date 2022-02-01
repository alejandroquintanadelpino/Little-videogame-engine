#pragma once
#include "Solid.h"
#include "Camera.h"
#include <vector>
#include "Ship.h"
#include "Text.h"

using namespace std;

class Scene : public Solid
{
	vector<Solid*> gameObjects;
	Vector3D boundary;
	Camera* activeCamera;
	Ship* player;

	int MAX_FILAS;
	int MAX_COLUMNAS;
	double mx, my;

	vector<Solid*> asteroids;
	vector<Solid*> junks;

	Text* cargamento;

public:
	Scene() : boundary(Vector3D(80.0, 80.0, 80.0))
	{ 
		this->activeCamera = new Camera(Vector3D(4.0, -3.0, 10.0));
		Vector3D rot = Vector3D(-60.0, 0.0, 0.0);
		this->activeCamera->SetRot(rot);
		gameObjects.push_back(activeCamera);

		this->player = new Ship();

		this->MAX_FILAS = 5;
		this->MAX_COLUMNAS = 25;
	}

	inline Text* GetStringCargamento() { return this->cargamento; }
	inline int GetFilas() const { return this->MAX_FILAS; }
	inline int GetColumnas() const { return this->MAX_COLUMNAS; }
	inline Camera* GetCamara() { return this->activeCamera; }
	inline Ship* GetPlayer() { return this->player; }
	inline vector<Solid*> GetAsteroids() { return this->asteroids; }
	inline vector<Solid*> GetJunks() { return this->junks; }
	inline Vector3D GetBoundary() { return boundary; }
	vector<Solid*> GetSolids() { return gameObjects; }

	inline void SetStringCargamento(Text* t) { this->cargamento = t; }
	void SetCamara(Vector3D c);
	inline void SetPlayer(Ship* ship) { this->player = ship; }
	inline void SetBoundary(Vector3D b) { this->boundary = b; }

	inline void AddAsteroid(Solid* s) { this->asteroids.push_back(s); }
	inline void AddJunk(Solid* s) { this->junks.push_back(s); }
	inline void AddGameObject(Solid* solid) { this->gameObjects.push_back(solid); }

	void CheckBoundary(Solid* ps);
	void Render();
	void Update(const float& dt);

	void ProcessKeyPressed(unsigned char key, int x, int y);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
	Scene* Clone();
};

