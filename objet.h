#pragma once
#include "vecteur3.h"

class Objet
{
protected :
	float size;
	vecteur3<float> p;
public :
	Objet();
	virtual ~Objet();
	virtual void draw() = 0;
	vecteur3<float> getPosition();
	float getSize();
};

