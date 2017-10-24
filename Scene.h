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

	vector<Solid*> getSolids() {
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
