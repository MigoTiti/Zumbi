#include "Zumbi.h"
#include <random>
#include <ctime>
#include <iostream>
#include <conio.h>

#define vh 4000

Zumbi::Zumbi(string name){
	nome=name;
}

int Zumbi::getA(){
    return armadura;
}

int Zumbi::getC(){
	return capacete;
}

void Zumbi::setA(){
	armadura=true;
    hp=hp+500;
}

void Zumbi::setC(){
	capacete=true;
    hp=hp+200;
}

void Zumbi::setName(string name){
	nome=name;
}

void Zumbi::setHealth(float x){
	if (x>=0)
	hp=x;
}

void Zumbi::setStrength(int s){
    if (s>0)
    strength=s;
}

void Zumbi::setSpeed(int s){
	if (s>0)
	velocidade=s;
}

float Zumbi::getHealth(){
	return hp;
}

string Zumbi::getName(){
	return nome;
}

int Zumbi::getSpeed(){
	return velocidade;
}

int Zumbi::getStrength(){
	return strength;
}

void Zumbi::pegarItem(char item, Zumbi *z1){
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
	int VidaH=vh, Sh=200, Sz, maismenos, atk, total;
	float hp;
	char opt;
	srand(time(NULL));
	hp=getHealth();
    Sz=getStrength();
	do{
		system("cls");
		cout << "HP humano: " << VidaH << "    ";
		cout << "HP " << getName() << ": " << hp;
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
				cout << getName() << " usou Ataque normal, causando " << total << " de dano.";
				do{
				cin.get();
			    }while(cin.get()!='\n');
				break;
			case '2':
				hp=hp-200;
                if (hp<0){
                    hp=0;
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
				cout << getName() << " usou Mordida, causando " << total << " de dano e recebendo 200 de dano colateral";
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
					hp=hp-total;
					if (hp<0){
						hp=0;
					}
				}else{
					total=Sh-atk;
					hp=hp-total;
					if (hp<0){
						hp=0;
					}
				}
				cout << "Humano usou Ataque normal, causando " << total << " de dano.";
				do{
				cin.get();
			    }while(cin.get()!='\n');
	}while((hp>0) && (VidaH>0));
	if (hp==0){
    system("cls");
	return 0;
	}else{
    system("cls");
	return 1;
    }
}
