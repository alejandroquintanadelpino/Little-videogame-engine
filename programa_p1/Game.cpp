#include "Game.h"
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

inline double getRand(double min, double max) {
	static const int PRECISION = 10000;
	double n = max - min;
	int ir = rand() % PRECISION;
	double r = min + (double)ir / PRECISION * n;
	return r;
}

inline double getRand(double max = 1) { return getRand(0, max); }

vector<string> split0(string line) {
	string word;
	vector<string> words;
	istringstream ss(line);
	while (cin >> word) {
		words.push_back(word);
	}
	return words;
}

vector<string> split(string line, char delim = ' ') {
	string word;
	vector<string> words;
	istringstream ss(line);
	while (getline(ss, word, delim)) {
		words.push_back(word);
	}
	return words;
}

class ExceptionGame :public exception {
public:
	virtual const char* what() const throw() {
		return "Customized ExceptionGame error";
	}
};

void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
	switch (key)
	{
	case '1':
		if (this->scenes[0] != nullptr)
		{
			this->actualScene = this->scenes[0];
		}
		break;
	case '2':
		if (this->scenes[1] != nullptr)
		{
			this->actualScene = this->scenes[1];
		}
		break;
	}
	this->actualScene->ProcessKeyPressed(key, px, py);
}

void Game::ProcessMouseMovement(int x, int y) {
	this->actualScene->ProcessMouseMovement(x, y);
}

void Game::ProcessMouseClick(int button, int state, int x, int y) {
	this->actualScene->ProcessMouseClick(button, state, x, y);
}

