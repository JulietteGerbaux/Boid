#ifndef CAGE_H
#define CAGE_H
#include "objet.h"

class Cage : public Objet {
public:
	Cage(float s=20.0f);
	virtual ~Cage();
	virtual void draw();
};

#endif
