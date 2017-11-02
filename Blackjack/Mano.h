#ifndef Mano_h
#define Mano_h
#include <vector>

#include "Deck.h"


#endif /* Mano_h */

class Mano
{
public:
    Mano();
    Mano(Deck &deck);
    int getscore();
    Carta getCarta(Deck &deck);
    int getMaxSumaGanadora();
    int getMinSumaGanadora();
    void printJ();
    void printD();

private:
    int score;
    vector<Carta>ManoIns;
};

//constructors
Mano::Mano()
{
    
}

Mano::Mano(Deck &deck)
{
    ManoIns.push_back(deck.getCarta());
    ManoIns.push_back(deck.getCarta());
    score = getMaxSumaGanadora();

}

//getters and setter
int Mano::getscore()
{
    return score;
}


//functions
Carta Mano::getCarta(Deck &deck)
{
    Carta tempCarta = deck.getCarta();

    ManoIns.push_back(tempCarta);
    
    score = getMaxSumaGanadora();
    
    return ManoIns.back();
}

int Mano::getMaxSumaGanadora()
{
    int score = 0;
    int CantAs = 0;
    for (int iC = 0; iC < ManoIns.size(); iC++)
    {
        if (ManoIns[iC].getValor() == 1)
        {
            CantAs+=1;
        }
        else
        {
            if (ManoIns[iC].getValor() >= 10)
            {
                score+= 10;
            }
            else
            {
                score+= ManoIns[iC].getValor();
            }
            
        }
    }
    
    if (score + CantAs <= 11 && CantAs >= 1)
    {
        score+= 10;
        score+= CantAs;

    }
    else
    {
        score+= CantAs;
    }
    
    return score;
}

int Mano::getMinSumaGanadora()
{
    int score = 0;
    
    for (int iC = 0; iC < ManoIns.size(); iC++)
    {
        if (ManoIns[iC].getValor() >= 10)
        {
            score+= 10;
        }
        else
        {
            score+= ManoIns[iC].getValor();
        }

    }
    return score;
}


void Mano::printJ()
{
    for (int iC = 0; iC < ManoIns.size(); iC++)
    {
        ManoIns[iC].muestraValor();
    }
}

void Mano::printD()
{
    ManoIns[0].muestraValor();
    cout<< "Carta volteada"<<endl;
}

