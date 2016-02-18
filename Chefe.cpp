#include "Chefe.h"

Chefe::Chefe()
{
    this->hp=5000;
    this->strength=300;
}

Chefe::~Chefe()
{
}

void Chefe::incrementarVida()
{
    this->hp+=100;
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
    return this->hp;
}