#include <GL\freeglut.h>
#include <iostream>
#include "Vector3D.h"
#include "Sphere.h"

using namespace std;

void Sphere::render() {
	glPushMatrix();
	glTranslatef(getPos().getX(), getPos().getY(), getPos().getZ());
	glColor3f(getCol().getX(), getCol().getY(), getCol().getZ());
	glutSolidSphere(r, 10, 10);
	glPopMatrix();
}

