#include <string>

using namespace std;

class Zumbi{
	public:
        Zumbi();
        Zumbi(const Zumbi &);
		Zumbi(const string &);
        void exibirStatus() const;        
		int atacarHumano(bool);
		void pegarItem(char);
	private:
		void setC();
		void setA();      
		string nome;
		int strength, hp;
		bool capacete, armadura;
};
