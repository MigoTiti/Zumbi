#include <iostream>
#include <conio.h>
#include <windows.h>
#include <random>
#include <ctime>
#include "Mapa.h"

using namespace std;

void escolha2(int opt);
void escolha(int op, Zumbi z1, Mapa1 *m1, Mapa2 *m2);
int menu();

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

int main(){
	SetConsoleTextAttribute(console,15);
	cout << "Digite o nome do zumbi: ";
	string nome1;
	cin >> nome1;
	
	Zumbi z1(nome1);
	z1.setSpeed(1);
	z1.setHealth(5000);
	
    Mapa1 m1(30);
	m1.iniciarMapa(&m1,8);
	
	Mapa2 m2(30);
	m2.iniciarMapa(&m2,8);
	
	int op;
	do{
	op=menu();
	escolha(op,z1,&m1,&m2);
    }while(op!=3);
}	

void escolha(int op, Zumbi z1, Mapa1 *m1, Mapa2 *m2){
	int opt, i, j, c=0;
	char d;
	switch(op){
		case 1:
			system("cls");
			m1->exibirMapa(m1);
			cout << "\nDeseja voltar ao menu? (s=1/n=0): ";
			cin >> opt;
			escolha2(opt);
			break;
		case 2:
			system("cls");
			m1->exibirMapa(m1);
			cout << "\nUse o numpad para andar: ";
			d=getche();
			m1->andarMapa(m1,d,&z1,&c);
			break;
		case 3:
			exit(0);
			break;
		default:
			cout << "Comando invalido";
	}
	if (c==16){
	system("cls");
	cout << "Voce chegou ao nivel 2.";
	do{
	    cin.get();
	}while(cin.get()!='\n');
	m2->andarMapa(m2,d,&z1);
	}
}

void escolha2(int opt){
	system("cls");
    if (opt==0)
     exit(0);
    else
     system("cls");
}

int menu(){
	int op;
	system("cls");
	cout << "Escoha uma opcao:\n\n";
	cout << "1-Ver mapa; \n";
	cout << "2-Andar; \n";
	cout << "3-Sair. \n\n";
	cin >> op;
	return op;
}