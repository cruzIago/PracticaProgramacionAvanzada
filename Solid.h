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

	Solid(double x=0, double y=0, double z=0) :pos(x, y, z), vel(0, 0, 0), col(1, 1, 1), fur(0, 0, 0), mas(0) {}
	Solid(const Solid&s) :
		pos (s.pos),
		vel (s.vel),
		col	(s.col),
		fur (s.fur),
		mas(s.mas)
	{}
	//virtual ~Solid(); //Se llama automaticamente cuando una variable deja de ser necesaria (virtual ~ss)
	virtual Solid *clone() = 0;
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

	virtual void render() = 0;//Esto obliga a los hijos a hacer un metodo render en los hijos

	void update(double dt);

	friend ostream &operator<<(ostream &os, const Solid &s);
};

inline ostream &operator<<(ostream &os, const Solid &s) {
	os << "pos=" << s.pos << endl;
	os << "vel=" << s.vel << endl;
	os << "col=" << s.col << endl;
	os << "fur=" << s.fur << endl;
	os << "mas=" << s.mas << endl;
	return os;
}

