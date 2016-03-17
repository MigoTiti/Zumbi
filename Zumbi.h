#ifndef ZUMBI_H
#define ZUMBI_H

#include "Humano.h"
#include <string>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Zumbi : public Humano{
	public:
        Zumbi();
        Zumbi(const Zumbi &);
		Zumbi(const string &, int, int);       
		virtual int atacarHumano(bool,int,int) = 0;
        virtual void incrementarVida(int);
		void pegarItem(char);
		string getItem(int);
		bool operator==(const Zumbi &) const;
        void operator=(const Zumbi &);
	protected:
		void setC();
		void setA();      
		string nome;
		bool capacete, armadura;
        vector<string> itens;
        int numeroItens=0;
};

#endif
