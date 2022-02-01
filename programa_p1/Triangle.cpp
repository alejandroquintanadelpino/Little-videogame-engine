#include "Triangle.h"

void Triangle::Render() {
	glBegin(GL_TRIANGLES);
	//vértice 1
	glColor3f(c1.GetRedComponent(), c1.GetGreenComponent(), c1.GetBlueComponent());
	glNormal3f(n1.GetX(), n1.GetY(), n1.GetZ());
	glVertex3f(vertex1.GetX(), vertex1.GetY(), vertex1.GetZ());
	//vértice 2
	glColor3f(c2.GetRedComponent(), c2.GetGreenComponent(), c2.GetBlueComponent());
	glNormal3f(n2.GetX(), n2.GetY(), n2.GetZ());
	glVertex3f(vertex2.GetX(), vertex2.GetY(), vertex2.GetZ());
	//vértice 3
	glColor3f(c3.GetRedComponent(), c3.GetGreenComponent(), c3.GetBlueComponent());
	glNormal3f(n3.GetX(), n3.GetY(), n3.GetZ());
	glVertex3f(vertex3.GetX(), vertex3.GetY(), vertex3.GetZ());
	glEnd();

}