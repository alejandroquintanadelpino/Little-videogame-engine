#pragma once
#include <GL/glut.h>
template <class S> class Vector3Dx;

typedef Vector3Dx<float> Vector3D;

typedef Vector3Dx<float> Vector3Df;
typedef Vector3Dx<double> Vector3Dd;
typedef Vector3Dx<int> Vector3Di;


template <class S> class Vector3Dx
{
private:
	S x, y, z;

public:
	Vector3Dx(S x = 0, S y = 0, S z = 0) : x(x), y(y), z(z) {}

	inline S GetX() const { return x; }
	inline S GetY() const { return y; }
	inline S GetZ() const { return z; }
	inline void SetX(S d) { x = d; }
	inline void SetY(S d) { y = d; }
	inline void SetZ(S d) { z = d; }

	Vector3Dx<S> operator+(Vector3Dx<S> v);
	Vector3Dx<S> operator-(Vector3Dx<S> v);
	Vector3Dx<S> operator*(S s);
	Vector3Dx<S> operator/(S s);
	S operator*(Vector3Dx<S> v);

	S Norm2();
	S Norm();
	S Length();
	S Distance(Vector3Dx<S> v);
	Vector3Dx<S> X(Vector3Dx<S> v1);
	Vector3Dx<S> Normalize();
	Vector3Dx<S> Project(Vector3Dx<S> v);
	Vector3Dx<S> Coproject(Vector3Dx<S> a);

};

template<class S> Vector3Dx<S> Vector3Dx<S>::operator+(Vector3Dx<S> v)
{
	return Vector3Dx<S>(this->GetX() + v.GetX(), this->GetY() + v.GetY(), this->GetZ() + v.GetZ());
}

template <class S> Vector3Dx<S> Vector3Dx<S>::operator-(Vector3Dx<S> v) {
	return Vector3Dx<S>(this->GetX() - v.GetX(), this->GetY() - v.GetY(),
		this->GetZ() - v.GetZ());
}

template <class S> Vector3Dx<S> Vector3Dx<S>::operator*(S s) {
	return Vector3D(this->GetX() * s, this->GetY() * s,
		this->GetZ() * s);
}

template <class S> Vector3Dx<S> Vector3Dx<S>::operator/(S s) {
	return Vector3D(this->GetX() / s, this->GetY() / s,
		this->GetZ() / s);
}

template <class S> S Vector3Dx<S>::operator*(Vector3Dx<S> v) {
	return (this->GetX() * v.GetX()) + (this->GetY() * v.GetY()) +
		(this->GetZ() / v.GetZ());
}

template <class S> Vector3Dx<S> Vector3Dx<S>::X(Vector3Dx<S> v1) {
	Vector3Dx<S>& v2 = *this;
	Vector3Dx<S> r(
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x);
	return r;
}

template <class S> S Vector3Dx<S>::Norm2() {
	S s;
	Vector3Dx<S>& este = *this;
	//s= x*x + y*y + z*z;
	s = este * este;//(*this)*(*this) <=> this->operator*(*this)
	return s;
}

template <class S> S Vector3Dx<S>::Norm() {
	Vector3Dx<S>& este = *this;
	S s;
	s = sqrt(este.Norm2());
	return s;
}

template <class S> S Vector3Dx<S>::Length() {
	return Norm();
}

template <class S> S Vector3Dx<S>::Distance(Vector3Dx<S> v) {
	Vector3Dx<S> dif;
	dif.setX(v.getX() - (*this).getX());
	dif.setY(v.getY() - this->getY());
	dif.setZ(v.getZ() - this->getZ());
	S d;
	d = dif.Norm();
	return d;
}

template <class S> Vector3Dx<S> Vector3Dx<S>::Normalize() {
	Vector3Dx<S> r;
	S l;
	Vector3Dx<S>& este = *this;
	l = Norm();
	r = este / l;
	return r;
}

template <class S> Vector3Dx<S> Vector3Dx<S>::Project(Vector3Dx<S> v) {
	Vector3Dx<S> n;
	Vector3Dx<S> r;
	n = this->Normalize();
	S prjL;
	prjL = n * v;
	r = n * prjL;
	return r;
}

template <class S> Vector3Dx<S> Vector3Dx<S>::Coproject(Vector3Dx<S> a) {
	Vector3Dx<S> a1;
	Vector3Dx<S> a2;
	a1 = this->Project(a);
	a2 = a - a1;
	return a2;
}


/**
template <class S> class Vector3Dx
{
private:
	S x, y, z;
	//float coordinateX;
	//float coordinateY;
	//float coordinateZ;

public:
	
	Vector3Dx() :x(0), y(0), z(0) {}
	Vector3Dx(S x, S y, S z = 0) : x(x), y(y), z(z) {}

	inline S GetX() const { return x; }
	inline S GetY() const { return y; }
	inline S GetZ() const { return z; }
	inline void SetX(S d) { x = d; }
	inline void SetY(S d) { y = d; }
	inline void SetZ(S d) { z = d; }

	Vector3Dx<S> operator+(Vector3Dx<S> v);
	Vector3Dx<S> operator-(Vector3Dx<S> v);
	Vector3Dx<S> operator*(S s);
	Vector3Dx<S> operator/(S s);
	S operator*(Vector3Dx<S> v);

	S Norm2();
	S Norm();
	S Length();
	S Distance(Vector3Dx<S> v);
	Vector3Dx<S> X(Vector3Dx<S> v1);
	Vector3Dx<S> Normalize();
	Vector3Dx<S> Project(Vector3Dx<S> v);
	Vector3Dx<S> Coproject(Vector3Dx<S> a);
	
	Vector3D() : coordinateX(0.0), coordinateY(0.0), coordinateZ(0.0) {}
	Vector3D(float coordX, float coordY, float coordZ) : coordinateX(coordX), coordinateY(coordY), coordinateZ(coordZ){}

	inline float GetX() const { return this->coordinateX; }
	inline float GetY() const { return this->coordinateY; }
	inline float GetZ() const { return this->coordinateZ; }

	inline void SetX(const float& coordinateXToSet) { this->coordinateX = coordinateXToSet; }
	inline void SetY(const float& coordinateYToSet) { this->coordinateY = coordinateYToSet; }
	inline void SetZ(const float& coordinateZToSet) { this->coordinateZ = coordinateZToSet; }

	Vector3D Add(const Vector3D& vector);
	Vector3D Substract(const Vector3D& vector);
	Vector3D Product(const float& value);
	Vector3D Division(const float& value);
	float DotProduct(const Vector3D& vector);
	Vector3D Cross(Vector3D v);
	float Norm2();
	float Norm();
	Vector3D Normalize();

	Vector3D operator+(const Vector3D& vector);
	Vector3D operator-(const Vector3D& vector);
	Vector3D operator*(const float& value);
	Vector3D operator/(const float& value);
	float operator*(const Vector3D& vector);
	
};
/**/
