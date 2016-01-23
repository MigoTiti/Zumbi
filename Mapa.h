#include "Zumbi.h"
class Mapa{
	public:
		Mapa(int);
    protected:
    	int tam;
		char mapa[30][30];	
};

class Mapa1 : public Mapa{
	public:
		Mapa1(int);
		void iniciarMapa(Mapa1*, int);
		void exibirMapa(Mapa1*);
        void andarMapa(Mapa1*, char, Zumbi*, int*);
        void verificarMapa(Mapa1*, char, int, int, int*, int*, Zumbi*, int*);
        void procurarMapa(Mapa1*, int*, int*);
};

class Mapa2 : public Mapa{
	public:
		Mapa2(int);
		void iniciarMapa(Mapa2*, int);
		void exibirMapa(Mapa2*);
        void andarMapa(Mapa2*, char, Zumbi*);
        void verificarMapa(Mapa2*, char, int, int, int*, int*, Zumbi*);
        void procurarMapa(Mapa2*, int*, int*);
};