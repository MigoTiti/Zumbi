#include "ZumbiCharger.h"
#include <random>
#include <ctime>
#include <conio.h>

#define vh 4000

ZumbiCharger::ZumbiCharger():Zumbi("Sem nome",5000,400){
    this->stamina = 50;
}

ZumbiCharger::ZumbiCharger(const string &nome, int vida, int strength):Zumbi(nome,vida,strength){
    this->stamina = 50;
}

ZumbiCharger::ZumbiCharger(const ZumbiCharger &z1):Zumbi(z1.nome,z1.vida,z1.strength){
	this->stamina = z1.stamina;
}

void ZumbiCharger::operator=(const ZumbiCharger &z1){
	this->nome = z1.nome;
    this->armadura=z1.armadura;
    this->capacete=z1.capacete;
    this->numeroItens=z1.numeroItens;
    
	this->vida=z1.vida;
    this->strength=z1.strength; 
    
    this->itens.clear();
    this->itens = vector<string>(z1.itens);
    
    this->stamina = z1.stamina;
}

ostream& operator<<(ostream &saida, const ZumbiCharger &z1){
	saida <<  z1.nome;
	saida << "\nPontos de vida: " << z1.vida;
    saida << "\nForca: " << z1.strength;
    
    for(int i=0;i<z1.numeroItens;i++){
        saida << "\nPossui " << z1.itens.at(i) << ";";
    }
    
	saida << "\nStamina: " << z1.stamina;
	return saida;
}

bool ZumbiCharger::operator==(const ZumbiCharger &z1){
	if(this->nome != z1.nome)
        return false;
    if(this->vida != z1.vida)
        return false;
    if(this->armadura != z1.armadura)
        return false;
    if(this->capacete != z1.capacete)
        return false;
    if(this->strength != z1.strength)
        return false;
    if(this->numeroItens != z1.numeroItens)
        return false;
    if(this->stamina != z1.stamina)
        return false;
    for(int i=0;i<this->numeroItens;i++){
    	if(this->itens.at(i) != z1.itens.at(i))
    	    return false;
	}
	return true;
}

int ZumbiCharger::atacarHumano(bool chefe, int vidaC, int strengthC){
	int VidaH=vh, VidaZ=vida, Sh=200, Sz=strength, maismenos, atk, total;
	char opt;
    string nomeH = "Humano";
    if (chefe){
        VidaH = vidaC;
        Sh = strengthC;
        nomeH = "Chefe";
    }
	srand(time(NULL));
	do{
		system("cls");
		cout << "HP " << nomeH << ": " << VidaH << "    ";
		cout << "HP " << nome << ": " << VidaZ;
		cout << "\n1- Ataque normal;";
		cout << "\n2- Ataque carregado (custa stamina);";
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
				cout << nome << " usou Ataque normal, causando " << total << " de dano.";
				do{
					cin.get();
			    }while(cin.get()!='\n');
				break;
			case '2':
				stamina-=10;             
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
				cout << nome << " usou Ataque carregado, causando " << total << " de dano e gastando 10 de stamina";
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
			VidaZ=VidaZ-total;
			if (VidaZ<0){
				VidaZ=0;
			}
		}else{
			total=Sh-atk;
			VidaZ=VidaZ-total;
			if (VidaZ<0){
				VidaZ=0;
			}
		}
		cout << nomeH <<" usou Ataque normal, causando " << total << " de dano.";
		do{
			cin.get();
	    }while(cin.get()!='\n');
	}while((VidaZ>0) && (VidaH>0));
	if (VidaZ==0){
        system("cls");
	    return 0;
	}else{
        system("cls");
	    return 1;
    }
}