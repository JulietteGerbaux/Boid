#ifndef FLOCK_H
#define FLOCK_H

#include "boid.h"
#include "target.h"
#include "cage.h"
#include <vector>
#include "vecteur3.h"

class Flock {

	std::vector<Boid> boids;
	std::vector<Target> targets;
	Cage cage;
public:
	// Constructor
	Flock();
	// Destructor
	~Flock();


	void draw();
	void move(float);
	void addBoid();
	vecteur3<float> ruleCohesion(int i);
	vecteur3<float> ruleSeparation(int i);
	vecteur3<float> ruleAlignment(int i);
	vecteur3<float> ruleTarget(int i);
	int closestBoid(int i);
	std::vector<int> closedBoids(int i);
	int closestTarget(int i);
};

#endif 

