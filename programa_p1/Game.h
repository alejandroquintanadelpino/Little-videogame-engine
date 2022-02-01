#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <GL/glut.h>
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "Torus.h"
#include "Cylinder.h"
#include "Solid.h"
#include "Vector3D.h"
#include "Scene.h"
#include "Camera.h"
#include "ModelLoader.h"
#include <vector>
#include <chrono>
#include "Puntuacion.h"
#include "Asteroid.h"
#include "Junk.h"

using namespace std;
using namespace std::chrono;

class Game
{
private:
	const double TIME_INCREMENT = 0.07; //ms tiempo en el juego
	const long UPDATE_PERIOD = 10; //ms tiempo en el mundo real

	milliseconds initialMilliseconds;
	long lastUpdatedTime;

	Scene* actualScene = new Scene();
	vector<Scene*> scenes;

	Puntuacion* ficheroPuntuaciones;

	//vector<Solid*> gameObjects;

	//Teapot teapot;
	//Cube cube;
	//Sphere sphere;
	//Cuboid cuboid;
	//Torus torus;
	//Cylinder cylinder;

public:
	Game() : actualScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0), ficheroPuntuaciones(new (nothrow) Puntuacion()) {}

	//inline Teapot GetTeapot() { return this->teapot; }
	//inline Cube GetCube() { return this->cube; }
	//inline Sphere GetSphere() { return this->sphere; }
	//inline Cuboid GetCuboid() { return this->cuboid; }
	//inline Torus GetTorus() { return this->torus; }
	//inline Cylinder GetCylinder() { return this->cylinder; }

	void Init();
	void Init(const string& file);

	Solid* GetLastSolid();

	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
};

