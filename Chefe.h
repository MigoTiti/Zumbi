#ifndef CHEFE_H
#define CHEFE_H

class Chefe
{
public:
    Chefe();
    ~Chefe();
    void incrementarVida();
    void decrementarStrength();
    int getVida();
    int getStrength();
private:
    int hp;
    int strength;
};

#endif