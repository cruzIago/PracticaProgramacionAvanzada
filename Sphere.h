#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "Vector3D.h";
#include "Solid.h"

class Sphere:public Solid {
private:
	double r;
public:

	inline double getR() {
		return r;
	}
	inline void setR(double d) {
		r = d;
	}
	void render();
	//void update(double dt);
};

#endif