#ifndef TARGET_H
#define TARGET_H

#include "vecteur3.h"
#include "objet.h"

class  Target : public Objet
{

public:
	
	// Constructor
	Target(vecteur3<float> pos = {0.0f, 0.0f, 0.0f});
	// Destructor
	virtual ~Target();
	virtual void draw();
};

#endif