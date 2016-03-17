#ifndef CHEFE_H
#define CHEFE_H
#include "Humano.h"

class Chefe : public Humano
{
	friend ostream& operator<<(ostream &, const Chefe &);
public:
    Chefe();
    Chefe(const Chefe &c);
    ~Chefe();
    virtual void incrementarVida(int);
    void decrementarStrength();
    int getVida();
    int getStrength();
    void operator=(const Chefe &);
private:
    bool arma;
};

#endif
