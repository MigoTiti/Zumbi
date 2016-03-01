#include "Chefe.h"
#include "Humano.h"

Chefe::Chefe():Humano(5000,300)
{
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
