#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Mapa.h"

using namespace std;

void escolha(int op, Zumbi z1, Mapa *m1);
int menu();

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

int main(){
	SetConsoleTextAttribute(console,15);
	cout << "Digite o nome do zumbi: ";
	string nome;
	cin >> nome;
	
	Zumbi z1(nome);
	z1.setSpeed(1);
	z1.setHealth(5000);
    z1.setStrength(300);
	
    Mapa m1(30);
	m1.iniciarMapa(&m1);

	int op;
	do{
	op=menu();
	escolha(op,z1,&m1);
    }while(op!=3);
}	

void escolha(int op, Zumbi z1, Mapa *m1){
	int opt;
	char d;
	switch(op){
		case 1:
			system("cls");
			m1->exibirMapa(m1);
			cout << "\nDeseja voltar ao menu? (s=1/n=0): ";
			opt=getche();
	        system("cls");
            if (opt==0)
              exit(0);
			break;
		case 2:
			system("cls");
			m1->exibirMapa(m1);
			cout << "\nUse o numpad para andar: ";
			d=getche();
			m1->andarMapa(m1,d,&z1);
			break;
		case 3:
			exit(0);
			break;
		default:
			cout << "Comando invalido";
	}
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
