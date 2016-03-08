#include "Chefe.h"
#include "Humano.h"

ostream& operator<<(ostream &saida, const Chefe &c1){
	saida << static_cast <Humano> (c1);
	
	if(c1.arma)
	    saida << "Possui arma.";
    else
        saida << "Nao possui arma.";
    
    return saida;
}

Chefe::Chefe():Humano(5000,300)
{
}

Chefe::Chefe(const Chefe &c):Humano(static_cast <Humano> (c)){
	this->arma = c.arma;
}

void Chefe::operator=(const Chefe &c1){
	static_cast<Humano&> (*this) = static_cast <Humano>(c1);
	this->arma = c1.arma;
}

Chefe::~Chefe()
{
}

void Chefe::incrementarVida()
{
    this->vida+=100;
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
