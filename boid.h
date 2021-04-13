#ifndef BOIDS_H
#define BOIDS_H

#include "objet.h"
#include "vecteur3.h"


class Boid : public Objet {

	vecteur3<float> v;
	vecteur3<float> a;
	vecteur3<float> color;
public:
	// Constructor
	Boid(vecteur3<float> pos = { 0.0f, 0.0f, 0.0f }, vecteur3<float> speed = { 0.0f, 0.0f, 0.0f}, vecteur3<float> acc = { 0.0f, 0.0f, 0.0f}, vecteur3<float> col = { 1.0f, 1.0f, 1.0f});
	// Destructor
	virtual ~Boid();
	virtual void draw() ;
	Boid& update(vecteur3<float> acc, float dt, vecteur3<float> speed, float size);
	vecteur3<float> getSpeed();
	
};

#endif  // BOIDS_LIB_SAMPLE_CLASS_H_
