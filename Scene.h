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
	virtual ~Scene();
	Scene(const Scene&es) {
		for (Solid *s : es.solids) {
			Solid *s0 = s->clone();
			solids.push_back(s0);
		}
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

		for (Solid* s : solids) {
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
