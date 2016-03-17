#ifndef ZUMBICHARGER_H
#define ZUMBICHARGER_H

#include "Zumbi.h"

class ZumbiCharger : public Zumbi{
    friend ostream& operator<<(ostream &, const ZumbiCharger &);
    public:
        ZumbiCharger();
        ZumbiCharger(const ZumbiCharger &);
		ZumbiCharger(const string &, int, int);       
		bool operator==(const ZumbiCharger &);
        void operator=(const ZumbiCharger &);
        virtual int atacarHumano(bool,int,int);
    protected:
        int stamina;
};

#endif // ZUMBICHARGER_H
