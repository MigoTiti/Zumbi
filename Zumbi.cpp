#include <iostream>
#include <conio.h>
#include <windows.h>
#include <random>
#include <ctime>
#include "Zumbi.h"

#define tam 30
#define humans 8

using namespace std;

void escolha2(int opt);
void escolha(int op, Zumbi z1, char mapa[tam][tam]);
int menu(void);
void iniciarMapa(char mapa[tam][tam]);
void exibirMapa(char mapa[tam][tam]);
void andarMapa(char mapa[tam][tam], char d);
void verificarMapa(char mapa[tam][tam], char d, int x, int y, int *l, int *c);
void procurarMapa(char mapa[tam][tam], int *l, int *c);
int atacarHumano(Zumbi z1);

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

int atacarHumano(Zumbi z1){
	int VidaH=4000, Sh=200, Sz=300, opt, maismenos, atk;
	float hp;
	hp=z1.getHealth();
	do{
		system("cls");
		cout << "HP humano: " << VidaH << "    ";
		cout << "HP " << z1.getName() << ": " << hp;
		cout << "\n1- Ataque normal;";
		cout << "\n2- Mordida (custa pontos de vida);\n\n";
		cin >> opt;
		switch(opt){
			case 1:
				maismenos=rand() % 2;
				atk=rand() % 201;
				if (maismenos==1){
					VidaH=VidaH-(Sz+atk);
					if (hp<0){
						hp=0;
					}
				}else{
					VidaH=VidaH-(Sh-atk);
					if (hp<0){
						hp=0;
					}
				}
				break;
			case 2:
				hp=hp-200;
				maismenos=rand() % 2;
				atk=rand() % 201;
				if (maismenos==1){
					VidaH=VidaH-(Sz+atk)-100;
					if (hp<0){
						hp=0;
					}
				}else{
					VidaH=VidaH-(Sz-atk)-100;
					if (hp<0){
						hp=0;
					}
				}
				break;
		}
				maismenos=rand() % 2;
				atk=rand() % 101;
				if (maismenos==1){
					hp=hp-(Sh+atk);
					if (hp<0){
						hp=0;
					}
					z1.setHealth(hp);
				}else{
					hp=hp-(Sh-atk);
					if (hp<0){
						hp=0;
					}
					z1.setHealth(hp);
				}
	}while((hp>0) && (VidaH>0));
	if (hp==0){
	return 0;
	}else{
	return 1;
    }
}

void verificarMapa(char mapa[tam][tam], char d, int x, int y, int *l, int *c, Zumbi z1){
	int i, j, v, opt;    
	switch(d){
		case '1':
			if(mapa[x+1][y-1]=='1'){
			    mapa[x+1][y-1]='Z';
			    mapa[x][y]='1';
			    *l=x+1;
			    *c=y-1;
			}else if(mapa[x+1][y-1]=='H'){
				v=atacarHumano(z1);
				if (v==1){
			    mapa[x+1][y-1]='Z';
			    }else{
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
			    cin >> opt;
			    exit(0);
			    }
			}
		    break;
		case '2':
		case 's':
		case 'S':
			if(mapa[x+1][y]=='1'){
			    mapa[x+1][y]='Z';
			    mapa[x][y]='1';
			    *l=x+1;
			}else if(mapa[x+1][y]=='H'){
				v=atacarHumano(z1);
				if (v==1){
			    mapa[x+1][y]='Z';
			    }else{
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
			    cin >> opt;
			    exit(0);
			    }
		    }
		    break;
		case '3':
			if(mapa[x+1][y+1]=='1'){
			    mapa[x+1][y+1]='Z';
			    mapa[x][y]='1';
			    *l=x+1;
			    *c=y+1;
			}else if(mapa[x+1][y+1]=='H'){
				v=atacarHumano(z1);
				if (v==1){
			    mapa[x+1][y+1]='Z';
			    }else{
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
			    cin >> opt;
			    exit(0);
			    }
		    }
		    break;
		case '4':
		case 'a':
		case 'A':
			if(mapa[x][y-1]=='1'){
			    mapa[x][y-1]='Z';
			    mapa[x][y]='1';
			    *c=y-1;
			}else if(mapa[x][y-1]=='H'){
				v=atacarHumano(z1);
				if (v==1){
			    mapa[x][y-1]='Z';
			    }else{
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
			    cin >> opt;
			    exit(0);
			    }
		    }
		    break;
		case '6':
		case 'd':
		case 'D':
			if(mapa[x][y+1]=='1'){
			    mapa[x][y+1]='Z';
			    mapa[x][y]='1';
			    *c=y+1;
			}else if(mapa[x][y+1]=='H'){
				v=atacarHumano(z1);
				if (v==1){
			    mapa[x][y+1]='Z';
			    }else{
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
			    cin >> opt;
			    exit(0);
			    }
		    }
		    break;
		case '7':
			if(mapa[x-1][y-1]=='1'){
			    mapa[x-1][y-1]='Z';
			    mapa[x][y]='1';
			    *l=x-1;
			    *c=y-1;
			}else if(mapa[x-1][y-1]=='H'){
				v=atacarHumano(z1);
				if (v==1){
			    mapa[x-1][y-1]='Z';
			    }else{
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
			    cin >> opt;
			    exit(0);
			    }
		    }
		    break;
		case '8':
		case 'w':
		case 'W':
			if(mapa[x-1][y]=='1'){
			    mapa[x-1][y]='Z';
			    mapa[x][y]='1';
			    *l=x-1;
			}else if(mapa[x-1][y]=='H'){
				v=atacarHumano(z1);
				if (v==1){
			    mapa[x-1][y]='Z';
			    }else{
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
			    cin >> opt;
			    exit(0);
			    }
		    }
		    break;
		case '9':
			if(mapa[x-1][y+1]=='1'){
			    mapa[x-1][y+1]='Z';
			    mapa[x][y]='1';
			    *l=x-1;
			    *c=x+1;
			}else if(mapa[x-1][y+1]=='H'){
				v=atacarHumano(z1);
				if (v==1){
			    mapa[x-1][y+1]='Z';
			    }else{
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
			    cin >> opt;
			    exit(0);
			    }
		    }
		    break;
		default:
			cout << "Posicao invalida.\n";
			break;
	}	
}

