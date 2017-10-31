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
