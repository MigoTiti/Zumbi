#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Mapa.h"
#include <string>

using namespace std;

void escolha(char op, int *c, ZumbiHunter *const z1, Mapa *const m1);
char menu();

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

int main(){
	SetConsoleTextAttribute(console,15);
	cout << "Digite o nome do zumbi: ";
	string nome;
	cin >> nome;
	
	ZumbiHunter z1(nome,5000,300);
	
    Mapa m1(&z1);
    
	m1.iniciarMapa();

	int c=0;
	char op;
	do{
	op=menu();
	escolha(op,&c,&z1,&m1);
    }while(op!=666);
}	

void escolha(char op, int *c, ZumbiHunter *const z1, Mapa *const m1){
	char d, opt;
    system("cls");
	switch(op){
		case '1':
			system("cls");
			m1->exibirMapa();
			cout << "\nDeseja voltar ao menu? (s=1/n=0): ";
			opt=getche();
	        system("cls");
            if (opt=='0')
              exit(0);
			break;
		case '2':
			system("cls");
			m1->exibirMapa();
			cout << "\nUse o numpad para andar: ";
			d=getche();
			m1->andarMapa(d,c);
			break;
		case '3':
            system("cls");
            cout << *z1;
			cout << "\n\n\nDeseja voltar ao menu? (s=1/n=0): ";
			opt=getche();
	        system("cls");
            if (opt=='0')
              exit(0);
			break;
        case '4':
			m1->exibirDia();
			cout << "\nDeseja voltar ao menu? (s=1/n=0): ";
			opt=getche();
	        system("cls");
            if (opt=='0')
              exit(0);
			break;
        case '5':
            system("cls");
			Mapa::exibirHumanos();
			cout << "\nDeseja voltar ao menu? (s=1/n=0): ";
			opt=getche();
	        system("cls");
            if (opt=='0')
              exit(0);
			break;
        case '6':
			exit(0);
			break;
		default:
			cout << "Comando invalido";
	}
}

char menu(){
	char op;
	system("cls");
	cout << "Escolha uma opcao:\n\n";
	cout << "1-Ver mapa; \n";
	cout << "2-Andar; \n";
    cout << "3-Exibir status; \n";
	cout << "4-Exibir dia; \n";
    cout << "5-Exibir o numero de sobreviventes; \n";
	cout << "6-Sair. \n\n";
	op=getche();
	return op;
}
