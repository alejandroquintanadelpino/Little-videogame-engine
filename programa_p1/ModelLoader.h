#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Model.h"
using namespace std;

class ModelLoader
{
private:
	float size;

	Model model;

	vector<Vector3D> vertex;
	vector<Vector3D> normals;

	float maxX, maxY, maxZ;
	float minX, minY, minZ;

	inline float GetWidth() { return maxX - minX; }
	inline float GetHeight() { return maxY - minY; }
	inline float GetLength() { return maxZ - minZ; }

	void CalcBoundaries(Vector3D v);
	Triangle Center(Triangle t);
	Vector3D ParseObjLineToVector3D(const string &line);
	Triangle ParseObjTriangle(const string& line);

public:
	ModelLoader(double s = 1.0) : size(s){}

	inline Model GetModel() { return model; }
	inline float GetSize() { return size; }

	inline void SetSize(float s) { size = s; }

	void LoadModel(const string& file);
	void Clear() { vertex.clear(); normals.clear(); model.Clear(); }
};

