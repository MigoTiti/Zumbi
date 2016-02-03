#include "Zumbi.h"
#include <random>
#include <ctime>
#include <iostream>
#include <conio.h>

#define vh 4000

Zumbi::Zumbi(){
	this->nome="Sem nome";
    this->hp=5000;
    this->armadura=false;
    this->capacete=false;
    this->strength=300;   
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
    if (armadura)
        cout << "\nPossui armadura.";
    else
        cout << "\nNao possui armadura";
    if (capacete)
        cout << "\nPossui capacete.";
    else
        cout << "\nNao possui capacete";        
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
	switch(item){
		case 'C':
			cout << "Voce pegou um capacete, +200 de vida.";
			setC();
			do{
				cin.get();
			    }while(cin.get()!='\n');
			system("cls");
			break;
		case 'A':
			cout << "Voce pegou uma armadura, +500 de vida.";
			setA();
			do{
				cin.get();
			    }while(cin.get()!='\n');
			system("cls");
			break;
	}
}

int Zumbi::atacarHumano(){
	int VidaH=vh, VidaZ=hp, Sh=200, Sz=strength, maismenos, atk, total;
	char opt;
	srand(time(NULL));
	do{
		system("cls");
		cout << "HP humano: " << VidaH << "    ";
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
				cout << "Humano usou Ataque normal, causando " << total << " de dano.";
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
