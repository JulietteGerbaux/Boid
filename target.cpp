#include "target.h"

#include <iostream>
#include <GL/glut.h>
#include "vecteur3.h"

Target::Target(vecteur3<float> pos) {
	p = pos;
	size = 1.0f;
}

Target::~Target() {
}

void Target::draw(){
	glPushMatrix();
	glTranslatef(p[0], p[1], p[2]);
	glScalef(2.0, 2.0, 2.0);
	glBegin(GL_QUADS); // face droite
	glColor4f(179.0f / 255.0f, 59.0f / 255.0f, 20.0f / 255.0f, 0.7f);
	glNormal3f(0, 1, 0);
	glVertex3f(0.1, 0.1, 0.1);
	glVertex3f(0.1, 0.1, -0.1);
	glVertex3f(-0.1, 0.1, -0.1);
	glVertex3f(-0.1, 0.1, 0.1);
	glEnd();
	glBegin(GL_QUADS); // face devant
	glColor3f(1, 123.0f / 255.0f, 79.0f / 255.0f);
	glNormal3f(1, 0, 0);
	glVertex3f(0.1, 0.1, 0.1);
	glVertex3f(0.1, 0.1, -0.1);
	glVertex3f(0.1, -0.1, -0.1);
	glVertex3f(0.1, -0.1, 0.1);
	glEnd();
	glBegin(GL_QUADS); // face dessus
	glColor3f(1, 104.0f / 255.0f, 54.0f / 255.0f);
	glNormal3f(0, 0, 1);
	glVertex3f(0.1, 0.1, 0.1);
	glVertex3f(-0.1, 0.1, 0.1);
	glVertex3f(-0.1, -0.1, 0.1);
	glVertex3f(0.1, -0.1, 0.1);
	glEnd();
	glBegin(GL_QUADS); // face droite
	glColor4f(2.0f / 255.0f, 179.0f / 255.0f, 137.0f / 255.0f, 0.7);
	glNormal3f(0, -1, 0);
	glVertex3f(0.1, -0.1, 0.1);
	glVertex3f(0.1, -0.1, -0.1);
	glVertex3f(-0.1, -0.1, -0.1);
	glVertex3f(-0.1, -0.1, 0.1);
	glEnd();
	glBegin(GL_QUADS); // face derriere
	glColor3f(54.0f / 255.0f, 1, 208.0f / 255.0f);
	glNormal3f(-1, 0, 0);
	glVertex3f(-0.1, 0.1, 0.1);
	glVertex3f(-0.1, 0.1, -0.1);
	glVertex3f(-0.1, -0.1, -0.1);
	glVertex3f(-0.1, -0.1, 0.1);
	glEnd();
	glBegin(GL_QUADS); // face dessous
	glColor3f(1, 1, 1);
	glNormal3f(0, 0, -1);
	glVertex3f(0.1, 0.1, -0.1);
	glVertex3f(-0.1, 0.1, -0.1);
	glVertex3f(-0.1, -0.1, -0.1);
	glVertex3f(0.1, -0.1, -0.1);
	glEnd();
	glPopMatrix();
}
