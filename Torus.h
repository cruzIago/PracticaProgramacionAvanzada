#pragma once
#include "Vector3D.h"
#include "Solid.h"


class Torus :public Solid {

	private: 
		double iradius;
		double eradius;
	public:
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