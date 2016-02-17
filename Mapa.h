#include "Zumbi.h"
#include "Data.h"

class Mapa{
	public:
		Mapa();
		void iniciarMapa();
        static void exibirHumanos();
		void exibirMapa() const;
        void exibirDia() const;
        void andarMapa(char, Zumbi *const, int *);
        void avancarDia();
	private:
        void verificarMapa(char, int, int, int *, int *, Zumbi *const, int *);
        void procurarMapa(int *, int *); 
		void iniciarMapa2();
		void iniciarMapa3();
		char mapa[30][30];
        static const int humanos;
        static int humanosVivos;
        Data dataAtual;
};

