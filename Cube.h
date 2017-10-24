#ifndef _CUBE_H_
#define _CUBE_H_
#include "Vector3D.h"
#include "Solid.h"


class Cube:public Solid {
private:

	double s;
public:

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