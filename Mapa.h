#include "Zumbi.h"
class Mapa{
	public:
		Mapa(int);
		void iniciarMapa(Mapa, int);
        void exibirMapa(Mapa);
        void andarMapa(Mapa, char, Zumbi);
        void verificarMapa(Mapa, char, int, int, int*, int*, Zumbi);
        void procurarMapa(Mapa, int*, int*);
        void setSize(int);
        void setMap(int, int);
    private:
    	int tam;
		char mapa[30][30];	
};
