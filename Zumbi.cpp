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
    return a;
}

int Zumbi::getC(){
	return c;
}

void Zumbi::setA(){
	a=1;
}

void Zumbi::setC(){
	c=1;
}

void Zumbi::setName(string name){
	nome=name;
}

void Zumbi::setHealth(float x){
	if (x>=0)
	hp=x;
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

void Zumbi::pegarItem(char item, Zumbi *z1){
	switch(item){
		case 'C':
			cout << "Voce pegou um capacete, +200 de vida.";
			setC();
			z1->c=1;
			do{
				cin.get();
			    }while(cin.get()!='\n');
			system("cls");
			break;
		case 'A':
			cout << "Voce pegou uma armadura, +500 de vida.";
			setA();
			z1->a=1;
			do{
				cin.get();
			    }while(cin.get()!='\n');
			system("cls");
			break;
	}
}

int Zumbi::atacarHumano(){
	int VidaH=vh, Sh=200, Sz=300, maismenos, atk, total;
	float hp;
	char opt;
	srand(time(NULL));
	setHealth(5000);
	hp=getHealth();
	if(getA()==1){
		hp=hp+500;
	}
	if(getC()==1){
		hp=hp+200;
	}
	do{
		system("cls");
		cout << "HP humano: " << VidaH << "    ";
		cout << "HP " << getName() << ": " << hp;
		cout << "\n1- Ataque normal;";
		cout << "\n2- Mordida (custa pontos de vida);\n\n";
		opt=getche();
		switch(opt){
			case '1':
				maismenos=rand() % 2;
				atk=rand() % 201;
				if (maismenos==1){
					total=Sz+atk;
					VidaH=VidaH-total;
					if (hp<0){
						hp=0;
					}
				}else{
					total=Sz-atk;
					VidaH=VidaH-total;
					if (hp<0){
						hp=0;
					}
				}
				system("cls");
				cout << getName() << " usou Ataque normal, causando " << total << " de dano.";
				do{
				cin.get();
			    }while(cin.get()!='\n');
				break;
			case '2':
				hp=hp-200;
				maismenos=rand() % 2;
				atk=rand() % 201;
				if (maismenos==1){
					total=Sz+atk+100;
					VidaH=VidaH-total;
					if (hp<0){
						hp=0;
					}
				}else{
					total=Sz-atk+100;
					VidaH=VidaH-total;
					if (hp<0){
						hp=0;
					}
				}
				system("cls");
				cout << getName() << " usou Mordida, causando " << total << " de dano e recebendo 200 de dano colateral";
				do{
				cin.get();
			    }while(cin.get()!='\n');
				break;
		}
				maismenos=rand() % 2;
				atk=rand() % 101;
				if (maismenos==1){
					total=Sh+atk;
					hp=hp-total;
					if (hp<0){
						hp=0;
					}
					setHealth(hp);
				}else{
					total=Sh-atk;
					hp=hp-total;
					if (hp<0){
						hp=0;
					}
					setHealth(hp);
				}
				cout << "Humano usou Ataque normal, causando " << total << " de dano.";
				do{
				cin.get();
			    }while(cin.get()!='\n');
	}while((hp>0) && (VidaH>0));
	if (hp==0){
	return 0;
	}else{
	return 1;
    }
}