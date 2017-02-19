#ifndef TARJETA_H
#define TARJETA_H
#include <iostream>

using namespace std;

class Tarjeta
{
    public:
        Tarjeta();
        virtual ~Tarjeta();
        void setNumeroTarjeta(long long val);
        long long getNumeroTarjeta();
        string validarTarjeta();
    protected:

    private:
        long long numerotarjeta;
};

#endif // TARJETA_H
