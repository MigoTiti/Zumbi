#include <string>

using namespace std;

class Zumbi{
    public:
        Zumbi();
		Zumbi(const string &);
		void setName(string);
		void setSpeed(int);
		void setHealth(float);
        void setStrength(int);
		string getName();
		int getSpeed();
        int getStrength();
		float getHealth();
		void setC();
		void setA();
		int atacarHumano();
		void pegarItem(char);
        void exibirStatus();        
	private:
		string nome;
		int strength;
		float hp;
		bool capacete, armadura;
};