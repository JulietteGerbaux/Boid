#include "objet.h"
#include <iostream>

Objet::Objet() {
	vecteur3<float> p;
	size = 20.0f;
}

vecteur3<float> Objet::getPosition() {
	return p;
}

float Objet::getSize() {
	return size;
}

Objet::~Objet() {

}
