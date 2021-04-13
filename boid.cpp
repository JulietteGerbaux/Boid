#include <iostream>
#include <GL/glut.h>
#include "boid.h"
#include <math.h>


//BOID
Boid::Boid(vecteur3<float> pos, vecteur3<float> speed, vecteur3<float> acc, vecteur3<float> col) : v(speed), a(acc), color(col) {
	size = 1.0f;
	p = pos;
}

Boid::~Boid() {
}

void Boid::draw()
{
	float angle = v.angle_z();
	float x = p[0], y = p[1], z = p[2];
	float red = color[0], green = color[1], blue = color[2];
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(angle-90.0, 0.0, 0.0, 1.0);
	glScalef(1.0 / 7.5, 1.0 / 10.0, 1.0 / 10.0);
	glTranslatef(0.0, -4.0, -1.5);
	glBegin(GL_TRIANGLE_STRIP);
	/* left wing */
	glColor3f(red, green, blue);
	glVertex3f(-7.0, 0.0, 2.0);
	glVertex3f(-1.0, 0.0, 3.0);
	
	glVertex3f(-1.0, 7.0, 3.0);
	/* left side */
	glColor3f(0.6 * red, 0.6 * green, 0.6 * blue);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 8.0, 0.0);
	/* right side */
	glVertex3f(1.0, 0.0, 3.0);
	glVertex3f(1.0, 7.0, 3.0);
	/* final tip of right wing */
	glColor3f(red, green, blue);
	glVertex3f(7.0, 0.0, 2.0);
	glEnd();
	glPopMatrix();
}

Boid& Boid::update(vecteur3<float> acc, float dt, vecteur3<float> speed, float size) {
	a = acc;
	v += a * dt;
	v += speed;
	p += v * dt;
	float maxSpeed(10.0f);
	v.maxValue(maxSpeed);
	p.maxValue(size);
	return *this;
}

vecteur3<float> Boid::getSpeed() {
	return v;
}

