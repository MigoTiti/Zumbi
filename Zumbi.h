#ifndef ZUMBI_H
#define ZUMBI_H

#include <string>

using namespace std;

class Zumbi{
	public:
        Zumbi();
        Zumbi(const Zumbi &);
		Zumbi(const string &);
        void exibirStatus() const;        
		int atacarHumano(bool,int,int);
		void pegarItem(char);
	private:
		void setC();
		void setA();      
		string nome;
		int strength, hp;
		bool capacete, armadura;
};

#endif