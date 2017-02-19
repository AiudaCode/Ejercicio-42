
import javax.swing.JOptionPane;

public class Main
{
    public static void main(String[] args)
    {
        Tarjeta obj = new Tarjeta();
        // declaramos e inicializamos la variable numerotarjeta en 0
        long numerotarjeta = 0;

        // preguntamos el numero de la tarjeta
        do
        {
            numerotarjeta = Long.parseLong(JOptionPane.showInputDialog("Ingrese su numero de tarjeta"));
        }
        while (numerotarjeta < 0);
        // encapsulamos la variable numerotarjeta
        obj.setNumeroTarjeta(numerotarjeta);
        // mostramos que tipo de tarjeta es
        JOptionPane.showMessageDialog(null, "Su numero de tarjeta es " + obj.validarTarjeta());
    }
}
