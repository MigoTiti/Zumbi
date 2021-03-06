#include "Zumbi.h"
#include <random>
#include <string>
#include <ctime>
#include <iostream>
#include <conio.h>

#define vh 4

Zumbi::Zumbi():Humano(5000,300){
	this->nome="Sem nome";
    this->armadura=false;
    this->capacete=false;
    itens=new string[numeroItens];
}

ostream& operator<<(ostream &saida, const Zumbi &z1){
	
	saida << "\n" << z1.nome;
	saida << static_cast <Humano> (z1);
    
    for(int i=0;i<z1.numeroItens;i++){
        saida << "\nPossui " << z1.itens[i] << ";";
    }
    return saida;
}

Zumbi::Zumbi(const Zumbi &z1):Humano(static_cast <Humano> (z1)){
	this->nome=z1.nome;
	this->armadura=z1.armadura;
	this->capacete=z1.capacete;
    this->itens=z1.itens;
}

Zumbi::Zumbi(const string &name, int vida, int strength):Humano(vida,strength){
	this->nome=name;
    this->armadura=false;
    this->capacete=false;
    itens=new string[numeroItens];
}

void Zumbi::operator=(const Zumbi &z1){
	
	
    this->nome = z1.nome;
    this->armadura=z1.armadura;
    this->capacete=z1.capacete;
    this->numeroItens=z1.numeroItens;
    
	static_cast<Humano&> (*this) = static_cast <Humano>(z1);
    
    delete [] itens;
    itens = new string[this->numeroItens];
    
    for (int i=0;i<numeroItens;i++){
        this->itens[i] = z1.itens[i];
    }
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

void Zumbi::setA(){
	armadura=true;
    vida=vida+500;
}

void Zumbi::setC(){
	capacete=true;
    vida=vida+200;
}

void Zumbi::pegarItem(char item){
    
    string *aux = new string[++numeroItens];
    
    for (int i=0;i<numeroItens-1;i++){
        aux[i] = itens[i];
    }
    
    delete [] itens;
    
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
    aux[numeroItens-1] = itemAtual;
	itens = aux;
}

int Zumbi::atacarHumano(bool chefe, int vidaC, int strengthC){
	int VidaH=vh, VidaZ=vida, Sh=200, Sz=strength, maismenos, atk, total;
	char opt;
    string nomeH = "Humano";
    if (chefe){
        VidaH = vidaC;
        Sh = strengthC;
        nomeH = "Chefe";
    }
	srand(time(NULL));
	do{
		system("cls");
		cout << "HP " << nomeH << ": " << VidaH << "    ";
		cout << "HP " << nome << ": " << VidaZ;
		cout << "\n1- Ataque normal;";
		cout << "\n2- Mordida (custa pontos de vida);";
        cout << "\n3- Fugir; \n\n";
		opt=getche();
		switch(opt){
			case '1':
				maismenos=rand() % 2;
				atk=rand() % 201;
				if (maismenos==1){
					total=Sz+atk;
					VidaH=VidaH-total;
				}else{
					total=Sz-atk;
					VidaH=VidaH-total;
				}
				system("cls");
				cout << nome << " usou Ataque normal, causando " << total << " de dano.";
				do{
				cin.get();
			    }while(cin.get()!='\n');
				break;
			case '2':
				VidaZ=VidaZ-200;
                if (VidaZ<0){
                    VidaZ=0;
                }                
				maismenos=rand() % 2;
				atk=rand() % 201;
				if (maismenos==1){
					total=Sz+atk+100;
					VidaH=VidaH-total;
				}else{
					total=Sz-atk+100;
					VidaH=VidaH-total;
				}
				system("cls");
				cout << nome << " usou Mordida, causando " << total << " de dano e recebendo 200 de dano colateral";
				do{
				cin.get();
			    }while(cin.get()!='\n');
				break;
            case '3':
                    system("cls");
                    return 2;
		}
				maismenos=rand() % 2;
				atk=rand() % 101;
				if (maismenos==1){
					total=Sh+atk;
					VidaZ=VidaZ-total;
					if (VidaZ<0){
						VidaZ=0;
					}
				}else{
					total=Sh-atk;
					VidaZ=VidaZ-total;
					if (VidaZ<0){
						VidaZ=0;
					}
				}
				cout << nomeH <<" usou Ataque normal, causando " << total << " de dano.";
				do{
				cin.get();
			    }while(cin.get()!='\n');
	}while((VidaZ>0) && (VidaH>0));
	if (VidaZ==0){
    system("cls");
	return 0;
	}else{
    system("cls");
	return 1;
    }
}
