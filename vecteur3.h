#pragma once
#include <time.h>
#include <iostream>
#include <math.h>
#define PI 3.14159265f

template <typename T>
class vecteur3
{
	T x, y, z;
public:
	vecteur3();
	vecteur3(T x, T y, T z) : x(x), y(y), z(z) {};
	vecteur3(vecteur3<T> const& vecteur3ACopier) : x(vecteur3ACopier.x), y(vecteur3ACopier.y), z(vecteur3ACopier.z) {};
	
	~vecteur3() {};
	T getX(void);
	T getY(void);
	T getZ(void);

	T operator[](int i);
	vecteur3<T>& operator+=(const vecteur3<T>& a);
	vecteur3<T>& operator-=(const vecteur3<T>& a);
	vecteur3<T>& operator*=(const T& a);
	vecteur3<T>& operator/=(const T& a);
	
	T angle_z();
	T norm();
	vecteur3<T>& changeZ(const T& a);
	vecteur3<T>& maxValue(const T& a);
};



template <typename T>
inline T vecteur3<T>::getX(void) {
	return x;
}

template <typename T>
inline T vecteur3<T>::getY(void) {
	return y;
}

template <typename T>
inline T vecteur3<T>::getZ(void) {
	return z;
}

template <typename T>
inline bool operator==(vecteur3<T> const& a, vecteur3<T> const& b)
{
	if (a.getX() == b.getX() && a.getY() == b.getY() && a.getZ() == b.getZ()) { return true; }
	else { return false; }
}

template <typename T>
inline T vecteur3<T>::operator[](int i)
{
	if (i == 0) return getX();
	if (i == 1) return getY();
	if (i == 2) return getZ();
	else {
		throw std::string("Indice invalid");
	}
}

template <typename T>
inline vecteur3<T>& vecteur3<T>::operator+=(const vecteur3<T>& a)
{
	x += a.x;
	y += a.y;
	z += a.z;
	return *this;
}

template <typename T>
inline vecteur3<T> operator+(vecteur3<T> const& a, vecteur3<T> const& b)
{
	vecteur3<T> copie(a);
	copie += b;       
	return copie;
}

template <typename T>
inline vecteur3<T>& vecteur3<T>::operator-=(const vecteur3<T>& a)
{
	x -= a.x;
	y -= a.y;
	z -= a.z;
	return *this;
}

template <typename T>
inline vecteur3<T> operator-(vecteur3<T> const& a, vecteur3<T> const& b)
{
	vecteur3<T> copie(a);
	copie -= b;
	return copie;
}

template <typename T>
inline vecteur3<T>& vecteur3<T>::operator*=(const T& a)
{
	x *= a;
	y *= a;
	z *= a;
	return *this;
}

template <typename T>
inline vecteur3<T> operator*(vecteur3<T> const& a, T const& b)
{
	vecteur3<T> copie(a);
	copie *= b;
	return copie;
}

template <typename T>
inline vecteur3<T> operator*(T const& a, vecteur3<T> const& b)
{
	vecteur3<T> copie(b);
	copie *= a;
	return copie;
}

template <typename T>
inline vecteur3<T>& vecteur3<T>::operator/=(const T& a)
{
	x /= a;
	y /= a;
	z /= a;
	return *this;
}

template <typename T>
inline vecteur3<T> operator/(vecteur3<T> const& a, T const& b)
{
	vecteur3<T> copie(a);
	copie /= b;
	return copie;
}

template <typename T>
inline vecteur3<T>& vecteur3<T>::maxValue(const T& a) {
	if (x > a) x = a;
	if (x < -a) x = -a;
	if (y > a) y = a;
	if (y < -a) y = -a;
	if (z > a) z = a;
	if (z < -a) z = -a;
	return *this;
}

template <typename T>
inline T vecteur3<T>::norm() {
	return sqrt(x * x + y * y + z * z);
}

template <typename T>
inline vecteur3<T>& vecteur3<T>::changeZ(const T& a) {
	z = a;
	return *this;
}

inline vecteur3<float>::vecteur3() {
	x = (float)rand() / RAND_MAX; // float entre 0 et 1
	y = (float)rand() / RAND_MAX;
	z = (float)rand() / RAND_MAX;
}

inline vecteur3<int>::vecteur3() {
	x = (rand() % 10); // entier entre 0 et 9
	y = (rand() % 10);
	z = (rand() % 10);
}

inline float vecteur3<float>::angle_z() {
	if (x == 0) {
		if (y > 0) return 90.0f;
		else return 270.0f;
	}
	else {
		return 180.0f / PI * atan(y / x);
	}
}