void Game::Init() {
	srand(time(NULL)); //semilla 11 para probar los datos
	//(4,-3)
	string n;
	cout << "Introduce un nombre para la puntuacion:" << endl;
	cin >> n;
	ficheroPuntuaciones->SetName(n);

	Scene* mainScene = new(nothrow) Scene();
	Scene* winningScene = new (nothrow) Scene();
	Scene* lossingScene = new (nothrow) Scene();

	const int filas = 5;
	const int columnas = 25;
	const float velAvance = -0.5;

	Text* textCargamento = new Text("Cargamento: ");
	mainScene->SetStringCargamento(textCargamento);
	textCargamento->SetPos(Vector3D(7, 4, 2));
	mainScene->AddGameObject(textCargamento);

	Text* victoriaTexto = new Text("Victoria");
	victoriaTexto->SetPos(Vector3D(3, -5, 0));
	Text* derrotaTexto = new Text("Derrota :c");
	derrotaTexto->SetPos(Vector3D(3, -5, 0));

	winningScene->AddGameObject(victoriaTexto);
	lossingScene->AddGameObject(derrotaTexto);

	// prueba escena ingame
	int arrayEscena[filas][columnas];

	for (int i = 0; i < columnas; i++)
	{
		int contAsteroides = 0;
		int contChatarra = 0;
		for (int j = 0; j < filas; j++)
		{
			//calculamos si se generarán asteroides
			if (contAsteroides >= 3) {
				// no añadimos más
			}
			else {
				int random = rand() % 2;
				if (random == 0) { //cogemos el 0 como true para generar 
					arrayEscena[j][i] = 0; //el 0 en nuestro array representará los asteroides
					contAsteroides++;
					continue;
				}
			}
			//calculamos si se generará chatarra
			if (contChatarra >= 1) {
				//no añadimos más
			}
			else {
				int random = rand() % 10; //esta variable está sujeta a estudio de cuánta chatarra queremos generar. Podria estar ligada a dificultad?
				if (random == 0) {
					arrayEscena[j][i] = 1; // usamos el 1 como chatarra en nuestro array
					contChatarra++;
					continue;
				}
			}
			arrayEscena[j][i] = 2; // usamos el 2 como vacío en nuestro array
		}
	}
	//FIN metodo

	//metodo de pintar los elementos
	Asteroid* asteroidBase1 = new Asteroid();
	Asteroid* asteroidBase2 = new Asteroid();
	Asteroid* asteroidBase3 = new Asteroid();

	Junk* junkBase = new Junk();
	junkBase->SetSpeed(Vector3D(0, velAvance, 0));
	junkBase->SetCol(Color(1, 1, 1));
	junkBase->SetOrSpeed(Vector3D(0, 0, 10));

	Ship* shipModel = new Ship();
	mainScene->AddGameObject(shipModel);
	mainScene->SetPlayer(shipModel);

	ModelLoader lobj(0.15);
	ModelLoader lobj1(0.4);
	ModelLoader lobj2(0.4);
	ModelLoader lobj3(0.4);
	ModelLoader lobj4(0.8);

	//ModelMeshTriangles* shipModel = new ModelMeshTriangles();
	lobj.LoadModel("D:\\Mis cosas\\Universidad\\PA\\Practica_2\\programa_p2\\programa_p1\\models3d\\Spaceship3.obj");
	shipModel->SetSolids(lobj.GetModel().GetTriangles());
	shipModel->SetRot(Vector3D(-90, 0, 180)); //corregimos la rotación de la nave
	shipModel->PaintColor(Color(1.0, 0.4, 0.7));
	shipModel->SetSize(lobj.GetSize());
	
	//Cargamos los modelos de asteroides para luego randomizarlos
	lobj1.LoadModel("D:\\Mis cosas\\Universidad\\PA\\Practica_2\\programa_p2\\programa_p1\\models3d\\AsteroidPiedrecita.obj"); //
	asteroidBase1->SetSolids(lobj1.GetModel().GetTriangles());
	asteroidBase1->PaintColor(Color(0.0, 0.4, 0.7));
	asteroidBase1->SetSize(lobj1.GetSize());

	lobj2.LoadModel("D:\\Mis cosas\\Universidad\\PA\\Practica_2\\programa_p2\\programa_p1\\models3d\\Asteroide2.obj");
	asteroidBase2->SetSolids(lobj2.GetModel().GetTriangles());
	asteroidBase2->PaintColor(Color(0.1, 0.7, 0.2));
	asteroidBase2->SetSize(lobj2.GetSize());

	lobj3.LoadModel("D:\\Mis cosas\\Universidad\\PA\\Practica_2\\programa_p2\\programa_p1\\models3d\\Asteroide1.obj");
	asteroidBase3->SetSolids(lobj3.GetModel().GetTriangles());
	asteroidBase1->PaintColor(Color(0.6, 0.1, 0.4));
	asteroidBase3->SetSize(lobj3.GetSize());

	Asteroid* arrayAsteroids[3] = { asteroidBase1, asteroidBase2, asteroidBase3 };

	//Cargamos los modelos de la chatarra
	lobj4.LoadModel("D:\\Mis cosas\\Universidad\\PA\\Practica_2\\programa_p2\\programa_p1\\models3d\\GearCoin.obj");
	junkBase->SetSolids(lobj4.GetModel().GetTriangles());
	junkBase->PaintColor(Color(1.0, 0.0, 0.5));
	junkBase->SetSize(lobj4.GetSize());


	for (int i = 0; i < columnas; i++)
	{
		for (int j = 0; j < filas; j++)
		{
			int e = arrayEscena[j][i];
			switch (e)
			{
				case 0:
				{
					int r = rand() % 3;
					Asteroid* asteroidClone = arrayAsteroids[r]->Clone();
					asteroidClone->SetPos(Vector3D(j * 2, i * 2, 0));
					asteroidClone->SetSpeed(Vector3D(0, velAvance, 0));
					asteroidClone->SetCol(Color(1, 0, 0));
					mainScene->AddAsteroid(asteroidClone);
					mainScene->AddGameObject(asteroidClone);
				}
				break;

				case 1:
				{
					Junk* junkClone = junkBase->Clone();

					int c = rand() % 2 + 1;
					junkClone->SetContent(c);

					junkClone->SetPos(Vector3D(j * 2, i * 2, 0));
					mainScene->AddJunk(junkClone);
					mainScene->AddGameObject(junkClone);

				}
				break;

				case 2:
					// no se genera nada en la posición
					break;
				}
		}
	}

	for (Solid* ps : mainScene->GetAsteroids()) {
		cout << ps->GetPos().GetX();
		cout << ps->GetPos().GetY();
		cout << ps->GetPos().GetZ();
		cout << "...";

	}

	this->scenes.push_back(winningScene); //0
	this->scenes.push_back(mainScene);	//1
	this->scenes.push_back(lossingScene);//2
	this->actualScene = mainScene;

}

