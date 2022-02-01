#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Puntuacion
{
private:
	string name;
	int puntuacion;

public:
	Puntuacion() :name(""), puntuacion(0) {};
	inline void SetName(string n) { this->name = n; }
	inline string GetName() { return this->name; }
	inline void SetPuntuacion(int p) { this->puntuacion = p; }
	inline int GetPuntuacion() { return this->puntuacion; }
	void WriteFile();
	void ReadFile();
	void ReadPuntuacion();
};

