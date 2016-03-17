#include "Chefe.h"
#include "Humano.h"

ostream& operator<<(ostream &saida, const Chefe &c1){
	saida << "\nPontos de vida: " << c1.vida;
    saida << "\nForca: " << c1.strength;
	
	if(c1.arma)
	    saida << "Possui arma.";
    else
        saida << "Nao possui arma.";
    
    return saida;
}

Chefe::Chefe():Humano(5000,300)
{
}

Chefe::Chefe(const Chefe &c):Humano(c.vida,c.strength){
	this->arma = c.arma;
}

void Chefe::operator=(const Chefe &c1){
	this->vida = c1.vida;
	this->strength = c1.strength;
	this->arma = c1.arma;
}

Chefe::~Chefe()
{
}

void Chefe::incrementarVida(int valor)
{
    this->vida+=valor;
}

void Chefe::decrementarStrength()
{
    this->strength-=10;
}

int Chefe::getStrength()
{
    return this->strength;
}

int Chefe::getVida()
{
    return this->vida;
}
