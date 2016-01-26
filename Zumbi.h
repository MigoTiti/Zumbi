#include <string>

using namespace std;

class Zumbi{
	public:
		Zumbi(string);
		void setName(string);
		void setSpeed(int);
		void setHealth(float);
        void setStrength(int);
		string getName();
		int getSpeed();
        int getStrength();
		float getHealth();
		int atacarHumano();
		void pegarItem(char,Zumbi *);
		void setC();
		void setA();
		int getA();
		int getC();
	private:
		string nome;
		int velocidade, strength;
		float hp;
		bool capacete=false, armadura=false;
};