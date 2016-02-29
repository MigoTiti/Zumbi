#ifndef HUMANO_H
#define HUMANO_H

#include <iostream>

using namespace std;

class Humano{
	friend ostream& operator<<(ostream &, const Humano &);
	public:
        Humano(int, int);
        Humano(const Humano &);
        void operator=(const Humano &);        
	protected:
		int strength, vida;
};

#endif
