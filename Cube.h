#ifndef _CUBE_H_
#define _CUBE_H_
#include "Vector3D.h"
#include "Solid.h"


class Cube:public Solid {
private:

	double s;
public:

	Cube(double x=0, double y=0, double z=0) :Solid(x, y, z), s(0.1) {}
	Cube(const Cube&c):
	Solid(c),
	s(c.s)
	{
	}

	Cube *clone() {
		return new Cube(*this);
	}
	inline double getS() {
		return s;
	}
	inline void setS(double d) {
		s = d;
	}

	void render();
	//void update(double dt);
};

#endif