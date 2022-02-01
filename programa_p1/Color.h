#pragma once
#include <GL/glut.h>

class Color
{
private:
	float redComponent;
	float greenComponent;
	float blueComponent;

public:
	Color() : redComponent(0.0), greenComponent(1.0), blueComponent(0.0) {}
	Color(float red, float green, float blue) : redComponent(red), greenComponent(green), blueComponent(blue) {}

	inline float GetRedComponent() const { return this->redComponent; }
	inline float GetGreenComponent() const { return this->greenComponent; }
	inline float GetBlueComponent() const { return this->blueComponent; }

	inline void SetRedComponent(const float& redComponentToSet) { this->redComponent = redComponentToSet; }
	inline void SetGreenComponent(const float& greenComponentToSet) { this->greenComponent = greenComponentToSet; }
	inline void SetBlueComponent(const float& blueComponentToSet) { this->blueComponent = blueComponentToSet; }
};