void Game::Init(const string& file)
{

	ifstream inputFileStream(file);
	json jsonInfo;
	if (inputFileStream.is_open() && inputFileStream.good())
	{
		inputFileStream >> jsonInfo;

		cout << jsonInfo << endl;

		for (int idx = 0; idx < jsonInfo.at("scenes").size(); idx++)
		{
			json currentScene = jsonInfo.at("scenes").at(idx);

			Scene* scene = new Scene();
			scene->SetBoundary(Vector3D(currentScene.at("size").at("x"), currentScene.at("size").at("y"), currentScene.at("size").at("z")));

			for (int idx2 = 0; idx2 < currentScene.at("objects").size(); idx2++)
			{
				json currentObject = currentScene.at("objects").at(idx2);
				if (currentObject.at("type") == "cube")
				{
					Cube* cube = new Cube();
					cube->SetPos(Vector3D(currentObject.at("position").at("x"), currentObject.at("position").at("y"), currentObject.at("position").at("z")));
					cube->SetSpeed(Vector3D(currentObject.at("speed").at("x"), currentObject.at("speed").at("y"), currentObject.at("speed").at("z")));
					cube->SetCol(Color(currentObject.at("color").at("x"), currentObject.at("color").at("y"), currentObject.at("color").at("z")));
					cube->SetRot(Vector3D(currentObject.at("rotation").at("x"), currentObject.at("rotation").at("y"), currentObject.at("rotation").at("z")));
					cube->SetOrSpeed(Vector3D(currentObject.at("rotationSpeed").at("x"), currentObject.at("rotationSpeed").at("y"), currentObject.at("rotationSpeed").at("z")));
					cube->SetSize(currentObject.at("size"));
					scene->AddGameObject(cube);
				}
				else if (currentObject.at("type") == "sphere")
				{
					Sphere* sphere = new Sphere();
					sphere->SetPos(Vector3D(currentObject.at("position").at("x"), currentObject.at("position").at("y"), currentObject.at("position").at("z")));
					sphere->SetSpeed(Vector3D(currentObject.at("speed").at("x"), currentObject.at("speed").at("y"), currentObject.at("speed").at("z")));
					sphere->SetCol(Color(currentObject.at("color").at("x"), currentObject.at("color").at("y"), currentObject.at("color").at("z")));
					scene->AddGameObject(sphere);
				}
				else if (currentObject.at("type") == "model")
				{
					ModelLoader lobj(currentObject.at("scale"));
					Model* model = new Model();
					lobj.LoadModel(currentObject.at("file"));
					*model = lobj.GetModel();
					model->SetPos(Vector3D(currentObject.at("position").at("x"), currentObject.at("position").at("y"), currentObject.at("position").at("z")));
					model->SetSpeed(Vector3D(currentObject.at("speed").at("x"), currentObject.at("speed").at("y"), currentObject.at("speed").at("z")));
					model->SetCol(Color(currentObject.at("color").at("x"), currentObject.at("color").at("y"), currentObject.at("color").at("z")));
					model->SetRot(Vector3D(currentObject.at("rotation").at("x"), currentObject.at("rotation").at("y"), currentObject.at("rotation").at("z")));
					model->SetOrSpeed(Vector3D(currentObject.at("rotationSpeed").at("x"), currentObject.at("rotationSpeed").at("y"), currentObject.at("rotationSpeed").at("z")));
					scene->AddGameObject(model);
				}
			}
			this->scenes.push_back(scene);
		}
		this->actualScene = this->scenes[0];
	}
	else
	{
		cout << "Error leyendo archivo: " << file << endl;
	}
}


