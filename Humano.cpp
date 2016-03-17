#include "Humano.h"

Humano::Humano(int vida, int strength){
	if(vida>0)
	    this->vida = vida;
	else
	    this->vida = 2000;
	    
    if(strength>0)
    	this->strength = strength;
    else
        this->strength = 200;
}

Humano::Humano(const Humano &h1){
	this->vida = h1.vida;
	this->strength = h1.strength;
}
