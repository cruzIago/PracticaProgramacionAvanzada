#pragma once
#include "Solid.h"
#include "Vector3D.h"
//Plano (p/p.x*a+p.y*b+p.z*c=-d

class Triangle {
private:
	Vector3D a;
	Vector3D b;
	Vector3D c;
public:
	 Triangle(Vector3D p0, Vector3D p1, Vector3D p2) {
		 Vector3D v0 = p0 - p1;
		 Vector3D v1 = p1 - p2;
		 Vector3D v2 = v0.cross(v1);
		 if (v2.length()<0.001) {
			 cout << "muy pequeño" << endl;
		 }
		 else {
			 v2.normalize();
		 }
		 float u = v2 * p2;
	}
	inline Vector3D getA() {
		return a;
	}
	inline void setA(Vector3D d) {
		a = d;
	}
	inline Vector3D getB() {
		return b;
	}

	inline void setB(Vector3D d) {
		b = d;
	}
	inline Vector3D getC() {
		return c;
	}
	inline void setC(Vector3D d) {
		c = d;
	}

};