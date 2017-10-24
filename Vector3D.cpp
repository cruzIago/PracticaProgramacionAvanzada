#include "Vector3D.h"


Vector3D Vector3D::operator+(Vector3D v2) {
	Vector3D vuelta;
	vuelta.x = x + v2.x;
	vuelta.y = y + v2.y;
	vuelta.z = z + v2.z;
	return vuelta;
}
Vector3D Vector3D::operator-(Vector3D v2) {
	Vector3D vuelta;
	vuelta.x = v2.x - x;
	vuelta.y = v2.y - y;
	vuelta.z = v2.z - z;
	return vuelta;
}
Vector3D Vector3D::operator*(double d) {
	Vector3D vuelta;
	vuelta.x = x*d;
	vuelta.y = y*d;
	vuelta.z = z*d;
	return vuelta;
}

Vector3D Vector3D::operator/(double d) {
	Vector3D vuelta;
	vuelta.x = x / d;
	vuelta.y = y / d;
	vuelta.z = z / d;
	return vuelta;
}


