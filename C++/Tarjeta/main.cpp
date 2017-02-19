#include <iostream>
#include "Tarjeta.h"

using namespace std;

int main(void)
{
    Tarjeta *obj = new Tarjeta();
    // declaramos e inicializamos la variable numerotarjeta en 0
    long long numerotarjeta = 0;

    // preguntamos el numero de la tarjeta
    do
    {
        cout << "Ingrese su numero de tarjeta" << endl;
        cout << ">> ";
        // guardamos en la variable numerotarjeta el valor ingresado
        cin >> numerotarjeta;
    }
    while (numerotarjeta < 0);
    // encapsulamos la variable numerotarjeta
    obj->setNumeroTarjeta(numerotarjeta);
    // mostramos que tipo de tarjeta es
    cout << "Su numero de tarjeta es " << obj->validarTarjeta() << endl;
}
