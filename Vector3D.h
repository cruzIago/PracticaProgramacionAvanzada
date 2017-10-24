#ifndef _VECTOR3D_H_
#define _VECTOR3D_H_

class Vector3D {
private:
	double x;
	double y;
	double z;
public:
	//Inicializa los parametros por defecto a 0 o a los valores que recibe
	
	Vector3D(double x = 0, double y = 0, double z = 0) :x(x), y(y), z(z) {
	}
	inline double getX() {
		return x;
	}
	inline void setX(double d) {
		x = d;
	}
	inline double getY() {
		return y;
	}
	inline void setY(double d) {
		y = d;
	}
	inline double getZ() {
		return z;
	}
	inline void setZ(double d) {
		z = d;
	}

	Vector3D operator+(Vector3D v2);
	Vector3D operator*(double f);
	Vector3D operator-(Vector3D v2);
	Vector3D operator/(double f);
};

#endif