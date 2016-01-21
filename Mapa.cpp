#include "Mapa.h"
#include <conio.h>
#include <windows.h>
#include <iostream>

Mapa::Mapa(int tamanho){
	tam=tamanho;
}

void Mapa::iniciarMapa(Mapa m1, int humans){
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
	for (c=0;c<1;c++){
		i=rand() % 30;
		j=rand() % 30;
		if (((i==15) && (j==0)) || (mapa[i][j]=='0') || (mapa[i][j]=='H')){
			c--;
		}else{
			mapa[i][j]='C';
		}
	}
	for (c=0;c<1;c++){
		i=rand() % 30;
		j=rand() % 30;
		if (((i==15) && (j==0)) || (mapa[i][j]=='0') || (mapa[i][j]=='H') || (mapa[i][j] == 'C')){
			c--;
		}else{
			mapa[i][j]='A';
		}
	}
}

void Mapa::exibirMapa(Mapa m1){
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

void Mapa::andarMapa(Mapa m1, char d, Zumbi z1){
	int opt, x, y;
	    procurarMapa(m1,&x,&y);
	    do{
	    system("cls");
		verificarMapa(m1,d,x,y,&x,&y,z1);
		exibirMapa(m1);
		d=getche();
	    }while(d!='0');
}

void Mapa::procurarMapa(Mapa m1, int *l, int *c){
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

void Mapa::verificarMapa(Mapa m1, char d, int x, int y, int *l, int *c, Zumbi z1){
	int i, j, v, opt;    
	switch(d){
		case '1':
			if(mapa[x+1][y-1]=='1'){
			    mapa[x+1][y-1]='Z';
			    mapa[x][y]='1';
			    *l=x+1;
			    *c=y-1;
			}else if(mapa[x+1][y-1]=='H'){
				v=z1.atacarHumano();
				if (v==1){
			    mapa[x+1][y-1]='Z';
			    }else{
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
			    }
			}else if((mapa[x+1][y-1]=='A') || (mapa[x+1][y-1]=='C')){
				z1.pegarItem(mapa[x+1][y-1]);
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
				v=z1.atacarHumano();
				if (v==1){
			    mapa[x+1][y]='Z';
			    }else{
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
			    cin.get();
			    exit(0);
			    }
		    }else if((mapa[x+1][y]=='A') || (mapa[x+1][y]=='C')){
				z1.pegarItem(mapa[x+1][y]);
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
				v=z1.atacarHumano();
				if (v==1){
			    mapa[x+1][y+1]='Z';
			    }else{
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
			    }
		    }else if((mapa[x+1][y+1]=='A') || (mapa[x+1][y+1]=='C')){
				z1.pegarItem(mapa[x+1][y+1]);
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
				v=z1.atacarHumano();
				if (v==1){
			    mapa[x][y-1]='Z';
			    }else{
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
			    }
		    }else if((mapa[x][y-1]=='A') || (mapa[x][y-1]=='C')){
				z1.pegarItem(mapa[x][y-1]);
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
				v=z1.atacarHumano();
				if (v==1){
			    mapa[x][y+1]='Z';
			    }else{
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
			    }
		    }else if((mapa[x][y+1]=='A') || (mapa[x][y+1]=='C')){
				z1.pegarItem(mapa[x][y+1]);
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
				v=z1.atacarHumano();
				if (v==1){
			    mapa[x-1][y-1]='Z';
			    }else{
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
			    }
		    }else if((mapa[x-1][y-1]=='A') || (mapa[x-1][y-1]=='C')){
				z1.pegarItem(mapa[x-1][y-1]);
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
				v=z1.atacarHumano();
				if (v==1){
			    mapa[x-1][y]='Z';
			    }else{
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
			    }
		    }else if((mapa[x-1][y]=='A') || (mapa[x-1][y]=='C')){
				z1.pegarItem(mapa[x-1][y]);
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
				v=z1.atacarHumano();
				if (v==1){
			    mapa[x-1][y+1]='Z';
			    }else{
			    cout << "Voce perdeu. Aperte qualquer botao para sair: ";
				cin.get();
			    exit(0);
			    }
		    }else if((mapa[x-1][y+1]=='A') || (mapa[x-1][y+1]=='C')){
				z1.pegarItem(mapa[x-1][y+1]);
				mapa[x-1][y+1]='1';
			}
		    break;
		default:
			cout << "Posicao invalida.\n";
			break;
	}	
}

