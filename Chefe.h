#ifndef CHEFE_H
#define CHEFE_H
#include "Humano.h"

class Chefe : public Humano
{
public:
    Chefe();
    ~Chefe();
    void incrementarVida();
    void decrementarStrength();
    int getVida();
    int getStrength();
private:
    bool arma;
};

#endif
