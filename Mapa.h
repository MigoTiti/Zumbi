#include "Zumbi.h"
class Mapa{
	public:
		Mapa();
		void iniciarMapa();
		void exibirMapa() const;
        void andarMapa(char, Zumbi *const, int *);
	private:
        void verificarMapa(char, int, int, int *, int *, Zumbi *const, int *);
        void procurarMapa(int *, int *); 
		void iniciarMapa2();
		void iniciarMapa3();
		char mapa[30][30];	
};

