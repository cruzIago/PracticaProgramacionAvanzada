#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include "Vector3D.h"
#include "Cube.h"
#include "Sphere.h"
#include "Torus.h";
#include <vector>
#include "Scene.h"
#include "Solid.h"
using namespace std;


float pitch = 0;
float t = 0;
float dt = 0.1;
float oDist = -3;

Vector3D g; //Declaramos la gravedad

Scene e;
/**
* glVertex2f(float x, float y).
* The point (0.0, 0.0) represents the middle of the window (not the top left corner).
* The "2f" suffix means 2 values of float type (x and y).
*/
void displayMe(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, oDist);
	glRotatef(pitch, 1.0, 0.0, 0.0);
	GLfloat lightpos[] = { 5.0,15.0,5.0,0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);


	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd();
	

	e.render();



	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glVertex3f(0.5, 0.0, 0.5);
	glVertex3f(0.0, 0.0, 0.5);
	glEnd();
	glFlush();
	glutSwapBuffers();

}

void idle(void) {//Funcion que aumenta y vuelve a mostrar las figuras geometricas
	t = t + dt;

	e.update(dt);

	displayMe();

}

void keyPressed(unsigned char key, int x, int y) {
	switch (key) {
	case 'p':
	case 'P':
		pitch++;
		break;
	case 'o':
	case 'O':
		pitch--;
		break;
	case 't':
	case'T':
		oDist += 0.1;
		break;
	case 'y':
	case'Y':
		oDist -= 0.1;
		break;
	case 27:
		exit(0);
		break;
	}
	glutPostRedisplay(); //request display() call ASAP
}
void init(void) {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, (GLfloat)width / (GLfloat)height, 1.0f, 200.0f);
	glMatrixMode(GL_MODELVIEW);
}
void mousePressed() {

}

void mouseMoved() {

}
double getRandom(double max, double min = 0) {
	double numero = max - min;
	int internalRandom = rand() % 1000;
	return min + (double)internalRandom / 1000 * numero;
}
int main(int argc, char** argv) {
	
	Cube *c;
	Sphere *f;
	Torus *tr;
	Vector3D v;
	//cout << v << endl;
	c = new Cube();

	c->setPos(Vector3D(0,1,0));

	c->setCol(Vector3D(1,0,0));
	
	c->setVel(Vector3D(0,0,0));

	c->setS(0.5);

	c->setMas(1);	

	e.add(c);

	tr = new Torus();

	tr->setPos(Vector3D(0, 1, 0));
	tr->setCol(Vector3D(0, 2, 0));
	tr->setVel(Vector3D(0, 0, 0));
	tr->setIradius(0.1);
	tr->setEradius(0.2);
	tr->setMas(1);
	e.add(tr);
	
	for (double i = -3; i < 3; i++) {

		for (double j = -3; j < 3; j++) {
			c = new Cube();
			c->setPos(Vector3D(i, 1, j));

			c->setCol(Vector3D(1, 0, 0));

			c->setVel(Vector3D(0, 0, 0));

			c->setS(0.5);

			c->setFur(Vector3D(0, -0.000098, 0));
			c->setMas(1);

			e.add(c);

		}

	}

	/*
	c[1].pos.x = 5;
	c[1].pos.y = 1;
	c[1].pos.z = 1;
	c[1].col.x = 1;
	c[1].col.y = 1;
	c[1].col.z = 0;
	c[1].s = 0.2;

	e[0].pos.x = -1;
	e[0].pos.y = 1;
	e[0].getPost().setZ();
	e[0].col.x = 1;
	e[0].col.y = 1;
	e[0].col.z = 0;
	e[0].vel.x = -0.3;
	e[0].vel.y = 0;
	e[0].vel.z = -0.1;
	e[0].r = 0.3;

	e[1].pos.x = -2;
	e[1].pos.y = 1;
	e[1].pos.z = 0;
	e[1].col.x = 0;
	e[1].col.y = 0;
	e[1].col.z = 1;
	e[1].r = 0.6;
	*/

	
	glutInit(&argc, argv);
	glutInitDisplayMode(/*GLUT_DOUBLE |*/ GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(1280, 720);                    // window size
	glutInitWindowPosition(0, 0);                // distance from the top-left screen
	glutCreateWindow("BadproG - Hello world :D");    // message displayed on top bar window
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(displayMe);
	glutKeyboardFunc(keyPressed);
	glutIdleFunc(idle);
	//glutMotionFunc(&mouseMoved);
	//glutMouseFunc(&mousePressed)
	glutMainLoop();
	
	return 0;
}
