#include <string>

using namespace std;

class Zumbi {
	private:
		string nome;
		int velocidade;
		float HP;
	public:
		Zumbi(string);
		void setName(string);
		void setSpeed(int);
		void setHealth(float);
		string getName();
		int getSpeed();
		float getHealth();
};