/**
void Game::Init() {
	Scene* mainScene = new(nothrow) Scene();

	Camera* camera = new Camera(Vector3D(4.0, 3.0, 12.0));
	mainScene->AddGameObject(camera);
	
	Teapot* teapot = new Teapot();
teapot->SetOrSpeed(Vector3D(1.0, 0.0, 0.0));
teapot->SetSpeed(Vector3D(1.0, 0.0, 0.0));
mainScene->AddGameObject(teapot);
//this->gameObjects.push_back(teapot);

Cube* cube = new Cube();
cube->SetOrSpeed(Vector3D(0.0, 0.5, 0.0));
cube->SetSpeed(Vector3D(0.5, 0.0, 0.0));
mainScene->AddGameObject(cube);
//this->gameObjects.push_back(cube);

Sphere* sphere = new Sphere();
sphere->SetOrSpeed(Vector3D(0.0, 0.0, 1.0));
sphere->SetSpeed(Vector3D(1.0, 0.5, 0.2));
mainScene->AddGameObject(sphere);
//this->gameObjects.push_back(sphere);

Cuboid* cuboid = new Cuboid();
cuboid->SetOrSpeed(Vector3D(1.0, 0.0, 1.0));
cuboid->SetSpeed(Vector3D(1.0, 1.0, 0.0));
mainScene->AddGameObject(cuboid);
//this->gameObjects.push_back(cuboid);

Torus* torus = new Torus();
torus->SetOrSpeed(Vector3D(1.0, 1.0, 0.0));
torus->SetSpeed(Vector3D(0.6, 0.2, 1.0));
mainScene->AddGameObject(torus);
//this->gameObjects.push_back(torus);

Cylinder* cylinder = new Cylinder();
cylinder->SetOrSpeed(Vector3D(0.0, 1.0, 1.0));
cylinder->SetSpeed(Vector3D(0.0, 0.2, 0.0));
mainScene->AddGameObject(cylinder);
//this->gameObjects.push_back(cylinder);

ModelLoader* loader = new ModelLoader();
loader->SetSize(0.3f);

/////////////////////////////////MODELO CORAZON////////////////////////////////////////////

Model* heart = new Model();
loader->LoadModel("D:\\Mis cosas\\Universidad\\PA\\Practica_2\\programa_p2\\programa_p1\\models3d\\Heart.obj");
*heart = loader->GetModel();
heart->SetPos(Vector3D(1.0, 1.0, 3.0));
heart->SetRot(Vector3D(0.0, 90.0, 0.0));
heart->SetOrSpeed(Vector3D(0.0, 0.0, 0.0));
heart->SetSpeed(Vector3D(0.0, 0.0, 0.0));
heart->PaintColor(Color(0.5, 0.2, 0.8));
mainScene->AddGameObject(heart);
loader->Clear();

////////////////////////////////////MODELO ESTRELLA////////////////////////////////////////

Model* star = new Model();
loader->LoadModel("D:\\Mis cosas\\Universidad\\PA\\Practica_2\\programa_p2\\programa_p1\\models3d\\Star.obj");
*star = loader->GetModel();
star->SetPos(Vector3D(2.0, 4.0, 3.0));
star->SetRot(Vector3D(0.0, 0.0, 0.0));
star->SetOrSpeed(Vector3D(0.0, 0.0, 0.0));
star->SetSpeed(Vector3D(0.0, 0.0, 0.0));
star->PaintColor(Color(0.7, 0.6, 0.2));
mainScene->AddGameObject(star);
loader->Clear();

////////////////////////////////////MODELO NAVE//////////////////////////////////////////////

//this->player = new Model();
//loader->LoadModel("D:\\Mis cosas\\Universidad\\PA\\Practica_2\\programa_p2\\programa_p1\\models3d\\Spaceship3.obj");
//*player = loader->GetModel();
//player->SetPos(Vector3D(3.0, 3.0, 0.0));
//player->SetRot(Vector3D(90.0, 0.0, 0.0));
//player->SetOrSpeed(Vector3D(0.0, 0.0, 0.0));
//player->SetSpeed(Vector3D(0.0, 0.0, 0.0));
//player->PaintColor(Color(0.1, 1.0, 0.5));
//mainScene->AddGameObject(player);
//loader->Clear();
//
//this->scenes.push_back(mainScene);
//this->actualScene = mainScene;
}
/**/

