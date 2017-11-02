#ifndef Deck_h
#define Deck_h

#include "Carta.h"

#endif /* Deck_h */

class Deck
{
public:
    Deck();
    void shuffle();
    Carta getCarta();
    
private:
    Carta deckCartas[52];
    int cartaActual;
};

//constructors
Deck::Deck()
{
    cartaActual = 0;
    
    int valor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    string palo[] = {"Corazones", "Diamantes", "Espadas", "Tréboles"};
    
    for (int cards = 0; cards < 52; cards++)
    {
        deckCartas[cards] = Carta(valor[cards % 13], palo[cards / 13]);
    }
}

//functions
void Deck::shuffle()
{
    cartaActual = 0;

    for(int x = 0; x < 52; x++)
    {
        int y = (rand() + time(0)) % 52;
        Carta temp = deckCartas[x];
        deckCartas[x] = deckCartas[y];
        deckCartas[y] = temp;
    }
}

Carta Deck::getCarta()
{
    
    if(cartaActual >= 52)
    {
        shuffle();
    }
    
    if( cartaActual < 52)
    {
        return (deckCartas[cartaActual++]);
    }
    
    return (deckCartas[0]);
}
