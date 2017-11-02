
#ifndef Carta_h
#define Carta_h
#include <vector>

#endif /* Carta_h */
class Carta
{
public:
    Carta();
    Carta(int valorr, string paloo);
    int getValor();
    string getPalo();
    void muestraValor();

private:
    int valor;
    string palo;
    
};

//constructors:
Carta::Carta()
{
    
}

Carta::Carta(int valorr, string paloo)
{
    valor = valorr;
    palo = paloo;
}


//getters and setters
int Carta::getValor()
{
    return valor;
}

string Carta::getPalo()
{
    return palo;
}

//functions
void Carta::muestraValor()
{
    if (valor == 1)
    {
        cout << "A" << " of " << palo <<endl;
    }
    else if (valor == 11)
    {
        cout << "J" << " of " << palo <<endl;
    }
    else if (valor == 12)
    {
        cout << "Q" << " of " << palo <<endl;
    }
    else if (valor == 13)
    {
        cout << "K" << " of " << palo <<endl;
    }
    else
    {
        cout << valor << " of " << palo <<endl;
    }
}










