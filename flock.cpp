#include "flock.h"

#include <iostream>
#include <GL/glut.h>
#include <Eigen/Dense>

using namespace std;


Flock::Flock() {
	Cage cage;
	boids = vector<Boid>(5);
	float size = cage.getSize();
	vecteur3<float> x(size, size, size);
	for (unsigned int i(0); i < boids.size(); ++i) {
		vecteur3<float> p;
		vecteur3<float> v(0.0f, 0.0f, 0.0f);
		vecteur3<float> a(0.0f, 0.0f, 0.0f);
		
		vecteur3<float> color;
		boids[i] = Boid(2*size*p-x,  v, a, 2.0f*color);
	}
	targets = vector<Target>(2);
	for (int i(0); i < targets.size(); ++i) {
		vecteur3<float> p;
		targets[i] = Target(1.5f*size* p-x);
	}
	
	
}

Flock::~Flock() {
	while (boids.size() != 0) {
		boids.pop_back();
	}
}

void Flock::draw()
{
	for (unsigned int i(0); i < boids.size(); ++i)
	{
		boids[i].draw();
	}
	for (unsigned int i(0); i < targets.size(); ++i)
	{
		targets[i].draw();
	}
	cage.draw();
}

void Flock::move(float dt)
{
	vector<vecteur3<float>> updateAcc(boids.size());
	vector<vecteur3<float>> updateV(boids.size());
	vecteur3<float> a1(0.0f, 0.0f, 0.0f);
	vecteur3<float> a2(0.0f, 0.0f, 0.0f);
	vecteur3<float> a3(0.0f, 0.0f, 0.0f);
	vecteur3<float> wind;
	for (unsigned int i(0); i < boids.size(); ++i)
	{
		a1 = ruleCohesion(i);
		a2 = ruleSeparation(i);
		a3 = ruleAlignment(i);
		updateAcc[i] = a1 + a2 + a3 + 2.0f*wind;
		updateV[i] = ruleTarget(i);
	}
	for (unsigned int i(0); i < boids.size(); ++i)
	{
		boids[i].update(updateAcc[i], dt, updateV[i], cage.getSize());
	}
}

vecteur3<float> Flock::ruleCohesion(int i) {
	vecteur3<float> massCenter(0.0f,0.0f,0.0f);
	for (unsigned int j(0); j < boids.size(); ++j) {
		if (i != j) {
			massCenter += boids[j].getPosition();
		}
	}
	massCenter /= (boids.size() - 1);
	return 0.005f * (massCenter - boids[i].getPosition());
}

int Flock::closestBoid(int i) {
	int indice(-1);
	float min(2.0f);
	for (unsigned int j(0); j < boids.size(); ++j) {
		if (i != j) {
			if ((boids[j].getPosition() - boids[i].getPosition()).norm() < min) {
				indice = j;
				min = (boids[j].getPosition() - boids[i].getPosition()).norm();
			}
		}
	}
	return indice;
}

int Flock::closestTarget(int i) {
	int indice(-1);
	float min(1000.0f);
	for (unsigned int j(0); j < targets.size(); ++j) {
		if ((targets[j].getPosition() - boids[i].getPosition()).norm() < min) {
			indice = j;
			min = (targets[j].getPosition() - boids[i].getPosition()).norm();
		}
	}
	return indice;
}

vecteur3<float> Flock::ruleSeparation(int i) {
	int indice = closestBoid(i);
	int iTar = closestTarget(i);
	if (indice != -1) {
		if ((boids[i].getPosition() - targets[iTar].getPosition()).norm() < (boids[i].getPosition() - boids[indice].getPosition()).norm()) {
			return 10.0f * (boids[i].getPosition() - targets[iTar].getPosition());
		}
		else {
			return 5.0f * (boids[i].getPosition() - boids[indice].getPosition());
		}
	}
	else {
		if ((boids[i].getPosition() - targets[iTar].getPosition()).norm() < 2.0f) {
			return 5.0f * (boids[i].getPosition() - targets[iTar].getPosition());
		}
		else {
			return { 0.0f, 0.0f, 0.0f };
		}
	}
}

vecteur3<float> Flock::ruleAlignment(int i) {
	vecteur3<float> massCenter(0.0f,0.0f,0.0f);
	for (unsigned int j(0); j < boids.size(); ++j) {
		if (i != j) {
			massCenter += boids[j].getSpeed();
		}
	}
	massCenter /= (boids.size() - 1);
	return 0.2f * (massCenter - boids[i].getSpeed());
}

vector<int> Flock::closedBoids(int i) {
	vector<int> closedBoids(0);
	float min(8.0f);
	for (unsigned int j(0); j < boids.size(); ++j) {
		if (i != j) {
			if ((boids[j].getPosition() - boids[i].getPosition()).norm() < min) {
				closedBoids.push_back(j);
			}
		}
	}
	return closedBoids;
}

vecteur3<float> Flock::ruleTarget(int i) {
	int iTar = (rand() % targets.size());
	return 0.005f * (targets[iTar].getPosition() - boids[i].getPosition())/ (targets[iTar].getPosition() - boids[i].getPosition()).norm();
}

void Flock::addBoid() {
	float size = cage.getSize();
	vecteur3<float> p;
	vecteur3<float> color;
	vecteur3<float> x(size, size, size);
	p *= 2.0f * size;
	p -= x;
	p.changeZ(-size);
	vecteur3<float> v = { 0.0f, 0.0f, 0.0f };
	vecteur3<float> a = { 0.0f, 0.0f, 0.0f };
	boids.push_back(Boid(p, v, a,2.0f*color));	
}