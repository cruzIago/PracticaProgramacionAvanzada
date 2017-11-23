#pragma once;
#include "Cube.h";
#include "Sphere.h";
#include "Torus.h";
#include "Solid.h"
#include <vector>;

using namespace std;


class Scene {
private:
	vector<Solid*> solids;
public:
	Scene();
	virtual ~Scene() {
		for (Solid *s : solids) {
			delete s;
		}
		solids.clear();
	}
	//El & permite recibir como parametros las variables y realizar operaciones directamente sobre
	//Los espacios de memoria (Guia de estudio 3, 2.2 referencias)
	Scene(const Scene&es) {
		for (Solid *s : es.solids) {
			Solid *s0 = s->clone();
			solids.push_back(s0);
		}
	}
	Scene *clone() {
		return new Scene(*this);
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
		for (Solid* s : solids) {
			s->render();
		}
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

inline ostream &operator<<(ostream &os, const Scene &e) {
	for (Solid *s : e.getSolids()){
		os << *s << endl;
	}
	return os;
}
