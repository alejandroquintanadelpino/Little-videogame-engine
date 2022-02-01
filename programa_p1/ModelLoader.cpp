#include "ModelLoader.h"

void ModelLoader::CalcBoundaries(Vector3D v) {
	this->maxX = fmax(this->maxX, v.GetX());
	this->maxY = fmax(this->maxY, v.GetY());
	this->maxZ = fmax(this->maxZ, v.GetZ());
	this->minX = fmin(this->minX, v.GetX());
	this->minY = fmin(this->minY, v.GetY());
	this->minZ = fmin(this->minZ, v.GetZ());
}

/**
Triangle ModelLoader::Center(Triangle t) {
	Vector3D centro(minX + GetWidth() / 2.0, minY + GetHeight() / 2.0, minZ + GetLength() / 2);
	Vector3D p0 = t.GetV1();
	Vector3D p1 = t.GetV2();
	Vector3D p2 = t.GetV3();
	return(Triangle(p0 - centro, p1 - centro, p2 - centro, Color(0.0, 0.0, 0.0), Color(0.0, 0.0, 0.0), Color(0.0, 0.0, 0.0)));
}
/**/

/**/
Triangle ModelLoader::Center(Triangle t) {
	Vector3D modelCenter(this->minX + this->GetWidth() / 2.0,
		this->minY + this->GetHeight() / 2.0,
		this->minZ + this->GetLength() / 2.0);
	
	Triangle centeredTriangle(
		t.GetV1() - modelCenter,
		t.GetV2() - modelCenter,
		t.GetV3() - modelCenter,
		t.GetN1(),
		t.GetN2(),
		t.GetN3());

	return centeredTriangle;
}
/**/

Vector3D ModelLoader::ParseObjLineToVector3D(const string& line) {
	/* 
	*  En el archivo obj, los vértices o las normales se define mediante
	*  las tres coordenadas de un vector. Este método convierte estas coordenadas
	*  a un objeto de la clase Vector3D
	*  el formato de un vértice en el obj es:
	*  v -0.091741 0.641907 0.606832
	*/

	string typeOfPoint;
	float xCoordinate, yCoordinate, zCoordinate;
	istringstream stringStream(line);
	stringStream >> typeOfPoint >> xCoordinate >> yCoordinate >> zCoordinate;
	Vector3D vectorPoint(xCoordinate, yCoordinate, zCoordinate);
	return vectorPoint * this->GetSize();
}
/**
Triangle ModelLoader::ParseObjTriangle(const string& line) {
	char c;
	size_t idx0Vertex, idx1Vertex, idx2Vertex;
	size_t idx0Normal, idx1Normal, idx2Normal;

	istringstream ss(line);
	// ejemplo face: f 4//1 1//1 2//1
	ss >> c >> idx0Vertex >> c >> c >> idx0Normal;
	ss >> idx1Vertex >> c >> c >> idx1Normal;
	ss >> idx2Vertex >> c >> c >> idx2Normal;
	Vector3D p0 = vertex[idx0Vertex - 1];
	Vector3D p1 = vertex[idx1Vertex - 1];
	Vector3D p2 = vertex[idx2Vertex - 1];
	Vector3D n = normals[idx0Normal - 1];
	Triangle result(p0, p1, p2, Color(0.0, 0.0, 0.0), Color(0.0, 0.0, 0.0), Color(0.0, 0.0, 0.0));
	result.SetN1(n);
	result.SetN2(n);
	result.SetN3(n);
	return result;
}
/**/

/**/
Triangle ModelLoader::ParseObjTriangle(const string& line) {
	/*
	*  En el archivo obj, las caras se definen a partir de los vértices y normales previos.
	*  Este método convierte esa información en un objeto de la clase Triangle.
	*  el formato de una cara (en este caso un triángulo) en el obj es:
	*  f 7//10 9//10 3//10
	*/
/**/
	char c; //caracter para leer lo que no nos interesa
	int idxVertex0, idxVertex1, idxVertex2;
	int idxNormal0, idxNormal1, idxNormal2;

	istringstream stringStream(line);
	stringStream >> c; //f
	stringStream >> idxVertex0 >> c >> c >> idxNormal0; // ejemplo: 7//10
	stringStream >> idxVertex1 >> c >> c >> idxNormal1;
	stringStream >> idxVertex2 >> c >> c >> idxNormal2;

	Vector3D vertex0 = this->vertex[idxVertex0 - 1];
	Vector3D vertex1 = this->vertex[idxVertex1 - 1];
	Vector3D vertex2 = this->vertex[idxVertex2 - 1];
	Vector3D normal = this->normals[idxNormal0 - 1]; // las tres normales son iguales

	Triangle parsedTriangle(vertex0, vertex1, vertex2, normal, normal, normal);

	return parsedTriangle;
}
/**/

void ModelLoader::LoadModel(const string& file) {
	try {
		ifstream objFile(file);
		if (objFile.is_open()) {
			string line;
			int count = 0;
			while (getline(objFile, line)) {
				if (line[0] == 'v' && line[1] == 'n') { //ejemplo: vn 0.0000 0.3603 -0.9328 => normal
					Vector3D normal = this->ParseObjLineToVector3D(line);
					this->normals.push_back(normal);
				}
				else if (line[0] == 'v') { // ejemplo: v -0.091741 0.641907 0.606832 => vértice
					Vector3D vertex = this->ParseObjLineToVector3D(line);
					this->CalcBoundaries(vertex);
					this->vertex.push_back(vertex);
				}
				else if(line[0] == 'f') { //ejemplo: f 2//4 5//4 6//4 => cara, triángulo
					Triangle triangle = this->ParseObjTriangle(line);
					this->model.AddTriangle(this->Center(triangle));
					//this->model.AddTriangle(triangle);
				}
			}
			objFile.close();
		}
		else {
			cout << "No se ha podido abrir el archivo: " << file << endl;
		}
	}
	catch (exception& ex) {
		cout << "Excepción al procesar el archivo: " << file << endl;
		cout << ex.what() << endl;
	}
}