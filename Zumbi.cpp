#include "Zumbi.h"
#include <random>

Zumbi::Zumbi():Humano(5000,300){
	this->nome="Sem nome";
    this->armadura=false;
    this->capacete=false;
}

Zumbi::Zumbi(const Zumbi &z1):Humano(z1.vida,z1.strength){
	this->nome=z1.nome;
	this->armadura=z1.armadura;
	this->capacete=z1.capacete;
    this->itens=z1.itens;
}

Zumbi::Zumbi(const string &name, int vida, int strength):Humano(vida,strength){
	this->nome=name;
    this->armadura=false;
    this->capacete=false;
}

bool Zumbi::operator==(const Zumbi &z1) const{
    if(this->nome != z1.nome)
        return false;
    if(this->vida != z1.vida)
        return false;
    if(this->armadura != z1.armadura)
        return false;
    if(this->capacete != z1.capacete)
        return false;
    if(this->strength != z1.strength)
        return false;
    if(this->numeroItens != z1.numeroItens)
        return false;
    for(int i=0;i<this->numeroItens;i++){
    	if(this->itens[i] != z1.itens[i])
    	    return false;
	}
	return true;
}

void Zumbi::incrementarVida(int valor){
    this->vida += valor;
}

void Zumbi::setA(){
	armadura=true;
    incrementarVida(500);
}

void Zumbi::setC(){
	capacete=true;
    incrementarVida(300);
}

void Zumbi::pegarItem(char item){
    string itemAtual;
    
	switch(item){
		case 'C':
			cout << "Voce pegou um capacete, +200 de vida.";
			setC();
            itemAtual = "capacete";
			do{
				cin.get();
			    }while(cin.get()!='\n');
			system("cls");
			break;
		case 'A':
			cout << "Voce pegou uma armadura, +500 de vida.";
			setA();
            itemAtual = "armadura";
			do{
				cin.get();
			    }while(cin.get()!='\n');
			system("cls");
			break;
	}
    this->numeroItens++;
    itens.push_back(itemAtual);
}
