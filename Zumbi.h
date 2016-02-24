#ifndef ZUMBI_H
#define ZUMBI_H

#include <string>
#include <iostream>

using namespace std;

class Zumbi{
	friend ostream& operator<<(ostream &, const Zumbi &);
	public:
        Zumbi();
        Zumbi(const Zumbi &);
		Zumbi(const string &);       
		int atacarHumano(bool,int,int);
		void pegarItem(char);
		string getItem(int);
		bool operator==(const Zumbi &) const;
	private:
		void setC();
		void setA();      
		string nome;
		int strength, vida;
		bool capacete, armadura;
        string *itens;
        int numeroItens=0;
};

#endif
