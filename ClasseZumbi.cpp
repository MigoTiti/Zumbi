#include <iostream>
#include "Zumbi.h"

using namespace std;

Zumbi::Zumbi(string name){
	nome=name;
	cout << "Zumbi criado";
}

void Zumbi::setName(string name){
	nome=name;
}

void Zumbi::setHealth(float x){
	if (x>0)
	HP=x;
}

void Zumbi::setSpeed(int s){
	if (s>0)
	velocidade=s;
}

float Zumbi::getHealth(){
	//cout << HP;
	return HP;
}

string Zumbi::getName(){
	//cout << nome;
	return nome;
}

int Zumbi::getSpeed(){
	//cout << velocidade;
	return velocidade;
}
