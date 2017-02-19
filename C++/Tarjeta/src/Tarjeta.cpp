#include "Tarjeta.h"

Tarjeta::Tarjeta()
{
    numerotarjeta = 0;
}

Tarjeta::~Tarjeta()
{
    //dtor
}

void Tarjeta::setNumeroTarjeta(long long val)
{
    numerotarjeta = val;
}

long long Tarjeta::getNumeroTarjeta()
{
    return numerotarjeta;
}

string Tarjeta::validarTarjeta()
{
    // determinamos si tiene un número válido de dígitos
    // recuerda para poder entender esto debes leer o averiguar sobre el Algoritmo de Luhn ;)
    int contador = 0;
    long long digitos = numerotarjeta;
    while (digitos > 0)
    {
        digitos = digitos/10;
        contador++;
    }
    if ((contador != 13) && (contador != 15) && (contador != 16))
    {
        return "INVALIDO.";
    }
    int numero[contador];

    for (int i = 0; i < contador; i++)
    {
        numero[i] = numerotarjeta % 10;
        numerotarjeta = numerotarjeta / 10;
    }

    int numero_original[contador];
    for (int i = 1; i < contador; i++)
    {
        numero_original[i] = numero[i];
    }

    for (int i = 1; i < contador; i+=2)
    {
        numero[i] = numero[i] * 2;
    }

    int v = 0;
    int temp;

    if (contador == 13)
    {
        for (int i = 0; i < contador; i++)
        {
            temp = (numero[i] % 10) + (numero[i]/10 % 10);
            v = v + temp;
        }
        if (numero_original[12] == 4 && v % 10 == 0)
        {
            return "VISA.";
        }
        else
        {
            return "INVALIDO.";
        }
    }
    if (contador == 15)
    {
        for (int i = 0; i < contador; i++)
        {
            temp = (numero[i] % 10) + (numero[i]/10 % 10);
            v = v + temp;
        }
        if (numero_original[14] == 3 && v % 10 == 0 && (numero_original[13] == 4 || numero_original[13] == 7))
        {
            return "AMERICAN EXPRESS.";
        }
        else
        {
            return "INVALIDO.";
        }
    }
    if (contador == 16)
    {
        for (int i = 0; i < contador; i++)
        {
            temp = (numero[i] % 10) + (numero[i]/10 % 10);
            v = v + temp;
        }
        if (numero_original[15] == 4 && v % 10 == 0)
        {
            return "VISA.";
        }
        else
        {
            return "MASTERCARD.";
        }
    }
    return "INVALIDO.";
}
