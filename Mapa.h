#include "Zumbi.h"
class Mapa{
	public:
		Mapa(int);
		void iniciarMapa();
		void iniciarMapa2();
		void iniciarMapa3();
		void exibirMapa();
        void andarMapa(char, Zumbi*,int*);
        void verificarMapa(char, int, int, int*, int*, Zumbi*, int*);
        void procurarMapa(int*, int*);
    private:
    	int tam;
		char mapa[30][30];	
};

