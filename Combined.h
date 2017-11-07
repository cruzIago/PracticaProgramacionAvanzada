#pragma once;
#include "Cube.h";
#include "Sphere.h";
#include "Torus.h";
#include "Solid.h"
#include <vector>;

using namespace std;


class Combined:public Solid {
private:
	vector<Solid*> solids;
public:
	Combined();
	virtual ~Combined() {
		for (Solid *s : solids) {
			delete s;
		}
		solids.clear();
	}

	Combined(const Combined&es):solids() {
		for (Solid *s : es.solids) {
			Solid *s0 = s->clone();
			solids.push_back(s0);
		}
	}
	Combined *clone() {
		return new Combined(*this);
	}
		
	vector<Solid*> getSolids() const {
		return solids;
	}

	void setSolids(vector<Solid*> s) {
		solids = s;
	}

	void add(Solid* s) {
		solids.push_back(s);
	}

	void render() {
		glPushMatrix();
		glTranslated(getPos().getX(), getPos().getY(), getPos().getZ());
		for (Solid* s : solids) {
			s->render();
		}
		glPopMatrix();
	}

	void update(double dt) {
		/*
		for (Solid* s : solids) {
		s->update(dt);
		}*/
		//Añadimos iterador para que el for each lo recorra de manera especifica
		//Se podría decir que es el for each con ciertas especificaciones
		for (vector<Solid * >::iterator i = solids.begin(); i < solids.end(); i++) {
			Solid *s = *i;
			s->update(dt);
		}

	}

};

inline ostream &operator<<(ostream &os, const Combined &e) {
	for (Solid *s : e.getSolids()) {
		os << *s << endl;
	}
	return os;
}
