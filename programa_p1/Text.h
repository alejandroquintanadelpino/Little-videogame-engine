#pragma once
#include <GL/glut.h>
#include <string>

#include "Solid.h"

using namespace std;

class Text : public Solid
{
	string text;

public:
	Text(string t = "Default text") : Solid(), text(t) {}
	Text(const Text& c) : Solid(c), text(c.text) {}
	Text* clone() { return new Text(*this); }
	inline string getText(string t) { text = t; }
	inline void setText(string t) { text = t; }
	void Render() {
		glPushMatrix();
		glColor3f(this->GetCol().GetRedComponent(), this->GetCol().GetGreenComponent(), this->GetCol().GetBlueComponent());
		glTranslatef(this->GetPos().GetX(), this->GetPos().GetY(), this->GetPos().GetZ());
		glRasterPos3d(0, 0, 0);
		for (char c : text)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
		glPopMatrix();
	}
};