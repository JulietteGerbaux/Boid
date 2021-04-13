#include <iostream>
#include <GL/glut.h>
#include "cage.h"

Cage::Cage(float s) {
	vecteur3<float> p;
	size = s;
}

Cage::~Cage() {}

void Cage::draw() {
	glBegin(GL_LINE_LOOP); // face droite
	glNormal3f(0, 1, 0);
	glVertex3f(size, size, size);
	glVertex3f(size, size, -size);
	glVertex3f(-size, size, -size);
	glVertex3f(-size, size, size);
	glEnd();
	glBegin(GL_LINE_LOOP); // face devant
	glNormal3f(1, 0, 0);
	glVertex3f(size, size, size);
	glVertex3f(size, size, -size);
	glVertex3f(size, -size, -size);
	glVertex3f(size, -size, size);
	glEnd();
	glBegin(GL_LINE_LOOP); // face dessus
	glColor3f(1, 104.0f / 255.0f, 54.0f / 255.0f);
	glNormal3f(0, 0, 1);
	glVertex3f(size, size, size);
	glVertex3f(-size, size, size);
	glVertex3f(-size, -size, size);
	glVertex3f(size, -size, size);
	glEnd();
	glBegin(GL_LINE_LOOP); // face droite
	glColor4f(2.0f / 255.0f, 179.0f / 255.0f, 137.0f / 255.0f, 0.7);
	glNormal3f(0, -1, 0);
	glVertex3f(size, -size, size);
	glVertex3f(size, -size, -size);
	glVertex3f(-size, -size, -size);
	glVertex3f(-size, -size, size);
	glEnd();
	glBegin(GL_LINE_LOOP); // face derriere
	glNormal3f(-1, 0, 0);
	glVertex3f(-size, size, size);
	glVertex3f(-size, size, -size);
	glVertex3f(-size, -size, -size);
	glVertex3f(-size, -size, size);
	glEnd();
	glBegin(GL_LINE_LOOP); // face dessous
	glColor3f(1, 1, 1);
	glNormal3f(0, 0, -1);
	glVertex3f(size, size, -size);
	glVertex3f(-size, size, -size);
	glVertex3f(-size, -size, -size);
	glVertex3f(size, -size, -size);
	glEnd();
}