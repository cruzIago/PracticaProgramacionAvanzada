#pragma once
#include "Vector3D.h"

class Solid {
private:
	Vector3D pos;
	Vector3D vel;
	Vector3D col;
	Vector3D fur;
	double mas;
public:
	void setPos(Vector3D p) {
		pos = p;
	}

	void setVel(Vector3D v) {
		vel = v;
	}

	void setCol(Vector3D c) {
		col = c;
	}
	
	void setFur(Vector3D f) {
		fur = f;
	}

	void setMas(double m) {
		mas = m;
	}

	Vector3D getPos() {
		return pos;
	}
	Vector3D getVel() {
		return vel;
	}
	Vector3D getCol() {
		return col;
	}
	Vector3D getFur() {
		return fur;
	}

	double getMas() {
		return mas;
	}

	void update(double dt);

};