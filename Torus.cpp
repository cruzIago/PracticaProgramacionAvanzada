#include <GL\freeglut.h>
#include <iostream>
#include "Vector3D.h"
#include "Torus.h"

using namespace std;

void Torus::render() {
	glPushMatrix();
	glTranslatef(getPos().getX(), getPos().getY(), getPos().getZ());
	glColor3f(getCol().getX(), getCol().getY(), getCol().getZ());
	glutSolidTorus(iradius,eradius, 10, 10);
	glPopMatrix();
}