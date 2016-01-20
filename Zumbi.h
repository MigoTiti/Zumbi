#include <string>

using namespace std;

class Zumbi {
	private:
		string nome;
		int velocidade;
		float hp;
	public:
		Zumbi(string);
		void setName(string);
		void setSpeed(int);
		void setHealth(float);
		string getName();
		int getSpeed();
		float getHealth();
		int atacarHumano();
		void pegarItem(string);
};
