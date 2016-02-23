#include "Zumbi.h"
#include <random>
#include <ctime>
#include <iostream>
#include <conio.h>

#define vh 4

Zumbi::Zumbi(){
	this->nome="Sem nome";
    this->hp=5000;
    this->armadura=false;
    this->capacete=false;
    this->strength=300;
    itens = new string[numeroItens];
}

Zumbi::Zumbi(const Zumbi &z1){
	nome=z1.nome;
	hp=z1.hp;
	armadura=z1.armadura;
	capacete=z1.capacete;
	strength=z1.strength;
}

Zumbi::Zumbi(const string &name){
	this->nome=name;
    this->hp=5000;
    this->armadura=false;
    this->capacete=false;
    this->strength=300;
}

void Zumbi::exibirStatus() const{
    cout << "Pontos de vida: " << hp;
    cout << "\nForca: " << strength;
    for(int i=0;i<numeroItens;i++){
        cout << "possui " << itens[i] << ";";
    }
}

void Zumbi::setA(){
	armadura=true;
    hp=hp+500;
}

void Zumbi::setC(){
	capacete=true;
    hp=hp+200;
}

void Zumbi::pegarItem(char item){
    string *aux = new string[numeroItens];
    if(numeroItens>0){
        for (int i=0;i<numeroItens;i++){
            aux[i] = itens[i];
        }
    }
    
    delete [] itens;
    
    itens = new string[++numeroItens];
    
    if((numeroItens-1)!=0){
    	for (int i=0;i<numeroItens-1;i++){
            itens[i] = aux[i];
        }
	}
    
	switch(item){
		case 'C':
			cout << "Voce pegou um capacete, +200 de vida.";
			setC();
            itens[numeroItens-1] = "capacete";
			do{
				cin.get();
			    }while(cin.get()!='\n');
			system("cls");
			break;
		case 'A':
			cout << "Voce pegou uma armadura, +500 de vida.";
			setA();
            itens[numeroItens-1] = "armadura";
			do{
				cin.get();
			    }while(cin.get()!='\n');
			system("cls");
			break;
	}
	delete [] aux;
}

int Zumbi::atacarHumano(bool chefe, int vidaC, int strengthC){
	int VidaH=vh, VidaZ=hp, Sh=200, Sz=strength, maismenos, atk, total;
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
