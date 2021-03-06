#ifndef ZUMBI_H
#define ZUMBI_H

#include "Humano.h"
#include <string>
#include <iostream>

using namespace std;

class Zumbi : public Humano{
	friend ostream& operator<<(ostream &, const Zumbi &);
	public:
        Zumbi();
        Zumbi(const Zumbi &);
		Zumbi(const string &, int, int);       
		int atacarHumano(bool,int,int);
		void pegarItem(char);
		string getItem(int);
		bool operator==(const Zumbi &) const;
        void operator=(const Zumbi &);
	protected:
		void setC();
		void setA();      
		string nome;
		bool capacete, armadura;
        string *itens;
        int numeroItens=0;
};

#endif
