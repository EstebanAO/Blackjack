
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
//    vector<pair<int, string>> Cartas;
    
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


//Carta::Carta()
//{
//    for (int iNum = 1; iNum <= 13; iNum++)
//    {
//        for (int iPalo = 1; iPalo <= 4; iPalo++)
//        {
//            string palo = "";
//            
//            if( iPalo == 1)
//            {
//                palo = "Spade";
//            }
//            if( iPalo == 2)
//            {
//                palo = "Heart";
//            }
//            if( iPalo == 3)
//            {
//                palo = "Diamond";
//            }
//            if( iPalo == 4)
//            {
//                palo = "Club";
//            }
//            
//            Cartas.push_back(make_pair(iNum, palo)):
//        }
//    }
//}

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
        cout << "As" << " de " << palo <<endl;
    }
    else if (valor == 11)
    {
        cout << "Joto" << " de " << palo <<endl;
    }
    else if (valor == 12)
    {
        cout << "Quina" << " de " << palo <<endl;
    }
    else if (valor == 13)
    {
        cout << "Rey" << " de " << palo <<endl;
    }
    else
    {
        cout << valor << " de " << palo <<endl;
    }
}










