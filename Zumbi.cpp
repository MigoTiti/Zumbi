#include <iostream>
#include "Zumbi.h"

#define tam 30

using namespace std;
void escolha2(int opt);

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

void escolha(int op, Zumbi z1, char mapa[tam][tam]){
	int opt, i, j;
	switch(op){
		case 1:
			system("cls");
			cout << "Pontos de vida: " << z1.getHealth();
			cout << "\nVelocidade: " << z1.getSpeed() << "\n";
			cout << "\nDeseja voltar ao menu? (s=1/n=0): ";
			cin >> opt;
			escolha2(opt);
			break;
		case 2:
			system("cls");
			for (i=0;i<=(tam-1);i++){
				for (j=0;j<=(tam-1);j++){
					cout << " " << mapa[i][j];
				}
				cout << "\n";
			}
			cout << "\nDeseja voltar ao menu? (s=1/n=0): ";
			cin >> opt;
			escolha2(opt);
			break;
	}
}

void escolha2(int opt){
	system("cls");
    if (opt==0)
     exit(0);
    else
     system("cls");
}

int menu(void){
	int op;
	system("cls");
	cout << "Escoha uma opcao:\n\n";
	cout << "1-Ver stats; \n";
	cout << "2-Ver mapa; \n";
	cout << "3-Andar; \n";
	cout << "4-Comecar; \n";
	cout << "5-Sair. \n\n";
	cin >> op;
	return op;
}

int main(){
	cout << "Digite o nome do zumbi: ";
	string nome1;
	cin >> nome1;
	Zumbi z1(nome1);
	z1.setSpeed(1);
	z1.setHealth(5000);
	char mapa[tam][tam];
	int i, j;
	for (i=0;i<=(tam-21);i++){
		for (j=0;j<=(tam-1);j++){
			mapa[i][j]='0';
		}
	}
	for (i=10;i<=(tam-11);i++){
		for (j=0;j<=(tam-1);j++){
			mapa[i][j]='1';
		}
	}
	for (i=20;i<=(tam-1);i++){
		for (j=0;j<=(tam-1);j++){
			mapa[i][j]='0';
		}
	}
	int op;
	do{
	op=menu();
	escolha(op,z1,mapa);
    }while(op!=5);
}
