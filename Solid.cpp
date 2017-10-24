#include <GL\freeglut.h>
#include <iostream>
#include "Vector3D.h"
#include "Solid.h"

using namespace std;



void Solid::update(double dt) {

	Vector3D g(0, -0.00098f, 0);
	Vector3D a = fur / mas;
	vel = vel + a*dt;
	vel = vel + g*dt;
	pos = pos + vel*dt;
	if (abs(pos.getZ()) > 2) {
		double vz;
		vz = vel.getZ();
		vz *= -1;
		vel.setZ(vz);

	}
	if (abs(pos.getX()) > 2) {
		double vx;
		vx = vel.getX();
		vx *= -1;
		vel.setX(vx);

	}
	if (pos.getY() < 0) {
		double vy;
		vy = vel.getY();
		vy *= -1;
		vel.setY(vy);
		pos.setY(0);



	}
}
