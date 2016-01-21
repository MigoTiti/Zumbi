#include <string>

using namespace std;

class Zumbi{
	public:
		Zumbi(string);
		void setName(string);
		void setSpeed(int);
		void setHealth(float);
		string getName();
		int getSpeed();
		float getHealth();
		int atacarHumano();
		void pegarItem(char);
		void setC();
		void setA();
		int getA();
		int getC();
	private:
		string nome;
		int velocidade;
		float hp;
		int c=0, a=0;
};
