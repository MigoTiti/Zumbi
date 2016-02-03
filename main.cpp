#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Mapa.h"

using namespace std;

void escolha(int op, Zumbi *z1, Mapa *m1);
int menu();

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

int main(){
	SetConsoleTextAttribute(console,15);
	cout << "Digite o nome do zumbi: ";
	string nome;
	cin >> nome;
	
	Zumbi z1(nome);
	
    Mapa m1;
	m1.iniciarMapa();

	int op;
	do{
	op=menu();
	escolha(op,&z1,&m1);
    }while(op!=4);
}	

void escolha(int op, Zumbi *z1, Mapa *m1){
	int c=0;
	char d, opt;
	switch(op){
		case 1:
			system("cls");
			m1->exibirMapa();
			cout << "\nDeseja voltar ao menu? (s=1/n=0): ";
			opt=getche();
	        system("cls");
            if (opt=='0')
              exit(0);
			break;
		case 2:
			system("cls");
			m1->exibirMapa();
			cout << "\nUse o numpad para andar: ";
			d=getche();
			m1->andarMapa(d,z1,&c);
			break;
		case 3:
            system("cls");
            z1->exibirStatus();
			cout << "\n\n\nDeseja voltar ao menu? (s=1/n=0): ";
			opt=getche();
	        system("cls");
            if (opt=='0')
              exit(0);
			break;
        case 4:
			exit(0);
			break;
		default:
			cout << "Comando invalido";
	}
}

int menu(){
	int op;
	system("cls");
	cout << "Escolha uma opcao:\n\n";
	cout << "1-Ver mapa; \n";
	cout << "2-Andar; \n";
    cout << "3-Exibir status; \n";
	cout << "4-Sair. \n\n";
	cin >> op;
	return op;
}
