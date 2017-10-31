#pragma once
#include "Vector3D.h"
#include "Solid.h"


class Torus :public Solid {

	private: 
		double iradius;
		double eradius;
	public:
		Torus(double x = 0, double y = 0, double z = 0) :Solid(x,y,z),iradius(0.1),eradius(0.5){}
		Torus(const Torus &t) :
		Solid(t),
			iradius(t.iradius),
			eradius(t.eradius)
		{}
		Torus *clone() {
			return new Torus(*this);
		}
		void setIradius(double d) {
			iradius = d;
		}
		void setEradius(double d) {
			eradius = d;
		}
		double getIradius() {
			return iradius;
		}
		double getEradius() {
			return eradius;
		}

		void render();

};