void Game::Render() {
	this->actualScene->Render();
	/**
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects.at(i)->Render();
	}
	/**/

	//this->GetTeapot().Render();
	//this->GetCube().Render();
	//this->GetSphere().Render();
	//this->GetCuboid().Render();
	//this->GetTorus().Render();
	//this->GetCylinder().Render();
}

void Game::Update() {

	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD)
	{
		this->actualScene->Update(TIME_INCREMENT);
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}

	this->scenes[1]->GetStringCargamento()->setText("Cargamento: " + to_string(actualScene->GetPlayer()->GetCargo())); //actualizamos el texto con el cargamento

	if (GetLastSolid()->GetPos().GetY() < -10) { //-10 es la posición en y que mejor queda con las posicions de camara, pero es un poco irrelevante

		if (this->scenes[0] != nullptr)
			this->actualScene = this->scenes[0];

		GetLastSolid()->SetPos(Vector3D(GetLastSolid()->GetPos().GetX(), -9, GetLastSolid()->GetPos().GetZ()));

		cout << "VICTORIA :)" << endl << endl;
		this->ficheroPuntuaciones->SetPuntuacion(this->scenes[1]->GetPlayer()->GetCargo() * 100 - this->scenes[1]->GetPlayer()->GetHits() * 30);
		this->ficheroPuntuaciones->ReadPuntuacion();
		this->ficheroPuntuaciones->WriteFile();
		this->ficheroPuntuaciones->SetPuntuacion(0);
		this->ficheroPuntuaciones->ReadFile();
	}
	//si colisionan asteroides
	for (Solid* s : this->scenes[1]->GetAsteroids()) {

		if (s->Collision(this->scenes[1]->GetPlayer()->Me())) {
			cout << "colisionandoa";
			this->scenes[1]->GetPlayer()->SubstractCargo();
			this->scenes[1]->GetPlayer()->AddHit();
		}
	}
	//si colisionan chatarras
	for (Solid* s : this->scenes[1]->GetJunks()) {
		if (s->Collision(this->scenes[1]->GetPlayer()->Me())) {
			cout << "colisionandoc";
			this->scenes[1]->GetPlayer()->AddCargo(s->GetContent());
		}
	}

	if (this->scenes[1]->GetPlayer()->GetCargo() <= 0) {
		/*cout << "HAS PERDIDO!" << endl << endl;*/

		this->ficheroPuntuaciones->SetPuntuacion(this->scenes[1]->GetPlayer()->GetCargo() * 100);
		this->ficheroPuntuaciones->ReadPuntuacion();
		this->ficheroPuntuaciones->WriteFile();
		this->ficheroPuntuaciones->SetPuntuacion(0);
		this->ficheroPuntuaciones->ReadFile();

		this->scenes[1]->GetPlayer()->AddCargo(1);

		this->actualScene = this->scenes[2];
	}

}

/**
void Game::Update() {
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD){
		this->actualScene->Update(TIME_INCREMENT);
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}
}
/**/

Solid* Game::GetLastSolid() {
	vector<Solid*> solidCopias = this->scenes[1]->GetSolids();
	/*cout << solidCopias.back()->getPos().getY();*/
	return solidCopias.back();
}
