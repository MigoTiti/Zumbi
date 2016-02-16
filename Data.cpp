#include "Data.h"
#include <iostream>

using namespace std;

Data::Data(int dia, int mes, int ano){
    this->mes = mes;
    this->ano = ano;
    this->dia = checarDia(dia);
}

Data::~Data(){
}

void Data::incrementarDia(){
    int fev;
    
    if ((this->ano % 400 == 0) || ((this->ano % 4 == 0) && (this->ano % 100 != 0)))
    fev = 29;
    else
    fev = 28;
    
    static const int diasPorMes[13] = {0,31,fev,31,30,31,30,31,31,30,31,30,31};
    
    if (dia < diasPorMes[this->mes])
        this->dia++;
    else if (dia == diasPorMes[this->mes]){
        this->dia = 1;
        if (mes == 12){
            this->mes = 1;
            this->ano++;
        }else
        this->mes++;
    }
}

int Data::checarDia(int dia) const{
    static const int diasPorMes[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    if ((dia > 0) && (dia <= diasPorMes[this->mes]))
        return dia;
        
    if ((this->mes == 2) && (dia == 29) && ((ano % 400 == 0) || ((this->ano % 4 == 0) && (this->ano % 100 != 0))))
        return dia;
        
    cout << "Dia invalido. \n";
    return 1;
}

void Data::imprimir() const{
    cout << dia << "/" << mes << "/" << ano;
}