void procurarMapa(char mapa[tam][tam], int *l, int *c){
	int i, j;
	for (i=0;i<=(tam-1);i++){
		for (j=0;j<=(tam-1);j++){
			if(mapa[i][j]=='Z'){
				*l=i;
				*c=j;
			}
		}
	}
}	

void andarMapa(char mapa[tam][tam], char d, Zumbi z1){
	int opt, x, y;
	    procurarMapa(mapa,&x,&y);
	    do{
	    system("cls");
		verificarMapa(mapa,d,x,y,&x,&y,z1);
		exibirMapa(mapa);
		d=getche();
	    }while(d!='0');
		cout << "\nDeseja voltar ao menu? (s=1/n=0): ";
		cin >> opt;
		escolha2(opt);
}

void exibirMapa(char mapa[tam][tam]){
	int i, j;
	for (i=0;i<=(tam-1);i++){
		for (j=0;j<=(tam-1);j++){
			if(mapa[i][j]=='Z'){
				SetConsoleTextAttribute(console,12);
				cout << " " << mapa[i][j];
				SetConsoleTextAttribute(console,15);
			}else if (mapa[i][j]=='H'){
				SetConsoleTextAttribute(console,9);
				cout << " " << mapa[i][j];
				SetConsoleTextAttribute(console,15);
			}else if (mapa[i][j]=='0'){
				SetConsoleTextAttribute(console,34);
				cout << " " << mapa[i][j];
				SetConsoleTextAttribute(console,15);
			}else{
				SetConsoleTextAttribute(console,0);
				cout << " " << mapa[i][j];
				SetConsoleTextAttribute(console,15);
			}
		}
		cout << "\n";
	}
}

void iniciarMapa(char mapa[tam][tam]){
	int i, j, c;
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
	mapa[15][0]='Z';
	for (c=0;c<=(humans-1);c++){
		i=rand() % 30;
		j=rand() % 30;
		if (((i==15) && (j==0)) || (mapa[i][j]=='0')){
			c--;
		}else{
			mapa[i][j]='H';
		}
	}
}

void escolha(int op, Zumbi z1, char mapa[tam][tam]){
	int opt, i, j;
	char d;
	switch(op){
		case 1:
			system("cls");
			cout << "Nome: " << z1.getName();
			cout << "\nPontos de vida: " << z1.getHealth();
			cout << "\nVelocidade: " << z1.getSpeed() << "\n";
			cout << "\nDeseja voltar ao menu? (s=1/n=0): ";
			cin >> opt;
			escolha2(opt);
			break;
		case 2:
			system("cls");
			exibirMapa(mapa);
			cout << "\nDeseja voltar ao menu? (s=1/n=0): ";
			cin >> opt;
			escolha2(opt);
			break;
		case 3:
			system("cls");
			exibirMapa(mapa);
			cout << "\nUse o numpad para andar: ";
			d=getche();
			andarMapa(mapa,d,z1);
			break;
		case 4:
			exit(0);
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
	cout << "4-Sair. \n\n";
	cin >> op;
	return op;
}

int main(){
	SetConsoleTextAttribute(console,15);
	srand(time(NULL));
	cout << "Digite o nome do zumbi: ";
	string nome1;
	cin >> nome1;
	
	Zumbi z1(nome1);
	z1.setSpeed(1);
	z1.setHealth(5000);
	
	char mapa[tam][tam];
	iniciarMapa(mapa);
	
	int op;
	do{
	op=menu();
	escolha(op,z1,mapa);
    }while(op!=4);
}

Zumbi::Zumbi(string name){
	nome=name;
}

void Zumbi::setName(string name){
	nome=name;
}

void Zumbi::setHealth(float x){
	if (x>=0)
	HP=x;
}

void Zumbi::setSpeed(int s){
	if (s>0)
	velocidade=s;
}

float Zumbi::getHealth(){
	return HP;
}

string Zumbi::getName(){
	return nome;
}

int Zumbi::getSpeed(){
	return velocidade;
}
