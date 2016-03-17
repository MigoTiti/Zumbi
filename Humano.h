#ifndef HUMANO_H
#define HUMANO_H

#include <iostream>

using namespace std;

class Humano{
	public:
        Humano(int, int);
        Humano(const Humano &);
		//virtual int atacarHumano(bool,int,int) = 0;        
	protected:
		int strength, vida;
};

#endif
