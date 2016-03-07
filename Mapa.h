#ifndef MAPA_H
#define MAPA_H

#include <thread>
#include "Zumbi.h"
#include "Zumbi_hunter.h"
#include "Data.h"
#include "Chefe.h"

class Mapa{
	public:
		Mapa(Zumbi*);
		Mapa(Zumbi_hunter*);
		void iniciarMapa();
        static void exibirHumanos();
		void exibirMapa() const;
        void exibirDia() const;
        void andarMapa(char,int *);
        void avancarDia();
	private:
        void verificarMapa(char,int,int,int *,int *,int *);
        void procurarMapa(int *,int *); 
		void iniciarMapa2();
		void iniciarMapa3();
		char mapa[30][30];
        static const int humanos;
        static int humanosVivos;
        Zumbi *zumbiJogador;
        Zumbi_hunter *hunterJogador;
        Data dataAtual;
        Chefe chefeFinal;
};

#endif
