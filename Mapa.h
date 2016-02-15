#include "Zumbi.h"
#include "Data.h"

class Mapa{
	public:
		Mapa();
		void iniciarMapa();
		void exibirMapa() const;
        void andarMapa(char, Zumbi *const, int *);
        void exibirDia() const;
	private:
        void verificarMapa(char, int, int, int *, int *, Zumbi *const, int *);
        void procurarMapa(int *, int *); 
		void iniciarMapa2();
		void iniciarMapa3();
		char mapa[30][30];
        static const int humanos;
        static const Data data;
};

