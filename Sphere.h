#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "Vector3D.h";
#include "Solid.h"

class Sphere:public Solid {
private:
	double r;
public:
	Sphere(double x=0, double y=0, double z=0):Solid(x, y, z), r(0.2) {}
	Sphere(const Sphere&e) :
		Solid(e),
		r(e.r)
	{}
	Sphere *clone() {
		return new Sphere(*this);
	}

	inline double getR() const {
		return r;
	}
	inline void setR(double d) {
		r = d;
	}
	void render();
	//void update(double dt);
};

inline ostream &operator<<(ostream &os, const Sphere &s) {
	os  << s.getR() << endl;
}

#endif