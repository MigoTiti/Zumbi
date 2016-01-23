#include "Mapa.h"
#include <conio.h>
#include <windows.h>
#include <random>
#include <ctime>
#include <iostream>

Mapa::Mapa(int tamanho){
	tam=tamanho;
}

Mapa1::Mapa1(int tamanho):Mapa(tam){
	tam=tamanho;
}

Mapa2::Mapa2(int tamanho):Mapa(tam){
	tam=tamanho;
}

void Mapa2::iniciarMapa(Mapa2 *m2, int humans){
	int i, j, c;
	srand (time(NULL));
	for (i=0;i<=29;i++){
		for (j=0;j<=29;j++){
			mapa[i][j]='1';
		}
	}
	for (i=19;i<=29;i++){
		for (j=0;j<=9;j++){
			mapa[i][j]='0';
		}
	}
	for (i=3;i<=26;i++){
		for (j=13;j<=18;j++){
			mapa[i][j]='0';
		}
	}
	for (i=24;i<=29;i++){
		for (j=24;j<=29;j++){
			mapa[i][j]='0';
		}
	}
	for (i=0;i<=9;i++){
		for (j=0;j<=9;j++){
			mapa[i][j]='0';
		}
	}
	for (i=0;i<=9;i++){
        mapa[i][21]='0';
	}
	for (j=23;j<=29;j++){
		mapa[9][j]='0';
	}
	for (i=19;i<=23;i++){
		mapa[i][29]='0';
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
	do{
		i=rand() % 30;
		j=rand() % 30;
		if (((i==15) && (j==0)) || (mapa[i][j]=='0') || (mapa[i][j]=='H')){
			c=1;
		}else{
			mapa[i][j]='C';
			c=0;
		}
	}while(c>0);
	do{
		i=rand() % 30;
		j=rand() % 30;
		if (((i==15) && (j==0)) || (mapa[i][j]=='0') || (mapa[i][j]=='H') || (mapa[i][j] == 'C')){
			c=1;
		}else{
			mapa[i][j]='A';
			c=0;
		}
	}while(c>0);
}

void Mapa2::exibirMapa(Mapa2 *m2){
	int i, j;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
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
			}else if (mapa[i][j]=='A'){
				SetConsoleTextAttribute(console,14);
				cout << " " << mapa[i][j];
				SetConsoleTextAttribute(console,15);
			}else if (mapa[i][j]=='C'){
			    SetConsoleTextAttribute(console,14);
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

void Mapa2::andarMapa(Mapa2 *m2, char d, Zumbi *z1){
	int opt, x, y;
	    procurarMapa(m2,&x,&y);
	    do{
	    system("cls");
		verificarMapa(m2,d,x,y,&x,&y,z1);
		exibirMapa(m2);
		d=getche();
	    }while(d!='0');
        exit(0);
}

void Mapa2::procurarMapa(Mapa2 *m2, int *l, int *c){
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

void Mapa2::verificarMapa(Mapa2 *m2, char d, int x, int y, int *l, int *c, Zumbi *z1){
	int i, j, v, opt;    
	switch(d){
		case '1':
			if(mapa[x+1][y-1]=='1'){
			    mapa[x+1][y-1]='Z';
			    mapa[x][y]='1';
			    *l=x+1;
			    *c=y-1;
			}else if(mapa[x+1][y-1]=='H'){
				v=z1->atacarHumano();
				if (v==1){
			    mapa[x+1][y-1]='Z';
			    }else if (v==0){
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
                }
			}else if((mapa[x+1][y-1]=='A') || (mapa[x+1][y-1]=='C')){
				z1->pegarItem(mapa[x+1][y-1],z1);
				mapa[x+1][y-1]='1';
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
				v=z1->atacarHumano();
				if (v==1){
			    mapa[x+1][y]='Z';
			    }else if (v==0){
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
                }
		    }else if((mapa[x+1][y]=='A') || (mapa[x+1][y]=='C')){
				z1->pegarItem(mapa[x+1][y],z1);
				mapa[x+1][y]='1';
			}
		    break;
		case '3':
			if(mapa[x+1][y+1]=='1'){
			    mapa[x+1][y+1]='Z';
			    mapa[x][y]='1';
			    *l=x+1;
			    *c=y+1;
			}else if(mapa[x+1][y+1]=='H'){
				v=z1->atacarHumano();
				if (v==1){
			    mapa[x+1][y+1]='Z';
			    }else if (v==0){
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
                }
		    }else if((mapa[x+1][y+1]=='A') || (mapa[x+1][y+1]=='C')){
				z1->pegarItem(mapa[x+1][y+1],z1);
				mapa[x+1][y+1]='1';
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
				v=z1->atacarHumano();
				if (v==1){
			    mapa[x][y-1]='Z';
			    }else if (v==0){
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
                }
		    }else if((mapa[x][y-1]=='A') || (mapa[x][y-1]=='C')){
				z1->pegarItem(mapa[x][y-1],z1);
				mapa[x][y-1]='1';
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
				v=z1->atacarHumano();
				if (v==1){
			    mapa[x][y+1]='Z';
			    }else if (v==0){
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
                }
		    }else if((mapa[x][y+1]=='A') || (mapa[x][y+1]=='C')){
				z1->pegarItem(mapa[x][y+1],z1);
				mapa[x][y+1]='1';
			}
		    break;
		case '7':
			if(mapa[x-1][y-1]=='1'){
			    mapa[x-1][y-1]='Z';
			    mapa[x][y]='1';
			    *l=x-1;
			    *c=y-1;
			}else if(mapa[x-1][y-1]=='H'){
				v=z1->atacarHumano();
				if (v==1){
			    mapa[x-1][y-1]='Z';
			    }else if (v==0){
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
                }
		    }else if((mapa[x-1][y-1]=='A') || (mapa[x-1][y-1]=='C')){
				z1->pegarItem(mapa[x-1][y-1],z1);
				mapa[x-1][y-1]='1';
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
				v=z1->atacarHumano();
				if (v==1){
			    mapa[x-1][y]='Z';
			    }else if (v==0){
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
                }
		    }else if((mapa[x-1][y]=='A') || (mapa[x-1][y]=='C')){
				z1->pegarItem(mapa[x-1][y],z1);
                mapa[x-1][y]='1';
			}
		    break;
		case '9':
			if(mapa[x-1][y+1]=='1'){
			    mapa[x-1][y+1]='Z';
			    mapa[x][y]='1';
			    *l=x-1;
			    *c=x+1;
			}else if(mapa[x-1][y+1]=='H'){
				v=z1->atacarHumano();
				if (v==1){
			    mapa[x-1][y+1]='Z';
			    }else if (v==0){
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
			    }
		    }else if((mapa[x-1][y+1]=='A') || (mapa[x-1][y+1]=='C')){
				z1->pegarItem(mapa[x-1][y+1],z1);
				mapa[x-1][y+1]='1';
			}
		    break;
		default:
			cout << "Posicao invalida.\n";
			break;
	}	
}

void Mapa1::iniciarMapa(Mapa1 *m1, int humans){
	int i, j, c;
	srand (time(NULL));
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
	do{
		i=rand() % 30;
		j=rand() % 30;
		if (((i==15) && (j==0)) || (mapa[i][j]=='0') || (mapa[i][j]=='H')){
			c=1;
		}else{
			mapa[i][j]='C';
			c=0;
		}
	}while(c>0);
	do{
		i=rand() % 30;
		j=rand() % 30;
		if (((i==15) && (j==0)) || (mapa[i][j]=='0') || (mapa[i][j]=='H') || (mapa[i][j] == 'C')){
			c=1;
		}else{
			mapa[i][j]='A';
			c=0;
		}
	}while(c>0);
}

void Mapa1::exibirMapa(Mapa1 *m1){
	int i, j;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
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
			}else if (mapa[i][j]=='A'){
				SetConsoleTextAttribute(console,14);
				cout << " " << mapa[i][j];
				SetConsoleTextAttribute(console,15);
			}else if (mapa[i][j]=='C'){
			    SetConsoleTextAttribute(console,14);
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

void Mapa1::andarMapa(Mapa1 *m1, char d, Zumbi *z1, int *c){
	int opt, x, y;
	    procurarMapa(m1,&x,&y);
	    do{
	    system("cls");
		verificarMapa(m1,d,x,y,&x,&y,z1,c);
		exibirMapa(m1);
		if (*c==8){
			d='0';
		}else{
			d=getche();
		}
	    }while(d!='0');
}

void Mapa1::procurarMapa(Mapa1 *m1, int *l, int *c){
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

void Mapa1::verificarMapa(Mapa1 *m1, char d, int x, int y, int *l, int *c, Zumbi *z1, int *c1){
	int i, j, v, opt;    
	switch(d){
		case '1':
			if(mapa[x+1][y-1]=='1'){
			    mapa[x+1][y-1]='Z';
			    mapa[x][y]='1';
			    *l=x+1;
			    *c=y-1;
			}else if(mapa[x+1][y-1]=='H'){
				v=z1->atacarHumano();
				if (v==1){
				*c1=*c1+1;
			    mapa[x+1][y-1]='Z';
			    }else if (v==0){
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
                }
			}else if((mapa[x+1][y-1]=='A') || (mapa[x+1][y-1]=='C')){
				z1->pegarItem(mapa[x+1][y-1],z1);
				mapa[x+1][y-1]='1';
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
				v=z1->atacarHumano();
				if (v==1){
				*c1=*c1+1;
			    mapa[x+1][y]='Z';
			    }else if (v==0){
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
                }
		    }else if((mapa[x+1][y]=='A') || (mapa[x+1][y]=='C')){
				z1->pegarItem(mapa[x+1][y],z1);
				mapa[x+1][y]='1';
			}
		    break;
		case '3':
			if(mapa[x+1][y+1]=='1'){
			    mapa[x+1][y+1]='Z';
			    mapa[x][y]='1';
			    *l=x+1;
			    *c=y+1;
			}else if(mapa[x+1][y+1]=='H'){
				v=z1->atacarHumano();
				if (v==1){
				*c1=*c1+1;
			    mapa[x+1][y+1]='Z';
			    }else if (v==0){
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
                }
		    }else if((mapa[x+1][y+1]=='A') || (mapa[x+1][y+1]=='C')){
				z1->pegarItem(mapa[x+1][y+1],z1);
				mapa[x+1][y+1]='1';
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
				v=z1->atacarHumano();
				if (v==1){
				*c1=*c1+1;
			    mapa[x][y-1]='Z';
			    }else if (v==0){
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
                }
		    }else if((mapa[x][y-1]=='A') || (mapa[x][y-1]=='C')){
				z1->pegarItem(mapa[x][y-1],z1);
				mapa[x][y-1]='1';
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
				v=z1->atacarHumano();
				if (v==1){
				*c1=*c1+1;
			    mapa[x][y+1]='Z';
			    }else if (v==0){
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
                }
		    }else if((mapa[x][y+1]=='A') || (mapa[x][y+1]=='C')){
				z1->pegarItem(mapa[x][y+1],z1);
				mapa[x][y+1]='1';
			}
		    break;
		case '7':
			if(mapa[x-1][y-1]=='1'){
			    mapa[x-1][y-1]='Z';
			    mapa[x][y]='1';
			    *l=x-1;
			    *c=y-1;
			}else if(mapa[x-1][y-1]=='H'){
				v=z1->atacarHumano();
				if (v==1){
				*c1=*c1+1;
			    mapa[x-1][y-1]='Z';
			    }else if (v==0){
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
                }
		    }else if((mapa[x-1][y-1]=='A') || (mapa[x-1][y-1]=='C')){
				z1->pegarItem(mapa[x-1][y-1],z1);
				mapa[x-1][y-1]='1';
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
				v=z1->atacarHumano();
				if (v==1){
				*c1=*c1+1;
			    mapa[x-1][y]='Z';
			    }else if (v==0){
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
                }
		    }else if((mapa[x-1][y]=='A') || (mapa[x-1][y]=='C')){
				z1->pegarItem(mapa[x-1][y],z1);
                mapa[x-1][y]='1';
			}
		    break;
		case '9':
			if(mapa[x-1][y+1]=='1'){
			    mapa[x-1][y+1]='Z';
			    mapa[x][y]='1';
			    *l=x-1;
			    *c=x+1;
			}else if(mapa[x-1][y+1]=='H'){
				v=z1->atacarHumano();
				if (v==1){
				*c1=*c1+1;
			    mapa[x-1][y+1]='Z';
			    }else if (v==0){
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
			    }
		    }else if((mapa[x-1][y+1]=='A') || (mapa[x-1][y+1]=='C')){
				z1->pegarItem(mapa[x-1][y+1],z1);
				mapa[x-1][y+1]='1';
			}
		    break;
		default:
			cout << "Posicao invalida.\n";
			break;
	}	
}