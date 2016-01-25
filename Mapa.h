#include "Zumbi.h"
class Mapa{
	public:
		Mapa(int);
		void iniciarMapa(Mapa*, int);
		void iniciarMapa2(Mapa*, int);
		void iniciarMapa3(Mapa*, int);
		void exibirMapa(Mapa*);
        void andarMapa(Mapa*, char, Zumbi*, int*);
        void verificarMapa(Mapa*, char, int, int, int*, int*, Zumbi*, int*);
        void procurarMapa(Mapa*, int*, int*);
    private:
    	int tam;
		char mapa[30][30];	
};

