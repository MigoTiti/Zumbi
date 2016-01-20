#include "Zumbi.h"


Zumbi::Zumbi(string name){
	nome=name;
}

void Zumbi::setName(string name){
	nome=name;
}

void Zumbi::setHealth(float x){
	if (x>=0)
	HP=x;
}

void Zumbi::setSpeed(int s){
	if (s>0)
	velocidade=s;
}

float Zumbi::getHealth(){
	return HP;
}

string Zumbi::getName(){
	return nome;
}

int Zumbi::getSpeed(){
	return velocidade;
}
