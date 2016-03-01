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

void Humano::operator=(const Humano &h1){
    this->vida=h1.vida;
    this->strength=h1.strength; 
}

ostream& operator<<(ostream &saida, const Humano &h1){
	saida << "Pontos de vida: " << h1.vida;
    saida << "\nForca: " << h1.strength;
    
    return saida;
}
