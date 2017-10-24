#include <GL\freeglut.h>
#include <iostream>
#include "Vector3D.h"
#include "Cube.h"

using namespace std;

void Cube::render() {
	glPushMatrix();
	glTranslatef(getPos().getX(), getPos().getY(), getPos().getZ());
	glColor3f(getCol().getX(), getCol().getY(), getCol().getZ());
	glutSolidCube(s);
	glPopMatrix();
}


