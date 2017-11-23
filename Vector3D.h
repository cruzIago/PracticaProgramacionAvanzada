#ifndef _VECTOR3D_H_
#define _VECTOR3D_H_
#include <iostream>

using namespace std;
template <class S> class Vector3Dx;

typedef Vector3Dx<double>Vector3Dd;
typedef Vector3Dx<float>Vector3Df;
typedef Vector3Dx<int>Vector3Di;
//Se podrían declarar vectores de cualquier tipo

template <class S> class Vector3Dx {
private:
	S x;
	S y;
	S z;
public:
	//Inicializa los parametros por defecto a 0 o a los valores que recibe
	
	Vector3Dx(S x = 0, S y = 0, S z = 0) :x(x), y(y), z(z) {
	}
	Vector3Dx(const Vector3Dx &v) :
		x(v.x),
		y(v.y),
		z(v.z){
	}

	S squaredLength() {
		return x*x + y*y + z*z;
	}

	S length() {
		return sqrt(squaredLength());
	}

	inline void normalize() {
		S magn=length();
		magn = 1.0f / magn;
		x *= magn;
		y *= magn;
		z *= magn;
		//c._str() version c del string
	}
	Vector3Dx<S> *clone() {
		return new Vector3Dx<S>(*this);
	}
	inline S getX() {
		return x;
	}
	inline void setX(S d) {
		x = d;
	}
	inline S getY() {
		return y;
	}
	inline void setY(S d) {
		y = d;
	}
	inline S getZ() {
		return z;
	}
	inline void setZ(S d) {
		z = d;
	}

	inline Vector3Dx<S> cross(Vector3Dx<S> v2) {
		Vector3Dx<S> v1 = *this;//El asterisco depende de donde se implemente. nombre* variable es una variable apuntando a una posicion de memoria
		//*variable es el valor al que apunta ese puntero
		return (v1.y*v2.z - v1.z*v2.y,
			v1.z*v2.x - v1.x*v2.z,
			v1.x*v2.y - v1.y*v2.x);
	}
	inline Vector3Dx <S> operator+(Vector3Dx<S> v2) {
		Vector3Dx<S> vuelta;
		vuelta.x = x + v2.x;
		vuelta.y = y + v2.y;
		vuelta.z = z + v2.z;
		return vuelta;
	}
	inline Vector3Dx <S> operator-(Vector3Dx<S> v2) {
		Vector3Dx<S> vuelta;
		vuelta.x = v2.x - x;
		vuelta.y = v2.y - y;
		vuelta.z = v2.z - z;
		return vuelta;
	}
	inline Vector3Dx <S> operator*(S d) {
		Vector3Dx<S> vuelta;
		vuelta.x = x*d;
		vuelta.y = y*d;
		vuelta.z = z*d;
		return vuelta;
	}

	inline Vector3Dx <S> operator/(S d) {
		Vector3Dx<S> vuelta;
		vuelta.x = x / d;
		vuelta.y = y / d;
		vuelta.z = z / d;
		return vuelta;
	}

	friend ostream &operator<<(ostream &os, const Vector3Dx<double> &v);
};

inline ostream &operator<<(ostream &os, const Vector3Dx<double> &v) {
	os << v.x << "," << v.y << "," << v.z;
	return os;
}

/*
//Templates especializados
template <class T> inline ostream &operator<<(ostream
template ostream &operator<< <double>(ostream &os,const Vector3Dx <double> &v){}
*/

#endif