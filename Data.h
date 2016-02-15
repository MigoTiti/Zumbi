#ifndef DATA_H
#define DATA_H

class Data
{
public:
    Data(int, int, int);
    ~Data();
    void imprimir() const;
private:
    int mes;
    int dia;
    int ano;
    int checarDia(int) const;
};

#endif // DATA_H
