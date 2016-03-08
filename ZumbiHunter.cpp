#include "ZumbiHunter.h"

ZumbiHunter::ZumbiHunter():Zumbi("Sem nome",2000,200){
	this->velocidade = 2;
}

ZumbiHunter::ZumbiHunter(const string &nome, int vida, int strength):Zumbi(nome,vida,strength){
	this->velocidade = 2;
}

ZumbiHunter::ZumbiHunter(const ZumbiHunter &z1):Zumbi(static_cast<Zumbi>(z1)){
	this->velocidade = z1.velocidade;
}

ostream& operator<<(ostream &saida, const ZumbiHunter &z1){
	saida << static_cast <Zumbi> (z1);
	saida << "\nVelocidade: " << z1.velocidade;
}

void ZumbiHunter::operator=(const ZumbiHunter &z1){
	static_cast<Zumbi&> (*this) = static_cast <Zumbi>(z1);
    this->velocidade = z1.velocidade;
}

bool ZumbiHunter::operator==(const ZumbiHunter &z1){
	if((static_cast<Zumbi&> (*this) == static_cast <Zumbi>(z1)) && this->velocidade == z1.velocidade)
	    return true;
	else
	    return false;
}
