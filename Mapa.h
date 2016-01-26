#include "Zumbi.h"
class Mapa{
	public:
		Mapa(int);
		void iniciarMapa(Mapa*);
		void iniciarMapa2(Mapa*);
		void iniciarMapa3(Mapa*);
		void exibirMapa(Mapa*);
        void andarMapa(Mapa*, char, Zumbi*);
        void verificarMapa(Mapa*, char, int, int, int*, int*, Zumbi*, int*);
        void procurarMapa(Mapa*, int*, int*);
    private:
    	int tam;
		char mapa[30][30];	
};

