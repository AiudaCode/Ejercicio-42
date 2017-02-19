public class Tarjeta
{
    private long numerotarjeta;
    
    public void setNumeroTarjeta(long val)
    {
        numerotarjeta = val;
    }
    
    public long getNumeroTarjeta()
    {
        return numerotarjeta;
    }
    
    public String validarTarjeta()
    {
        // determinamos si tiene un número válido de dígitos
        // recuerda para poder entender esto debes leer o averiguar sobre el Algoritmo de Luhn ;)
        int contador = 0;
        long digitos = numerotarjeta;
        while (digitos > 0)
        {
            digitos = digitos/10;
            contador++;
        }
        if ((contador != 13) && (contador != 15) && (contador != 16))
        {
            return "INVALIDO.";
        }
        long [] numero =  new long[contador];

        for (int i = 0; i < contador; i++)
        {
            numero[i] = numerotarjeta % 10;
            numerotarjeta = numerotarjeta / 10;
        }

        long [] numero_original = new long[contador];
        for (int i = 1; i < contador; i++)
        {
            numero_original[i] = numero[i];
        }

        for (int i = 1; i < contador; i+=2)
        {
            numero[i] = numero[i] * 2;
        }

        long v = 0;
        long temp;

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
}