#ifndef ZUMBIHUNTER_H
#define ZUMBIHUNTER_H

#include "Zumbi.h"
#include <string>
#include <iostream>

using namespace std;

class ZumbiHunter : public Zumbi{
	friend ostream& operator<<(ostream &, const ZumbiHunter &);
	public:
        ZumbiHunter();
        ZumbiHunter(const ZumbiHunter &);
		ZumbiHunter(const string &, int, int);       
		bool operator==(const ZumbiHunter &);
        void operator=(const ZumbiHunter &);
	protected:
		int velocidade;
};

#endif
