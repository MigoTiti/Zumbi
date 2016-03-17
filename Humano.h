#ifndef HUMANO_H
#define HUMANO_H

#include <iostream>

using namespace std;

class Humano{
	public:
        Humano(int, int);
        Humano(const Humano &);
		virtual void incrementarVida(int) = 0;        
	protected:
		int strength, vida;
};

#endif
