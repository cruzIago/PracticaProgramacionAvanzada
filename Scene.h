#pragma once;
#include "Cube.h";
#include "Sphere.h";
#include "Torus.h";
#include "Solid.h"
#include <vector>;

using namespace std;


class Scene {
private:
	vector<Cube*>cubes;
	vector<Sphere*>spheres;
	vector<Torus*> torus;
	vector<Solid*> solids;
public:

	vector<Solid*> getSolids() {
		return solids;
	}

	void setSolids(vector<Solid*> s) {
		solids = s;
	}


	void add(Torus* e) {
		torus.push_back(e);
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
