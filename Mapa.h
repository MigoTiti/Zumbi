#include "Zumbi.h"
class Mapa{
	public:
		Mapa();
		void iniciarMapa();
		void exibirMapa() const;
        void andarMapa(char, Zumbi* ,int*);
	private:
        void verificarMapa(char, int, int, int*, int*, Zumbi*, int*);
        void procurarMapa(int*, int*); 
		void iniciarMapa2();
		void iniciarMapa3();
		char mapa[30][30];	
};

